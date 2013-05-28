#pragma once
class SnakeElement
{
private:
	SnakeElement *next;
	int x,y;
public:
	SnakeElement(int px, int py);
	~SnakeElement(void);

	virtual bool hasNextElement();
	virtual SnakeElement* getNextElement();
	virtual void setNextElement(SnakeElement* pnext);	
	virtual void setX(int x);
	virtual void setY(int y);
	virtual int getX();
	virtual int getY();
	virtual int moveX(int x);
	virtual int moveY(int y);
	virtual void set(int x, int y);
	virtual void move(int x, int y);
	virtual void moveRecursively(int tox, int toy);
	virtual void extendRecursively(int tox, int toy);
};


