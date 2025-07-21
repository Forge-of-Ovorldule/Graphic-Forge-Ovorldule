#pragma once

#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <vector>

class GraphicsEngine {
public:
    void run();

private:
    void initWindow();
    void initVulkan();
    void createInstance();
    void pickPhysicalDevice();
    void createLogicalDevice();
    void mainLoop();
    void cleanup();

    // Переменные
    GLFWwindow* window = nullptr;
    VkInstance instance = VK_NULL_HANDLE;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device = VK_NULL_HANDLE;
    VkQueue graphicsQueue = VK_NULL_HANDLE;

    // Настройки
    const uint32_t WIDTH = 1200;
    const uint32_t HEIGHT = 800;
    const std::vector<const char*> validationLayers = {};
};