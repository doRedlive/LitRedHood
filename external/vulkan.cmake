find_package(Vulkan QUIET)
if (Vulkan_FOUND)
    target_link_libraries(litredhood_external INTERFACE Vulkan::Vulkan)
endif()
