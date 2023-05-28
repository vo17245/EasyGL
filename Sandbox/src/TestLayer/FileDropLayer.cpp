#include "FileDropLayer.h"
#include <sstream>

void FileDropLayer::OnEvent(const Event& event)
{
    if(event.IsOnCategory(EventType::WINDOW_FILE_DROP))
    {
        WindowFileDropEvent& windowFileDropEvent=*(WindowFileDropEvent*)&event;
        for(int i=0;i<windowFileDropEvent.GetCount();i++)
        {
            m_Paths.push_back(windowFileDropEvent.GetPaths()[i]);
        }
    }
    else if(event.IsOnCategory(EventType::WINDOW_RESIZE))
    {
        WindowResizeEvent windowResizeEvent=*(WindowResizeEvent*)&event;
        RendererCommand::SetViewport(0,0,windowResizeEvent.GetWidth(),windowResizeEvent.GetHeight());
    }
}

void FileDropLayer::OnImguiRender()
{
    ImGui::Begin("FileDropLayer");
    for(auto&& it:m_Paths)
    {
        ImGui::Text("%s",it.c_str());  
    }
    ImGui::End();
    
}