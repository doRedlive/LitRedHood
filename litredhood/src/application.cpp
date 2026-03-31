#include "application.hpp"

#include "spdlog/spdlog.h"
#include "glslang/Public/ShaderLang.h"

namespace LitRedHood {

    Application::Application() {
        initialize();
    }

    Application::~Application() {
        shutdown();
    }

    void Application::initialize() {
        spdlog::debug("{}", glslang::GetEsslVersionString());
        spdlog::debug("{}", glslang::GetGlslVersionString());

        glslang::InitializeProcess();

        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        window_handle_ = glfwCreateWindow(WindowWidth, WindowHeight, WindowName, nullptr, nullptr);
        if (window_handle_) {
            spdlog::error("Create window failed!");
        }

        if (!glfwVulkanSupported()) {
            spdlog::error("Vulkan not support glfw!");
            return;
        }
    }

    void Application::shutdown() {
        glslang::FinalizeProcess();
    }

    void Application::run() {
        while (!glfwWindowShouldClose(window_handle_)) {
            glfwPollEvents();
            const float cur_time = glfwGetTime();
            updateTick(cur_time - last_time_);
            renderTick();
        }
    }

}