//
//  os_unfair_recursive_lock_s.h
//  
//
//  Created by Pedro Tôrres on 2024-09-12.
//

#ifndef os_unfair_recursive_lock_s_h
#define os_unfair_recursive_lock_s_h

#include "os_unfair_lock_s.h"

struct os_unfair_recursive_lock_s {
    struct os_unfair_lock_s ourl_lock;
    unsigned int ourl_count;
};

#endif /* os_unfair_recursive_lock_s_h */
