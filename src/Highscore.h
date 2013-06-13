#pragma once

#include "HighscoreElement.h"
#include <string>
#include <vector>
#include <iostream>

const std::string FILENAME = "Highscore.txt";

class Highscore
{
private:
	virtual std::string readScoreFile();

public:
	Highscore(void);
	~Highscore(void);

	virtual void writeScore(std::string pname, int scoreValue);
//	virtual std::vector<HighscoreElement> readScore();
};
