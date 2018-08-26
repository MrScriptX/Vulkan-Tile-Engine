#ifndef _ENGINE_H
#define _ENGINE_H

#include "Logger.h"
#include "VulkanInstance.h"

class Engine
{
public:
	Engine();
	~Engine();

private:
	void setupDevice();
	void setupSwapchain();

	std::unique_ptr<Logger> m_pLogger;
	std::shared_ptr<extensions> m_pExtensions;
	std::shared_ptr<settings> m_pSettings;
	std::shared_ptr<graphic> m_pGraphic;

	std::unique_ptr<VulkanInstance> m_pInstance;
};

#endif //!_ENGINE_H