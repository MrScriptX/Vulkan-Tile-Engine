#ifndef _DEPENDENCY_H
#define _DEPENDENCY_H

#include "vulkan/vulkan.h"

struct extensions
{
	const std::vector<const char*> validationLayers = { "VK_LAYER_LUNARG_standard_validation", "VK_LAYER_LUNARG_monitor" };
	const std::vector<const char*> device_extension = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
};

struct settings
{
#ifdef NDEBUG
	const bool validation_layer_enable = false;
#else
	const bool validation_layer_enable = true;
#endif


};

struct graphic
{
	VkInstance vulkan_instance;
};

#endif //!_DEPENDENCY_H