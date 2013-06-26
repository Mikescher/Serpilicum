#pragma once
#include "highscoremenu.h"
class HighscoreMenuNormal :
	public HighscoreMenu
{
protected:
	virtual std::string getName();
	virtual int getHSID();
public:
	HighscoreMenuNormal(ActionListener* listener) : HighscoreMenu(listener){}
};

