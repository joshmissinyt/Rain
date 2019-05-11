#pragma once

#include "Application.h"
 
#ifdef RN_PLATFORM_WINDOWS

extern Rain::Application* Rain::CreateApplication();

int main(int argc, char** argv)
{
	Rain::Log::Init();
	RN_CORE_WARN("Initialized Log!");
	RN_INFO("Initialized Log!");

	auto app = Rain::CreateApplication();
	app->Run();
	delete app;
}

#endif