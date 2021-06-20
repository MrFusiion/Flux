#pragma once

#include "Core.h"

namespace Flux {
	class FLUX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	
	//To be defined in Client
	Application* CreateApplictation()
}