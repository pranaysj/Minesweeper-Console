#include <iostream>
#include "header/Introduction.h"
#include "header/Borad.h"
#include "header/PlayerInput.h"


int main()
{
	Introduction intro;
	PlayerInput playerInput;

	playerInput.Start();

	PlayerChoice response = playerInput.GetInput();

	if (response == PlayerChoice::YES)
	{
		intro.GameStart();
	}
	else if(response == PlayerChoice::NO)
	{
		cout << "\nExiting the game.\n";
		return 0;
	}

	Board board(5);
}
