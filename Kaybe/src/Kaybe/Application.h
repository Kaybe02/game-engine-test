#pragma once

#include "Core.h"

namespace Kaybe {

	class KAYBE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	//To be defined in Client
	Application* CreateApplication();

}


