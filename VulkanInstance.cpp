#include "VulkanInstance.h"



VulkanInstance::VulkanInstance(std::shared_ptr<extensions> extensionsObj, std::shared_ptr<settings> settingsObj, std::shared_ptr<graphic> graphicObj)
{
	m_pExtensions = extensionsObj;
	m_pSettings = settingsObj;
	m_pGraphic = graphicObj;

	VkApplicationInfo app_info = getApplicationInfo();

	if (m_pSettings->validation_layer_enable && !checkLayersSupport())
	{
		throw std::runtime_error("Requested layers are not available!");
	}

	VkInstanceCreateInfo create_info = {};
	create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	create_info.pNext = nullptr;
	create_info.flags = 0;
	create_info.pApplicationInfo = &app_info;

	std::vector<const char*> extensions = getRequiredExtensions();
	create_info.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
	create_info.ppEnabledExtensionNames = extensions.data();

	if (m_pSettings->validation_layer_enable)
	{
		create_info.enabledLayerCount = static_cast<uint32_t>(m_pExtensions->validationLayers.size());
		create_info.ppEnabledLayerNames = m_pExtensions->validationLayers.data();
	}
	else
	{
		create_info.enabledLayerCount = 0;
	}


	if (vkCreateInstance(&create_info, nullptr, &m_pGraphic->vulkan_instance) != VK_SUCCESS)
	{
		std::string error = "Failed to create vulkan instance!";
		std::cerr << error << std::endl;

		Logger::registerError(error);
	}
}


VulkanInstance::~VulkanInstance()
{
}

VkApplicationInfo VulkanInstance::getApplicationInfo()
{
	VkApplicationInfo app_info = {};
	app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	app_info.pNext = nullptr;
	app_info.pApplicationName = "Tile Engine";
	app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.pEngineName = "VkTile";
	app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.apiVersion = VK_API_VERSION_1_0;

	return app_info;
}

bool VulkanInstance::checkLayersSupport()
{
	uint32_t layer_count = 0;
	vkEnumerateInstanceLayerProperties(&layer_count, nullptr);

	std::vector<VkLayerProperties> available_layers(layer_count);
	vkEnumerateInstanceLayerProperties(&layer_count, available_layers.data());

	for (const char* layer_name : m_pExtensions->validationLayers)
	{
		bool layer_found = false;

		for (const VkLayerProperties& layer_properties : available_layers)
		{
			if (strcmp(layer_name, layer_properties.layerName) == 0)
			{
				layer_found = true;
				break;
			}
		}

		if (!layer_found)
		{
			return false;
		}
	}

	return true;
}

std::vector<const char*> VulkanInstance::getRequiredExtensions()
{
	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

	if (m_pSettings->validation_layer_enable)
	{
		extensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
	}

	return extensions;
}
