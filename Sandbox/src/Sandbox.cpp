#include <Rain.h>

class ExampleLayer : public Rain::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		RN_INFO("ExampleLayer::Update");
	}

	void OnEvent(Rain::Event& event) override
	{
		RN_TRACE("{0}", event);
	}
};

class Sandbox : public Rain::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Rain::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Rain::Application* Rain::CreateApplication()
{
	return new Sandbox();
}