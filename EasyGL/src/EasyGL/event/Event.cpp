#include "Event.h"
#include "EasyGLDebug.h"
#include <sstream>

std::string EventType2String(EventType eventType)
{
    switch (eventType)
    {
    case EventType::KEY_PRESS            :  
        return "KEY_PRESS";
        break;
    case EventType::KEY_RELEASE          :  
        return "KEY_RELEASE";
        break;
    case EventType::MOUSE_BUTTON_PRESS   :  
        return "MOUSE_BUTTON_PRESS";
        break;
    case EventType::MOUSE_BUTTON_RELEASE :  
        return "MOUSE_BUTTON_RELEASE";
        break;
    case EventType::KEY_REPEAT :  
        return "KEY_REPEAT";
        break;
    case EventType::WINDOW_FILE_DROP :
        return "WINDOW_FILE_DROP";
        break;
    case EventType::WINDOW_RESIZE :
        return "WINDOW_RESIZE";
        break;
    default:
        std::stringstream ss;
        ss<<"unknown EventType "<<static_cast<uint32_t>(eventType);
        ASSERT(false,ss.str().c_str());
        break;
    }
    return "";
}