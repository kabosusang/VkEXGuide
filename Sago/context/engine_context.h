#ifndef SG_CONXTEX_H
#define SG_CONXTEX_H
#include <memory>

//platform
#include "window_interface.h"
//engine
#include "common/single_internal.h"
#include "drivers/vulkan/vk_manager.h"

namespace Context {

class EngineContext : public Common::Singleton<EngineContext> {
	friend class Common::Singleton<EngineContext>;
public:
	void Init();
	void Tick();
	void Quit();
	
	EngineContext();
	~EngineContext();

private:
	std::unique_ptr<Platform::AppWindow> window_;
	std::unique_ptr<Driver::Vulkan::VkContextRendering> vkcontext_;
};



} //namespace context

#endif