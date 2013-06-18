#pragma once
class ActionListener {
public:
	virtual void actionPerformed(int id, int param) = 0;
};

class KeyEventListener {
public:
	virtual void keyEventPerformed(int key) = 0;
};