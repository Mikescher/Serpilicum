#pragma once
#include "highscoremenu.h"
class HighscoreMenuAuto :
	public HighscoreMenu
{
protected:
	virtual std::string getName();
	virtual int getHSID();
public:
	HighscoreMenuAuto(ActionListener* listener) : HighscoreMenu(listener){}
};

