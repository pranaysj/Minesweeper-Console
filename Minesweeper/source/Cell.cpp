#include "../header/Cell.h"
#include <iostream>
using namespace std;

Cell::Cell()
{
	initialize();
}

Cell::~Cell() {}

void Cell::initialize()
{
	cellState = CellState::HIDDEN;
	cellType = CellType::ZERO;
}

bool Cell::canOpenCell()
{
	return cellState == CellState::HIDDEN;
}

void Cell::open()
{
	setCellState(CellState::OPEN);
}


void Cell::setCellState(CellState state)
{
	cellState = state;
}

CellState Cell::getCellState()
{
	return cellState;
}

void Cell::setCellType(CellType type)
{
	cellType = type;
}

CellType Cell::getCellType()
{
	return cellType;
}
