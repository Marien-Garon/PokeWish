#include "GameManager.h"



int main()
{
	Utils::activerSupportUnicode();

	GameManager gm;
	gm.Init();
	gm.Loop();
	gm.Shutdown();


	return 0;
}