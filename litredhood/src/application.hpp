#pragma once

#include "GLFW/glfw3.h"

namespace LitRedHood {

    class Application {
        const int WindowWidth{1600};
        const int WindowHeight{1200};
        const char* WindowName{"LitRedHood"};
        
        GLFWwindow* window_handle_{nullptr};
        float last_time_{0.0f};
    public:
        Application();
        ~Application();

        void run();
    private:
        void initialize();
        void shutdown();

        void updateTick(float dt);
        void renderTick();
    };

}