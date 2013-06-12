#pragma once
class ActionListener {
public:
	virtual ~ActionListener();

	virtual void actionPerformed(int id) = 0;
};

