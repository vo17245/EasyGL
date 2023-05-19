#include "Log.h"
#include <string>
#include <sstream>

#ifdef CONFIG_DEBUG
    #define ASSERT(x,m) if(!(x))\
    {\
        std::stringstream ss;\
        ss<<"Assert Failed: "<<m<<" in "<<__FILE__<<":"<<__LINE__;\
        ERROR(ss.str());\
        exit(-1);\
    }
#else
    #define ASSERT(x,m)
#endif