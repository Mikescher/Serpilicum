#pragma once
#include "highscoremenu.h"
class HighscoreMenuAspirin :
	public HighscoreMenu
{
protected:
	virtual std::string getName();
	virtual int getHSID();
public:
	HighscoreMenuAspirin(ActionListener* listener) : HighscoreMenu(listener){}
};

