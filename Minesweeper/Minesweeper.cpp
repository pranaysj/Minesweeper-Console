#include <iostream>
#include "header/Introduction.h"
#include "header/PlayerInputManager.h"
#include "header/GameplayManager.h"


int main()
{
	Introduction intro;
	GameplayManager gameplayManager;

	gameplayManager.StartGame();
	
	GameResult gameResult = gameplayManager.getGameResult();

	if (gameResult == GameResult::NONE)
	{
		intro.GameStartTxt();
	}
	else if (gameResult == GameResult::LOST)
	{
		return 0;
	}

	while (gameplayManager.hasGameEnded())
	{
		gameplayManager.handleGamePlay();

		switch (gameplayManager.getGameResult())
		{
		case GameResult::NONE:
			break;

		case GameResult::WON:
			//Print Win Text
			intro.GameWonTxt();

			gameplayManager.GetBoard();
			intro.GameEndTxt();
			return 0;

		case GameResult::LOST:
			//Print Lost Text
			intro.GameLoseTxt();
			gameplayManager.GetBoard();
			intro.GameEndTxt();
			return 0;
		}
	}

}
