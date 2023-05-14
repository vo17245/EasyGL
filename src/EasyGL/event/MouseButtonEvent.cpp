#include "MouseButtonEvent.h"
#include <sstream>

const std::string MouseButtonEvent::ToString()const
{
    std::stringstream ss;
    ss<<EventType2String(m_Type)<<" "<<MouseButton2String(m_Button);
    return ss.str();
}