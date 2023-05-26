#include "LayerStack.h"

void LayerStack::Push(const std::shared_ptr<Layer>& layer)
{
    layer->OnAttach();
    m_Layers.push_back(layer);
}

void LayerStack::Pop(const std::shared_ptr<Layer>& layer)
{
    for(auto it=m_Layers.begin();it!=m_Layers.end();it++)
    {
        if((*it).get()==layer.get())
        {
            (*it)->OnDetach();
            m_Layers.erase(it);
        }
    }
}

void LayerStack::Pop()
{
    m_Layers[m_Layers.size()-1]->OnDetach();
    m_Layers.pop_back();
}

LayerStack::~LayerStack()
{
    for(auto it:m_Layers)
    {
        it->OnDetach();
    }
}