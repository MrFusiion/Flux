#pragma once

#ifdef F_PLATFORM_WINDOWS

extern Flux::Application* Flux::CreateApplictation();

int main(int argc, char** argv)
{ 
	auto app = Flux::CreateApplictation();
	app->Run();
	delete app;
}

#endif