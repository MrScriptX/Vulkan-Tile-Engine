#include "Engine.h"



Engine::Engine()
{
	//define dependencies
	m_pExtensions = std::make_shared<extensions>();
	m_pSettings = std::make_shared<settings>();
	m_pGraphic = std::make_shared<graphic>();

	//start logger
	m_pLogger = std::make_unique<Logger>();
	Logger::start();

	//engine start
	m_pInstance = std::make_unique<VulkanInstance>(m_pExtensions, m_pSettings, m_pGraphic);
}


Engine::~Engine()
{
}