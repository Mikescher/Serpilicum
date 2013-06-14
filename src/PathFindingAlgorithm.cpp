#include "PathFindingAlgorithm.h"

PathFindingAlgorithm::PathFindingAlgorithm(int map_w, int map_h) {
	m_w = map_w;
	m_h = map_h;

	dx = new int[dir];
	dy = new int[dir];

	map = allocateDynamicArray<int>(m_w, m_h);
	closed_nodes_map = allocateDynamicArray<int>(m_w, m_h);
	open_nodes_map = allocateDynamicArray<int>(m_w, m_h);
	dir_map = allocateDynamicArray<int>(m_w, m_h);

	dx[0] = 0;
	dy[0] = -1;

	dx[1] = 1;
	dy[1] = 0;

	dx[2] = 0;
	dy[2] = 1;

	dx[3] = -1;
	dy[3] = 0;

	lastResult = "";
}

PathFindingAlgorithm::~PathFindingAlgorithm() {
	freeDynamicArray(map);
	freeDynamicArray(closed_nodes_map);
	freeDynamicArray(open_nodes_map);
	freeDynamicArray(dir_map);
	
	delete[] dx;
	delete[] dy;
}

bool operator<(const node & a, const node & b)
{
  return a.getPriority() > b.getPriority();
}

string PathFindingAlgorithm::pathFind(const int & xStart, const int & yStart, const int & xFinish, const int & yFinish)
{
	static priority_queue<node> pq[2];
	static int pqi;
	static node* n0;
	static node* m0;
	static int i, j, x, y, xdx, ydy;
	static char c;
	pqi=0;

	for(y=0;y<m_h;y++)
	{
		for(x=0;x<m_w;x++)
		{
			closed_nodes_map[x][y]=0;
			open_nodes_map[x][y]=0;
		}
	}

	n0=new node(xStart, yStart, 0, 0);
	n0->updatePriority(xFinish, yFinish);
	pq[pqi].push(*n0);
	//open_nodes_map[x][y]=n0->getPriority();

	while(!pq[pqi].empty())
	{
		n0=new node( pq[pqi].top().getxPos(), pq[pqi].top().getyPos(), 
					 pq[pqi].top().getLevel(), pq[pqi].top().getPriority());

		x=n0->getxPos(); y=n0->getyPos();

		pq[pqi].pop(); 
		open_nodes_map[x][y]=0;

		closed_nodes_map[x][y]=1;

		if(x==xFinish && y==yFinish) 
		{
			string path="";
			while(!(x==xStart && y==yStart))
			{
				j=dir_map[x][y];
				c='0'+(j+dir/2)%dir;
				path=c+path;
				x+=dx[j];
				y+=dy[j];
			}

			delete n0;

			while(!pq[pqi].empty()) pq[pqi].pop();           
			return path;
		}

		for(i=0;i<dir;i++)
		{
			xdx=x+dx[i]; ydy=y+dy[i];

			if(!(xdx<0 || xdx>m_w-1 || ydy<0 || ydy>m_h-1 || map[xdx][ydy]==1 
				|| closed_nodes_map[xdx][ydy]==1))
			{
				m0=new node( xdx, ydy, n0->getLevel(), 
							 n0->getPriority());
				m0->nextLevel(i);
				m0->updatePriority(xFinish, yFinish);

				if(open_nodes_map[xdx][ydy]==0)
				{
					open_nodes_map[xdx][ydy]=m0->getPriority();
					pq[pqi].push(*m0);
					dir_map[xdx][ydy]=(i+dir/2)%dir;
				}
				else if(open_nodes_map[xdx][ydy]>m0->getPriority())
				{
					open_nodes_map[xdx][ydy]=m0->getPriority();
					dir_map[xdx][ydy]=(i+dir/2)%dir;

					while(!(pq[pqi].top().getxPos()==xdx && 
						   pq[pqi].top().getyPos()==ydy))
					{                
						pq[1-pqi].push(pq[pqi].top());
						pq[pqi].pop();       
					}
					pq[pqi].pop();
					
					if(pq[pqi].size()>pq[1-pqi].size()) pqi=1-pqi;
					while(!pq[pqi].empty())
					{                
						pq[1-pqi].push(pq[pqi].top());
						pq[pqi].pop();       
					}
					pqi=1-pqi;
					pq[pqi].push(*m0);
				}
				else delete m0;
			}
		}
		delete n0;
	}
	return "";
}

bool PathFindingAlgorithm::hasToRecalc(const int & xFinish, const int & yFinish, bool ignoreTargetChange) {
	return lastResult.empty() || ((lastResultTargetX != xFinish || lastResultTargetY != yFinish) && !ignoreTargetChange);
}

int PathFindingAlgorithm::getNextDirection(const int & xStart, const int & yStart, const int & xFinish, const int & yFinish, bool ignoreTargetChange) {
	//if (ignoreTargetChange && !lastResult.empty()) {
	//	if (lastResult.empty()) {
	//		std::cout << "ignoreTargetChanged->recalc" << std::endl;
	//	} else {
	//		std::cout << "ignoreTargetChanged" << std::endl;
	//	}
	//} else {
	//	std::cout << "not ignoreTargetChanged" << std::endl;
	//}

	if (hasToRecalc(xFinish, yFinish, ignoreTargetChange)) {
		// clock_t start = clock();

		lastResult = pathFind(xStart, yStart, xFinish, yFinish);

		// clock_t end = clock();
		// double time_elapsed = double(end - start);
		// cout << "Calculate A* Path (ms): " << time_elapsed;
		// if(lastResult == "") cout << " >> (empty)";
		// cout << endl;

		lastResultTargetX = xFinish;
		lastResultTargetY = yFinish;
	}

	if (lastResult.empty()) {
		return -1;
	} else {
		int result = lastResult.at(0) - '0';
		lastResult = lastResult.substr(1);
		return result;
	}
}

int PathFindingAlgorithm::getWidth() {
	return m_w;
}

int PathFindingAlgorithm::getHeight() {
	return m_h;
}