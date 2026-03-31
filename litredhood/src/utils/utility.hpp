#pragma once

#include "spdlog/spdlog.h"
#include "glm/glm.hpp"
#include "glm/gtc/constants.hpp"
#include "vulkan.h"

#include "common.hpp"

namespace LitRedHood {

#define LRH_ASSERT_VK(error) assert(error == VK_SUCCESS)
#define LRH_CHECK_VK_ERROR(error, message) \
    do { \
        if (VK_SUCCESS != (error)) { \
            assert(false && (message)); \
        } \
    } while(false)

    inline bool checkIsVkSuccess(const VkResult& result) {
        return result == VK_SUCCESS;
    }

    inline std::vector<char> readFile(const std::string& file_name) {
        std::ifstream file(file_name, std::ios::binary | std::ios::ate);
        if (!file.is_open()) {
            spdlog::error("Failed to open a file!");
            return;
        }

        size_t file_size = file.tellg();
        std::vector<char> file_buffer(file_size + 1, '\0');
        file.seekg(0);
        file.read(file_buffer.data(), file_size);
        file.close();
        return file_buffer;
    }

    inline float deg2rad(const float& deg) {
        return deg * (glm::pi<float>() / 180.0f);
    }

    using vec2 = glm::highp_vec2;
    using vec3 = glm::highp_vec3;
    using vec4 = glm::highp_vec4;
    using mat4 = glm::highp_mat4;
    using quat = glm::highp_quat;

} // LitRedHood