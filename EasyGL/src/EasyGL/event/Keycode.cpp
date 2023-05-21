#include "KeyCode.h"
#include "EasyGLDebug.h"
#include <sstream>


std::string Keycode2String(const KeyCode& code)
{
    switch (code)
    {
    case KeyCode::KEY_A:
        return "KEY_A";
        break;
    case KeyCode::KEY_B:
        return "KEY_B";
        break;
    case KeyCode::KEY_C:
        return "KEY_C";
        break;
    case KeyCode::KEY_D:
        return "KEY_D";
        break;
    case KeyCode::KEY_E:
        return "KEY_E";
        break;
    case KeyCode::KEY_F:
        return "KEY_F";
        break;
    case KeyCode::KEY_G:
        return "KEY_G";
        break;
    case KeyCode::KEY_H:
        return "KEY_H";
        break;
    case KeyCode::KEY_I:
        return "KEY_I";
        break;
    case KeyCode::KEY_J:
        return "KEY_J";
        break;
    case KeyCode::KEY_K:
        return "KEY_K";
        break;
    case KeyCode::KEY_L:
        return "KEY_L";
        break;
    case KeyCode::KEY_M:
        return "KEY_M";
        break;
    case KeyCode::KEY_N:
        return "KEY_N";
        break;
    case KeyCode::KEY_O:
        return "KEY_O";
        break;
    case KeyCode::KEY_P:
        return "KEY_P";
        break;
    case KeyCode::KEY_Q:
        return "KEY_Q";
        break;
    case KeyCode::KEY_R:
        return "KEY_R";
        break;
    case KeyCode::KEY_S:
        return "KEY_S";
        break;
    case KeyCode::KEY_T:
        return "KEY_T";
        break;
    case KeyCode::KEY_U:
        return "KEY_U";
        break;
    case KeyCode::KEY_V:
        return "KEY_V";
        break;
    case KeyCode::KEY_W:
        return "KEY_W";
        break;
    case KeyCode::KEY_X:
        return "KEY_X";
        break;
    case KeyCode::KEY_Y:
        return "KEY_Y";
        break;
    case KeyCode::KEY_Z:
        return "KEY_Z";
        break;
    
    default:
        std::stringstream ss;
        ss<<"unknown keycode "<<static_cast<uint32_t>(code);
        ASSERT(false,ss.str().c_str());
        break;
    }
    return "";
}
