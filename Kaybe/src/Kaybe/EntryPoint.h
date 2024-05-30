#pragma once

#ifdef KB_PLATFORM_WINDOWS

extern Kaybe::Application* Kaybe::CreateApplication();

int main(int argc, char** argv) {

	Kaybe::Log::Init();
	KB_CORE_WARN("Initialized Log");
	int a = 5;
	KB_CORE_INFO("Hello! Var=={0}", a);


	auto app = Kaybe::CreateApplication();
	app->Run();
	delete app;
}

#endif 

