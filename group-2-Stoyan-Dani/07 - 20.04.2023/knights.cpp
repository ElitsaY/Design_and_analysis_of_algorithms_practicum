#include <bits/stdc++.h>

using namespace std;

#define MAX 2048

int n, m, k, a, b, stx, sty, dist[MAX * MAX], ans, br;

pair<int, int> knights[MAX];

bool hole[MAX][MAX], used[MAX * MAX];

int coords_to_int(int x, int y)
{
	return x * n + y;
}

void get_neighbours(int node, vector<int>& neighbours)
{
	int i = node / n, j = node % n;
	if(!hole[i][j])
	{
		if(i + 1 < n && j + 2 < n)neighbours.push_back(coords_to_int(i + 1, j + 2));
		if(i - 1 >= 0 && j + 2 < n)neighbours.push_back(coords_to_int(i - 1, j + 2));
		if(i + 1 < n && j - 2 >= 0)neighbours.push_back(coords_to_int(i + 1, j - 2));
		if(i - 1 >= 0 && j - 2 >= 0)neighbours.push_back(coords_to_int(i - 1, j - 2));
		if(i + 2 < n && j + 1 < n)neighbours.push_back(coords_to_int(i + 2, j + 1));
		if(i - 2 >= 0 && j + 1 < n)neighbours.push_back(coords_to_int(i - 2, j + 1));
		if(i + 2 < n && j - 1 >= 0)neighbours.push_back(coords_to_int(i + 2, j - 1));
		if(i - 2 >= 0 && j - 1 >= 0)neighbours.push_back(coords_to_int(i - 2, j - 1));
	}

}

void bfs(int node)
{
	queue<int> q;
	q.push(node);
	
	while(!q.empty())
	{
		node = q.front();
		q.pop();
		if(used[node] == true)continue;
		used[node] = true;
		vector<int> neighbours;
		get_neighbours(node, neighbours);
		for(int i = 0; i < neighbours.size(); i++)
		{
			if(!used[neighbours[i]])
			{
				q.push(neighbours[i]);
				dist[neighbours[i]] = 1 + dist[node];
			}
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> k;
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		hole[a][b] = true;
	}
	
	for(int i = 0; i < k; i++)
	{
		cin >> knights[i].first >> knights[i].second;
	}
	
	cin >> stx >> sty;
	
	bfs(coords_to_int(stx, sty));
	
	for(int i = 0; i < k; i++)
	{
		ans = max(ans, dist[coords_to_int(knights[i].first, knights[i].second)]);
		if(dist[coords_to_int(knights[i].first, knights[i].second)] != 0)br++;
	}
	
	cout << br << " " << ans << endl;
	
	return 0;
}
