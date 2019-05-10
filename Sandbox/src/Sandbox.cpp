#include <Rain.h>

class Sandbox : public Rain::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Rain::Application* Rain::CreateApplication()
{
	return new Sandbox();
}