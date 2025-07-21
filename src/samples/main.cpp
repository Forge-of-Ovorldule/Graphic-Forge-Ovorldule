#include "../include/GraphicsEngine.hpp"
#include <iostream>
#include <cstdlib>

int main() {
    GraphicsEngine app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}