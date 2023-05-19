#pragma once
#include "GLFW/glfw3.h"
#include <string>
enum class MouseButton
{
    MOUSE_BUTTON_RIGHT=GLFW_MOUSE_BUTTON_RIGHT,
    MOUSE_BUTTON_LEFT=GLFW_MOUSE_BUTTON_LEFT,
    MOUSE_BUTTON_MIDDLE=GLFW_MOUSE_BUTTON_MIDDLE
};

std::string MouseButton2String(const MouseButton& mouseButton);

