#pragma once
#include "highscoremenu.h"
class HighscoreMenuEasy :
	public HighscoreMenu
{
protected:
	virtual std::string getName();
	virtual int getHSID();
public:
	HighscoreMenuEasy(ActionListener* listener) : HighscoreMenu(listener){}
};

