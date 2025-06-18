#include "../header/Borad.h"
#include <iostream>
using namespace std;

Board::Board(int size)
{
	this->size = size;
	Draw();
}

Board::~Board(){}

void Board::Draw()
{
	VerticalLine();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << "|" << "1";
		}
		cout << "|\n";
		VerticalLine();
	}
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
