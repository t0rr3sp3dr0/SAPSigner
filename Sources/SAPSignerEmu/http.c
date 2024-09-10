//
//  http.c
//  SAPSigner
//
//  Created by Pedro Tôrres on 2024-05-28.
//

#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>

#include "http.h"

struct http_response {
    char **data;
    unsigned long *size;
};

static size_t http_write(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct http_response *res = userp;

    unsigned long new_size = *res->size + realsize;
    char *new_data = realloc(*res->data, new_size + 1);
    if (!new_data) {
        return 0;
    }

    (void) memcpy(new_data + *res->size, contents, realsize);
    new_data[new_size] = '\0';

    *res->data = new_data;
    *res->size = new_size;

    return realsize;
}

static CURL *curl;

int http_init(void) {
    if (curl) {
        return 1;
    }

    CURLcode code = curl_global_init(CURL_GLOBAL_ALL);
    if (code) {
        return code;
    }

    curl = curl_easy_init();
    if (!curl) {
        return -1;
    }

    return 0;
}

int http_cleanup(void) {
    if (!curl) {
        return 1;
    }

    curl_easy_cleanup(curl);
    curl = NULL;

    curl_global_cleanup();

    return 0;
}

int http_get(const char *url, char **res_data, unsigned long *res_size) {
    struct http_response res = {
        .data = res_data,
        .size = res_size,
    };

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &res);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, http_write);

    CURLcode code = curl_easy_perform(curl);
    return code;
}

int http_post(const char *url, const char *req_data, unsigned long req_size, char **res_data, unsigned long *res_size) {
    *res_data = NULL;
    *res_size = 0;

    struct http_response res = {
        .data = res_data,
        .size = res_size,
    };

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, req_data);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, req_size);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &res);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, http_write);

    CURLcode code = curl_easy_perform(curl);
    return code;
}
