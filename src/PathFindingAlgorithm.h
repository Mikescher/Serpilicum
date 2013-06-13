#pragma once
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include "AbstractConsole.h"

using namespace std;

const int dir=4;
const int n = BUFFER_W;
const int m = BUFFER_H;

class PathFindingAlgorithm
{
private:
	int dx[dir];
	int dy[dir];
public:
	int map[n][m];
private:
	int closed_nodes_map[n][m];
	int open_nodes_map[n][m];
	int dir_map[n][m];
private:
	string lastResult;
	int lastResultTargetX;
	int lastResultTargetY;
private:
	string pathFind(const int & xStart, const int & yStart, const int & xFinish, const int & yFinish);
public:
	PathFindingAlgorithm();

	int getNextDirection(const int & xStart, const int & yStart, const int & xFinish, const int & yFinish);
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