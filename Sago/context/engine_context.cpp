#include "engine_context.h"

#include "window/window_sdl.h"

namespace Context {

EngineContext::EngineContext() {
	using namespace Platform;

	window_ = std::make_unique<AppWindow>();
	if (!window_) {
		LogInfoDetaill("Context Window Create Error");
	}
    
    Init();
}

void EngineContext::Init() {
    using namespace Driver::Vulkan;
    vkcontext_ = std::make_unique<VkContextRendering>();
    vkcontext_->Init();

}

EngineContext::~EngineContext() {
	window_.reset();
}

void EngineContext::Quit() {
	window_->Quit();
}

} //namespace Context