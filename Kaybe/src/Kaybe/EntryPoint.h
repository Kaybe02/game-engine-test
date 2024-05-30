#pragma once

#ifdef KB_PLATFORM_WINDOWS

extern Kaybe::Application* Kaybe::CreateApplication();

int main(int argc, char** argv) {
	auto app = Kaybe::CreateApplication();
	app->Run();
	delete app;
}

#endif 

