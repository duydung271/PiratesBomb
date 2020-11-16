#include "Sources/Application.h"
#include <time.h>
int main()
{
	srand(time(NULL));
	Application::GetInstance()->Run();
}