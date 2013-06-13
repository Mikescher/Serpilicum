#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

const std::string FILENAME = "Highscore.txt";

struct HighscoreElement {
	std::string name;
	int point;
};

class Highscore
{
private:
	virtual std::string readScoreFile();
	virtual std::vector<std::string> explode(const std::string& str, char delimiter);
	virtual void sortHighscoreList(std::vector<HighscoreElement>& elements);

public:
	Highscore(void);
	~Highscore(void);

	virtual void writeScore(std::string pname, int scoreValue);
	virtual std::vector<HighscoreElement> readScore();	
};
