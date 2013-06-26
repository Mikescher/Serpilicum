#pragma once
#include "highscoremenu.h"
class HighscoreMenuRetro :
	public HighscoreMenu
{
protected:
	virtual std::string getName();
	virtual int getHSID();
public:
	HighscoreMenuRetro(ActionListener* listener) : HighscoreMenu(listener){}
};

