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
}

std::string Highscore::readScoreFile()
{
	std::fstream datei;
	datei.open(FILENAME, std::ios::in);
	std::string zeile;
	while (getline(datei,zeile,'\0'));

	std::cout << zeile << std::endl;
	return zeile;
}
/* std::vector<HighscoreElement> Highscore::readScore()
{
	return 0;
}
*/