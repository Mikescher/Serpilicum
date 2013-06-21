#pragma once
#include "menu.h"
#include "ListenerCollection.h"
#include "Label.h"
#include "Button.h"
#include "Edit.h"
#include "Game.h"

class OptionMenu :
	public Menu
{
private:
	Edit* nameEdt;
	virtual void createMenu(ActionListener * optiontListener, std::string playername);
public:
	OptionMenu(ActionListener * optiontListener, std::string playername);
	~OptionMenu(void);

	virtual std::string getEditText(void);
};

