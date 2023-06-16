#pragma once
#include "Log.h"
#include <string>
#include <sstream>

#ifdef CONFIG_DEBUG
    #define ASSERT(x,m) if(!(x))\
    {\
        std::stringstream assert_ss;\
        assert_ss<<"Assert Failed: "<<m<<" in "<<__FILE__<<":"<<__LINE__;\
        EZ_CORE_ERROR(assert_ss.str());\
        exit(-1);\
    }
#else
    #define ASSERT(x,m)
#endif