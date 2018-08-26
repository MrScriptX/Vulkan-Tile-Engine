#ifndef _VULKAN_INSTANCE_H
#define _VULKAN_INSTANCE_H

#include <vector>
#include <memory>
#include <string>

#include "Logger.h"
#include "Dependency.h"
#include "vulkan/vulkan.h"
#include "GLFW/glfw3.h"

class VulkanInstance
{
public:
	VulkanInstance(std::shared_ptr<extensions> extensionsObj, std::shared_ptr<settings> settingsObj, std::shared_ptr<graphic> graphicObj);
	~VulkanInstance();

private:
	VkApplicationInfo getApplicationInfo();
	bool checkLayersSupport();
	std::vector<const char*> getRequiredExtensions();

	std::shared_ptr<extensions>  m_pExtensions;
	std::shared_ptr<settings>  m_pSettings;
	std::shared_ptr<graphic> m_pGraphic;
};

#endif //!_VULKAN_INSTANCE_H