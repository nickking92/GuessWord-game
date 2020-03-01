#include "GameManager.h"

int main()
{
		GameManager gm;
		if (gm.isGameOver) {
			gm.StartGame();
			gm.ManageInput(gm.input);
		}
	return 0;
}

