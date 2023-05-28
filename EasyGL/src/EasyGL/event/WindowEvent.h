#include "Event.h"

class WindowFileDropEvent:public Event
{
private:
    size_t m_Count;
    const char** m_Paths;
public:
    WindowFileDropEvent(size_t count,const char** paths)
        :Event(EventType::WINDOW_FILE_DROP),m_Count(count),m_Paths(paths)
    {}
    virtual ~WindowFileDropEvent(){}
    inline const size_t GetCount()const{return m_Count;}
    inline const char** GetPaths()const{return m_Paths;}
    virtual const std::string ToString()const override;
};

class WindowResizeEvent:public Event
{
private:
    size_t m_Width;
    size_t m_Height;
public:
    WindowResizeEvent(size_t width,size_t height)
        :Event(EventType::WINDOW_RESIZE),m_Width(width),m_Height(height)
    {}
    virtual ~WindowResizeEvent(){}
    inline const size_t GetWidth()const{return m_Width;}
    inline const size_t GetHeight()const{return m_Height;}
    virtual const std::string ToString()const override;
};