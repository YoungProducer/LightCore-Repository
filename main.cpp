#include "src\lc.h"

int main(void)
{
	lc::Application application = lc::Application(1280, 720, "App");

	application.Init();
	application.MainLoop();
	application.~Application();

	return 0;
}