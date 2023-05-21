#include "MouseButton.h"
#include "EasyGLDebug.h"
#include <sstream>

std::string MouseButton2String(const MouseButton& mouseButton)
{
    switch(mouseButton)
    {
    case MouseButton::MOUSE_BUTTON_RIGHT  :
        return "MOUSE_BUTTON_RIGHT";
        break;  
    case MouseButton::MOUSE_BUTTON_LEFT   :
        return "MOUSE_BUTTON_LEFT";
        break;  
    case MouseButton::MOUSE_BUTTON_MIDDLE :
        return "MOUSE_BUTTON_MIDDLE";
        break;
    default:
        std::stringstream ss;
        ss<<"unknown MouseButton "<<static_cast<uint32_t>(mouseButton);
        ASSERT(false,ss.str().c_str());
        break;
    }
    return "";
}