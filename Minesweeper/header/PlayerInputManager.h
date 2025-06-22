#pragma once
#include <iostream>
using namespace std;

enum class PlayerChoice
{
	YES,
	NO
};

class PlayerInputManager
{
private:
	int xpos, ypos;
	PlayerChoice input;

public:
	PlayerInputManager();
	~PlayerInputManager();

	void Start();
	PlayerChoice GetInput();

	void SelectCell();

	int getXPos();
	int getYPos();
};