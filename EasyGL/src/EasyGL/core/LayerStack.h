#pragma once
#include <vector>
#include "Layer.h"
#include <memory>

class LayerStack
{
private:
    std::vector<std::shared_ptr<Layer>> m_Layers;
public:
    LayerStack(){}
    ~LayerStack();
    void Push(const std::shared_ptr<Layer>& layer);
    void Pop(const std::shared_ptr<Layer>& layer);

    std::vector<std::shared_ptr<Layer>>::iterator begin() { return m_Layers.begin(); }
	std::vector<std::shared_ptr<Layer>>::iterator end() { return m_Layers.end(); }
	std::vector<std::shared_ptr<Layer>>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
	std::vector<std::shared_ptr<Layer>>::reverse_iterator rend() { return m_Layers.rend(); }
	std::vector<std::shared_ptr<Layer>>::const_iterator begin() const { return m_Layers.begin(); }
	std::vector<std::shared_ptr<Layer>>::const_iterator end()	const { return m_Layers.end(); }
	std::vector<std::shared_ptr<Layer>>::const_reverse_iterator rbegin() const { return m_Layers.rbegin(); }
	std::vector<std::shared_ptr<Layer>>::const_reverse_iterator rend() const { return m_Layers.rend(); }
};