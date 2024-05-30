#include <Kaybe.h>

class Sandbox : public Kaybe::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};


Kaybe::Application* Kaybe::CreateApplication()
{
	return new Sandbox();
}