#pragma once
class ActionListener {
public:
	virtual void actionPerformed(int id) = 0;
};

class KeyEventListener {
public:
	virtual void keyEventPerformed(int key) = 0;
};