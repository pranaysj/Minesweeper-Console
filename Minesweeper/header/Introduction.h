#pragma once
#include <iostream>
using namespace std;

class Introduction
{
private:
	void WelcomeTitle();
	void Rules();
	void HowToPlay();

public:
	Introduction();
	~Introduction();

	void GameStart();
};