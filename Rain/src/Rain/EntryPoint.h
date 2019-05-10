#pragma once

#include "Application.h"
 
#ifdef RN_PLATFORM_WINDOWS

extern Rain::Application* Rain::CreateApplication();

int main(int argc, char** argv) {
	auto app = Rain::CreateApplication();
	app->Run();
	delete app;
}

#endif