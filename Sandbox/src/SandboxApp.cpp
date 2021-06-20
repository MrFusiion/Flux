#include <Flux.h>

class Sandbox : public Flux::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Flux::Application* CreateAppliction()
{
	return new Sandbox();
}