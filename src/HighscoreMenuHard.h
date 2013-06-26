#pragma once
#include "highscoremenu.h"
class HighscoreMenuHard :
	public HighscoreMenu
{
protected:
	virtual std::string getName();
	virtual int getHSID();
public:
	HighscoreMenuHard(ActionListener* listener) : HighscoreMenu(listener){}
};

