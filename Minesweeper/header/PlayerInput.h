#pragma once
#include <iostream>
using namespace std;

enum class PlayerChoice
{
	YES,
	NO
};

class PlayerInput
{
private:
	int x, y;
	PlayerChoice input;

public:
	PlayerInput();
	~PlayerInput();

	void Start();
	PlayerChoice GetInput();

	void SelectCell();
};