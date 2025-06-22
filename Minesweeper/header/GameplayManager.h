#pragma once
#include "../header/Borad.h"
#include "../header/PlayerInputManager.h"

class Board;

enum class GameResult
{
	NONE,
	WON,
	LOST
};

class GameplayManager
{
private:
	Board* board;
	PlayerInputManager* playerInputManager;

	int inputX, inputY;
	GameResult gameresult;

public:
	GameplayManager();
	~GameplayManager();

	void StartGame();
	bool hasGameEnded();
	void handleGamePlay();

	void setGameResult(GameResult game_result);
	GameResult getGameResult();

	void GetBoard();
};