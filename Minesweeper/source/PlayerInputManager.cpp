#include "../header/PlayerInputManager.h"

PlayerInputManager::PlayerInputManager(){}

PlayerInputManager::~PlayerInputManager(){}

void PlayerInputManager::Start()
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

PlayerChoice PlayerInputManager::GetInput()
{
	return input;
}

void PlayerInputManager::SelectCell()
{
	cout << "\nEnter X co-ordinate : ";
	cin >> xpos;
	cout << "Enter Y co-ordinate : ";
	cin >> ypos;
	cout << "\n";
}

int PlayerInputManager::getXPos()
{
	return xpos;
}

int PlayerInputManager::getYPos()
{
	return ypos;
}
