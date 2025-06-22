#pragma once
#include <iostream>
using namespace std;

class Introduction
{
private:
	void WelcomeTitleTxt();
	void RulesTxt();
	void HowToPlayTxt();

public:
	Introduction();
	~Introduction();

	void GameStartTxt();
	void GameWonTxt();
	void GameLoseTxt();
	void GameEndTxt();
};