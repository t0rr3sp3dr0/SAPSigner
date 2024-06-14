//
//  http.h
//  SAPSigner
//
//  Created by Pedro Tôrres on 2024-05-28.
//

#ifndef http_h
#define http_h

int http_post(const char *url, const char *req_data, unsigned long req_size, char **res_data, unsigned long *res_size);

#endif /* http_h */
