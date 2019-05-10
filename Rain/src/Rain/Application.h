#pragma once

#include "Core.h"

namespace Rain {

	class RN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in a Client!
	Application* CreateApplication();
}