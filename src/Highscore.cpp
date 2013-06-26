#include "Highscore.h"
#include <fstream>



Highscore::Highscore(void)
{
}

Highscore::~Highscore(void)
{
}

void Highscore::writeScore(std::string pname, int pscoreValue)
{
	std::fstream datei;
	datei.open(gameName(GAMERULES::i().choosen_gamemode), std::ios::out | std::ios::app);
	datei << pname << "," << pscoreValue <<";";
	datei.close();
}

std::string Highscore::readScoreFile(int choose)
{
	std::fstream datei;
	datei.open(gameName(choose), std::ios::in);
	std::string line;
	while (getline(datei,line,'\0'));
	datei.close();


	return line;
}
std::vector<HighscoreElement> Highscore::readScore(int choose)
{
	std::string line;
	line = readScoreFile(choose);
	std::vector<std::string> elements;
	elements = explode(line, ';');
	std::vector<HighscoreElement> result;

	for(unsigned int z = 0; z < elements.size(); z++){
		std::string name;
		int score;
		std::vector<std::string> elements2;
		elements2 = explode(elements.at(z), ',');

		name = elements2.at(0);
		std::stringstream sstr(elements2.at(1));
		sstr >> score;

		HighscoreElement hse;
		hse.name = name;
		hse.point = score;

		result.push_back(hse);
	}

	sortHighscoreList(result);

	return result;
}

std::vector<std::string> Highscore::explode(const std::string& str, char delimiter) 
{
	std::vector<std::string> tokens;
	std::stringstream tokenStream(str);
	std::string tempStr;

	while(std::getline(tokenStream, tempStr, delimiter))
		tokens.push_back(tempStr);

	return tokens;
}

void Highscore::sortHighscoreList(std::vector<HighscoreElement>& elements)
{
	int n; 
	int i; 

	for (n = elements.size(); n>1; n--) 
	{ 
		for(i=0; i<n-1; i++) 
		{ 
			if (elements.at(i).point < elements.at(i+1).point) 
			{ 
				std::swap(elements[i], elements[i + 1]);
			} 
		} 
	} 
}

std::string Highscore::gameName(int choose)
{
	std::string FILENAME;

	switch(choose){
	case 0: 
		FILENAME = "Easy.txt";
		break;
	case 1:
		FILENAME = "Retro.txt";
		break;
	case 2:
		FILENAME = "Normal.txt";
		break;
	case 3:
		FILENAME = "Hardcore.txt";
		break;
	case 4:
		FILENAME = "Aspirin.txt";
		break;
	case 5:
		FILENAME = "Auto.txt";
		break;
	}

		return FILENAME;
}