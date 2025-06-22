#include <iostream>
#include "../header/Borad.h"
using namespace std;

Board::Board(GameplayManager* gameManager)
{
	initialize(gameManager);
}

Board::~Board(){}

void Board::initialize(GameplayManager* gameManager)
{
	randomEngine.seed(randomDevice());
	this->gameManager = gameManager;
}

void Board::CreateBoard()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cell[i][j] = new Cell();
		}
	}
	boardState = BoardState::FIRST_CELL;
}

void Board::Draw()
{
	VerticalLine();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (boardState == BoardState::FIRST_CELL)
			{
				cout << "|" << " ";
			}
			else if (boardState == BoardState::PLAYING)
			{
				//Use CellState
				cellState = cell[i][j]->getCellState();
				int cellValue = static_cast<int>(cell[i][j]->getCellType());

				//
				switch (cellState)
				{
				case CellState::HIDDEN:
					cout << "| ";
					break;
				case CellState::OPEN:
					if (cellValue == 9)
						cout << "|*";
					else
						cout << "|" << cellValue;
					break;
				}
				//if (cellType == 9)  // Mine
				//	cout << "|*";
				//else
				//	cout << "|" << cellType;
			}
		}
		cout << "|\n";
		VerticalLine();
	}

}

void Board::populateMines(int xpos, int ypos)
{
	std::uniform_int_distribution<int> x_dist(0, size - 1);
	std::uniform_int_distribution<int> y_dist(0, size - 1);
	int mines_placed = 0;

	while (mines_placed < minesCount)
	{
		int x = x_dist(randomEngine);
		int y = y_dist(randomEngine);

		//check the valid mine posiiotn
		if (isvalidMinePosition(xpos, ypos, x, y))
			continue;

		//cout <<"xpos :" << xpos << "," << "ypos : " << ypos << "\n";
		//cout <<"x :" << x << "," << "y : " << y << "\n";

		cell[x][y]->setCellType(CellType::MINE);
		++mines_placed;
	}
}

void Board::populateCell()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (cell[i][j]->getCellType() != CellType::MINE)
			{
				int mineCount = countMinesAround(i, j);
				cell[i][j]->setCellType(static_cast<CellType>(mineCount));
			}
		}
	}
}

int Board::countMinesAround(int x, int y)
{
	int minesAround = 0;

	for (int a = -1; a <= 1 ; a++)
	{
		for (int b = -1; b <= 1; b++)
		{
			if ((a == 0 && b == 0) || !isvalidCellPosition(x+a, y+b))
			{
				continue;
			}
			int c = x + a;
			int d = y + b;

			//cout << "c : " << c << "," << "d : " << d << " - " << static_cast<int>(cell[c][d]->getCellType()) << "\n";

			if (cell[c][d]->getCellType() == CellType::MINE)
			{
				minesAround++;
			}
		}

	}

	return minesAround;
}

bool Board::isvalidCellPosition(int x, int y)
{
	return (x >= 0 && y >= 0 && x < size && y < size);
}

void Board::openCell(int x, int y)
{
	//cell[x][y]->setCellState(CellState::OPEN);

	if (!cell[x][y]->canOpenCell()) {
		return;
	}

	processCellType(x, y);

}

void Board::openAllCell()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cell[i][j]->setCellState(CellState::OPEN);
		}
	}
}

void Board::processCellType(int x, int y)
{
	CellType cellType = cell[x][y]->getCellType();

	switch (cellType)
	{
	case CellType::ZERO:
		//Open adjacent cells
		proceeZeroType(x, y);
		break;
	case CellType::MINE:
		//Lost the game
		proceeMinesType(x, y);
		break;
	default:
		//Open single cell
		cell[x][y]->open();
		break;
	}

}

void Board::proceeZeroType(int x, int y)
{
	CellState cellState = cell[x][y]->getCellState();

	switch (cellState)
	{
	case CellState::OPEN:
		return;

	default:
		cell[x][y]->open();
		break;
	}

	for (int a = -1; a <= 1; ++a)
	{
		for (int b = -1; b <= 1; ++b)
		{
			// Skip current cell and invalid positions
			if ((a == 0 && b == 0) || !isvalidCellPosition(x+a, y+b))
			{
				continue;
			}

			//Open neighbor cell
			openCell(x+a, y+b);  // Open neighbor
		}
	}
}

void Board::proceeMinesType(int x, int y)
{
	//OPEN ALL THE CELLS WHEN LOST
	//openAllCell();

	//Draw();

	//set the lost condiiton
	gameManager->setGameResult(GameResult::LOST);
}


bool Board::isvalidMinePosition(int xpos, int ypos, int x, int y)
{

	return (x == xpos && y == ypos) || cell[x][y]->getCellType() == CellType::MINE;
}

bool Board::areAllCellsOpen()
{
	int totalSize = size * 2;
	int openCells = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (cell[i][j]->getCellState() == CellState::OPEN &&
				cell[i][j]->getCellType() != CellType::MINE)
			{
				openCells++;
			}
		}
	}
	return openCells == totalSize - minesCount;
}

void Board::setBoardState(BoardState state)
{
	boardState = state;
}

BoardState Board::getBoardState()
{
	return boardState;
}

void Board::VerticalLine()
{
	//Vertical line based on number of grid size
	for (int i = 0; i < size; i++)
	{
		cout << "--";
	}
	cout << "\n";
}

bool Board::isState(BoardState state) const
{
	return boardState == state;
}

