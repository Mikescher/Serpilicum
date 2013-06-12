#pragma once
class Highscore
{
public:
	Highscore(void);
	~Highscore(void);

	virtual void writeScore(int scoreValue);
	virtual int readScore(void);
};
