#include <Flux.h>

class ExampleLayer : public Flux::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		FLUX_INFO("ExampleLayer::Update");
	}

	void OnEvent(Flux::Event& event) override
	{
		FLUX_TRACE("{0}", event);
	}

};

class Sandbox : public Flux::Application
{
public:
	Sandbox();
	~Sandbox();
};

Sandbox::Sandbox()
{
	PushLayer(new ExampleLayer());
}

Sandbox::~Sandbox()
{
}

Flux::Application* Flux::CreateApplication()
{
	return new Sandbox();
}