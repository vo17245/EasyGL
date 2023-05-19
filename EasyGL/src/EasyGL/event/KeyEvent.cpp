#include <sstream>
#include "KeyEvent.h"
#include "EasyGLDebug.h"

const std::string KeyEvent::ToString()const
{
    std::stringstream ss;
    ss<<EventType2String(m_Type)<<" "<<Keycode2String(m_KeyCode);
    return ss.str();
}
