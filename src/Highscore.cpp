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
	datei.open(FILENAME, std::ios::out | std::ios::app);
	datei << pname << "," << pscoreValue <<";";
	datei.close();

	std::cout << readScoreFile() << std::endl;
}

std::string Highscore::readScoreFile()
{
	std::fstream datei;
	datei.open(FILENAME, std::ios::in);
	std::string line;
	while (getline(datei,line,'\0'));
	datei.close();


	return line;
}
std::vector<HighscoreElement> Highscore::readScore()
{
	std::string line;
	line = readScoreFile();
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