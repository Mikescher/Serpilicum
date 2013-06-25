#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Gamerules.h"

//const std::string FILENAME = "Highscore.txt";

struct HighscoreElement {
	std::string name;
	int point;
};

class Highscore
{
private:

	virtual std::string readScoreFile(int choose);
	virtual std::vector<std::string> explode(const std::string& str, char delimiter);
	virtual void sortHighscoreList(std::vector<HighscoreElement>& elements);
	virtual std::string gameName(int choose);

public:
	Highscore(void);
	~Highscore(void);

	virtual void writeScore(std::string pname, int scoreValue);
	virtual std::vector<HighscoreElement> readScore(int choose);	
};
