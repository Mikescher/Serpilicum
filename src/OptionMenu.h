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
	virtual void createMenu(ActionListener * optiontListener);
public:
	OptionMenu(ActionListener * optiontListener);
	~OptionMenu(void);

	virtual std::string getEditText(void);
};

