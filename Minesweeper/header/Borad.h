#pragma once
#include <random>
#include "../header/Cell.h"
#include "../header/GameplayManager.h"

class GameplayManager;

enum class BoardState
{
	FIRST_CELL,
	PLAYING,
	COMPLETE
};

class Board
{
private:
	static const int size = 9;
	int minesCount = 10;
	void VerticalLine();

	void initialize(GameplayManager* gameManager);
	std::default_random_engine randomEngine;
	std::random_device randomDevice;

	Cell* cell[size][size];
	GameplayManager* gameManager;

	BoardState boardState;
	CellState cellState;

	bool isvalidMinePosition(int xpos, int ypos, int x, int y);

	void deleteBoard();

public:
	Board(GameplayManager *gameManager);
	~Board();

	void CreateBoard();
	void Draw();

	void populateMines(int x, int y);
	void populateCell();
	int countMinesAround(int x, int y);
	bool isvalidCellPosition(int x, int y);

	
	void processCellType(int x, int y);
	void proceeZeroType(int x, int y);
	void proceeMinesType(int x, int y);

	void openCell(int x, int y);
	void openAllCell();
	bool areAllCellsOpen();

	void setBoardState(BoardState state);
	BoardState getBoardState();

	bool isState(BoardState state) const;
};