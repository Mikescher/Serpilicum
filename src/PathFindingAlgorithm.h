#pragma once
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include "AbstractConsole.h"
#include "Dynamic2DArray.h"

using namespace std;

const int dir=4;

class PathFindingAlgorithm
{
private:
	int m_w;
	int m_h;

	int *dx;
	int *dy;
public:
	int **map;
private:
	int **closed_nodes_map;
	int **open_nodes_map;
	int **dir_map;
private:
	string lastResult;
	int lastResultTargetX;
	int lastResultTargetY;
private:
	string pathFind(const int & xStart, const int & yStart, const int & xFinish, const int & yFinish);
public:
	PathFindingAlgorithm(int map_w, int map_h);
	virtual ~PathFindingAlgorithm();

	bool hasToRecalc(const int & xFinish, const int & yFinish, bool ignoreTargetChange);
	int getWidth();
	int getHeight();

	int getNextDirection(const int & xStart, const int & yStart, const int & xFinish, const int & yFinish, bool ignoreTargetChange);
};

class node {
	private:
		int xPos;
		int yPos;
		int level;
		int priority; 
	public:
		node(int xp, int yp, int d, int p) {xPos=xp; yPos=yp; level=d; priority=p;}
		int getxPos() const {return xPos;}
		int getyPos() const {return yPos;}
		int getLevel() const {return level;}
		int getPriority() const {return priority;}

		void updatePriority(const int & xDest, const int & yDest){ priority=level+estimate(xDest, yDest)*10; }

		void nextLevel(const int & i) { level+=(dir==8?(i%2==0?10:14):10); }
		
		const int & estimate(const int & xDest, const int & yDest) const
		{
			static int xd, yd, d;
			xd=xDest-xPos;
			yd=yDest-yPos;         
			d=static_cast<int>(sqrt(xd*xd+yd*yd));
			return(d);
		}
};