#include <iostream>
#include <cstring>

#define N 4

using namespace std;


void DFS_visited(int mat[][N], bool visitied[N], int here)
{
	visitied[here] = true;
	cout << here << endl;
	for(int i=0;i<N;i++) {
		//cout << "x,y" << here << " " << i << endl;
		if(!visitied[i] && mat[here][i]==1) {
			DFS_visited(mat,visitied,i);
		}
	}
}

void DFS(int mat[][N], bool visitied[N])
{
	for(int i=0;i<N;i++) {
		if(!visitied[i]) {
			DFS_visited(mat,visitied,i);
		}
	}
}

int main()
{
	int mat2d[N][N] = {
		{1,1,0,0},
		{0,1,0,0},
		{1,0,0,1},
		{0,0,0,0}
	};

	bool visited[N];
	memset(visited,false,sizeof(visited));

	DFS(mat2d,visited);

	
	return 0;
}
