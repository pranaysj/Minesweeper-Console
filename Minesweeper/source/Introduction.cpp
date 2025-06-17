#include "../header/Introduction.h"

Introduction::Introduction()
{
	WelcomeTitle();
	Rules();
	HowToPlay();
}

Introduction::~Introduction()
{
}

void Introduction::WelcomeTitle()
{
	cout << "\t---------------------------------------\n";
	cout << "\t|                                     |\n";
	cout << "\t|     WELCOME TO MINESWEEPER GAME     |\n";
	cout << "\t|                                     |\n";
	cout << "\t---------------------------------------\n";
}

void Introduction::Rules()
{
	cout << "\nRules :"
		"\n\t1.The board is divided into cells, with mines randomly distributed."
		"\n\t2.To win, you need to open all the cells."
		"\n\t3.The number on a cell shows the number of mines adjacent to it."
		"\n\t4.Using this information, you can determine cells that are safe, and cells that contain mines."
		"\n\t5.Interact, evolve and enjoy!\n";
}

void Introduction::HowToPlay()
{
	cout << "\nHow to Play :"
		"\n\t1.User will Input x and y (co-ordinates where they want to click)."
		"\n\t2.In each step check for win or lose.\n\n\n";
}

