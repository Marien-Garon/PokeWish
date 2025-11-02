#include "GameManager.h"



int main()
{
	GameManager gm;
	gm.Init();
	gm.Loop();
	gm.Shutdown();


	return 0;
}