#include "../header/GameplayManager.h"


GameplayManager::GameplayManager()
{
	initialize();
}

GameplayManager::~GameplayManager()
{
	delete playerInputManager;
	delete board;
}

void GameplayManager::initialize()
{
	playerInputManager = new PlayerInputManager();
	board = new Board(this);
	gameresult = GameResult::NONE;
}

void GameplayManager::StartGame()
{
	playerInputManager->Start();

	PlayerChoice response = playerInputManager->GetInput();

	if (response == PlayerChoice::YES)
	{
		gameresult = GameResult::NONE;
		board->CreateBoard();
	}
	else if (response == PlayerChoice::NO)
	{
		cout << "\nExiting the game.\n";
		gameresult = GameResult::LOST;
	}

}

bool GameplayManager::hasGameEnded()
{
	return gameresult != GameResult::LOST;
}

void GameplayManager::handleGamePlay()
{
	//Draw the board
	board->Draw();

	//Get the player inpur
	playerInputManager->SelectCell();
	inputX = playerInputManager->getXPos() - 1;
	inputY = playerInputManager->getYPos() - 1;

	//place the mines and place the numbers according to the mines
	if (board->isState(BoardState::FIRST_CELL))
	{
		board->populateMines(inputX, inputY);
		board->populateCell();
		board->setBoardState(BoardState::PLAYING);
	}	
	
	// Open Cell based on the input and their condition
	if (board->isState(BoardState::PLAYING))
	{
		board->openCell(inputX, inputY);
	}

	//WIN condiiton check
	if (board->areAllCellsOpen())
	{
		setGameResult(GameResult::WON);
	}
}

void GameplayManager::setGameResult(GameResult game_result)
{
	gameresult = game_result;
}

GameResult GameplayManager::getGameResult()
{
	return gameresult;
}

void GameplayManager::GetBoard()
{
	board->openAllCell();
	board->Draw();
}
