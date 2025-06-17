#pragma once

class Board
{
private:
	int size;
	void VerticalLine();

public:
	Board(int size);
	~Board();

	void Draw();
};