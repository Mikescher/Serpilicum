#pragma once
class PowerUp
{
private:
	PowerUp * next;
	int x;
	int y;
public:
	PowerUp(int px, int py);
	~PowerUp(void);

	virtual bool hasNextElement();
	virtual PowerUp * getNextElement();
	virtual void setNextElement(PowerUp * pnext);

	//########

	virtual int getX();
	virtual int getY();

	virtual char getSymbol() = 0;
};

