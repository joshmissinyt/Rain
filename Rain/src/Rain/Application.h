#pragma once

#include "Rain/Core.h"

#include "Rain/Window.h"
#include "Rain/LayerStack.h"
#include "Rain/Events/Event.h"
#include "Rain/Events/ApplicationEvent.h"


namespace Rain {

	class RAIN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	// To be defined in a Client!
	Application* CreateApplication();
}