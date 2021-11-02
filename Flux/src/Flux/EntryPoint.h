#pragma once

#ifdef FLUX_PLATFORM_WINDOWS

extern Flux::Application* Flux::CreateApplication();

int main(int argc, char** argv)
{
	Flux::Log::Init();
	FLUX_CORE_WARN("Initialized Log!");
	int a = 5;
	FLUX_INFO("Hello! Var={0}", a);

	auto app = Flux::CreateApplication();
	app->Run();
	delete app;
}

#endif