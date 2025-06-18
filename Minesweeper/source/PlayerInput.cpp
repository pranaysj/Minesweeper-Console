#include "../header/PlayerInput.h"

PlayerInput::PlayerInput(){}

PlayerInput::~PlayerInput(){}

void PlayerInput::Start()
{
	while (true)
	{
		char data;
		cout << "Enter Y/y to continue or N/n to close the game.\n\n";
		cin >> data;

		switch (data)
		{
		case 'Y':
		case 'y':
			input = PlayerChoice::YES;
			return;

		case 'N':
		case 'n':
			input = PlayerChoice::NO;
			return;

		default:
			cout << "\nINVALID INPUT !\n\n";
			break;
		}
	}
}

PlayerChoice PlayerInput::GetInput()
{
	return input;
}
