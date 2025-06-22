#pragma once

enum class CellState
{
    HIDDEN,
    OPEN
};

enum class CellType
{
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    MINE,
};

class Cell
{
private:
    CellState cellState;
    CellType cellType;


public:
	Cell();
	~Cell();

    void initialize();

    bool canOpenCell();
    void open();
   
    void setCellState(CellState state);
    CellState getCellState();

    void setCellType(CellType type);
    CellType getCellType();
};