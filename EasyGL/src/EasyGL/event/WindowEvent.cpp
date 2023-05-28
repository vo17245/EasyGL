#include "WindowEvent.h"
#include <sstream>

const std::string WindowFileDropEvent::ToString()const
{
    std::stringstream ss;
    ss<<EventType2String(m_Type);
    for(int i=0;i<m_Count;i++)
    {   
        ss<<" "<<m_Paths[i];
    }
    return ss.str();
}

const std::string WindowResizeEvent::ToString()const 
{
    std::stringstream ss;
    ss<<EventType2String(m_Type)<<" "<<"Width: "<<m_Width<<" height: "<<m_Height<<std::endl;
    return ss.str();
}