#include "../include/OvorlduleGraphics/Window.h"
#include <iostream>

using namespace Ovorldule;

int main() {
    try {
        Window window; // Правильное создание объекта
        
        while (!window.shouldClose()) {
            window.swapBuffers();
            window.pollEvents();
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}