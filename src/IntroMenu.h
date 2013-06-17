#pragma once
#include "menu.h"
#include "ListenerCollection.h"
#include "Label.h"
#include "Button.h"
#include "Edit.h"

class IntroMenu :
	public Menu
{
private:
	Edit* nameEdt;
	virtual void createMenu(ActionListener* mainMenuListener);
public:
	IntroMenu(ActionListener* mainMenuListener);
	~IntroMenu(void);

	virtual std::string getEditText(void);
};

