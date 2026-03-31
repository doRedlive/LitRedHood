#pragma once

#include "GLFW/glfw3.h"
#include "vulkan/vulkan.hpp"

#include <memory>
#include <vector>
#include <optional>

namespace LitRedHood {

	struct RenderContextCreateInfo {
		const char** extension;
		int extension_count;
		GLFWwindow* window_handle;
	};

	class RenderContext {
		struct QueueFamilyIndices {
			std::optional<uint32_t> graphics_family;
			std::optional<uint32_t> present_family;
			std::optional<uint32_t> compute_family;

			bool isComplete() { return graphics_family.has_value() && present_family.has_value() && compute_family.has_value();; }
    	};

		struct SwapchainSupportDetails {
			VkSurfaceCapabilitiesKHR        capabilities;
			std::vector<VkSurfaceFormatKHR> formats;
			std::vector<VkPresentModeKHR>   present_modes;
		};

		VkInstance instance_;
		VkSurfaceKHR surface_;
		VkPhysicalDevice physical_device_;
		VkDevice device_;
		VkQueue present_queue_;
		VkQueue graphics_queue_;
		VkQueue compute_queue_;
		VkSwapchainKHR swapchain_;
		std::vector<VkImage> swapchain_images_;
		std::vector<VkImageView> swapchain_imageviews_;
		VkFormat swapchain_image_format_;
		VkExtent2D swapchain_extent_;
		VkViewport viewport_;
		VkRect2D scissor_;
		
		VkDebugUtilsMessengerEXT debug_messenger_;

		QueueFamilyIndices queue_family_indices_;

		const std::vector<const char*> validation_layers_{"VK_LAYER_KHRONOS_validation"};
		const std::vector<const char*> device_extensions_ = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
	public:
		static std::unique_ptr<RenderContext> create(const RenderContextCreateInfo& info);
		static void destroy(std::unique_ptr<RenderContext>& context);

	private:
		void initialize(const RenderContextCreateInfo& info);
		void shutdown();

		bool checkValidationLayerSupport();
		void createInstance(const char** extension, int extension_count);
		void pickPhysicalDevice();
		void createLogicalDevice();
		void createSwapchain(GLFWwindow* window_handle);
		void createSwapchainImageViews();

		void initializeDebugMessenger();
		bool isDeviceSuitable(VkPhysicalDevice gpu);
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice gpu);
		bool checkDeviceExtensionSupport(VkPhysicalDevice gpu);
		SwapchainSupportDetails querySwapchainSupport(VkPhysicalDevice gpu);
	};

}