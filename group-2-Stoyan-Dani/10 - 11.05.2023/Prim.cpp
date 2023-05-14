#include <bits/stdc++.h>

using namespace std;

#define MAX 1010

int n, m, a, b, c, v;

vector<pair<int, int> > graph[MAX];

bool used[MAX];

int mind[MAX], par[MAX], wgt[MAX];

#define PA pair<int, int> 

void Prim(int from)
{
	int node;
	fill(mind, mind + n + 2, INT_MAX / 2);
	priority_queue<PA, vector<PA>, greater<PA> > pq;
	mind[from] = 0;
	pq.push({0, from});
	while(!pq.empty())
	{
		node = pq.top().second;
		pq.pop();
		if(used[node])continue;
		used[node] = true;
		for(int i = 0; i < graph[node].size(); i++)
		{
			if(used[graph[node][i].first] == false && mind[graph[node][i].first] > graph[node][i].second)
			{
				par[graph[node][i].first] = node;
				wgt[graph[node][i].first] = graph[node][i].second;
				mind[graph[node][i].first] = graph[node][i].second;
				pq.push({mind[graph[node][i].first], graph[node][i].first});
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	
	
	Prim(6);
	
	for(int i = 1; i <= n; i++)
	{
		if(i != 6)cout << par[i] << " " << i  <<  " " << wgt[i] << endl;
	}
	
	return 0;
}

/*

9 13
7 8 1
3 9 2
2 3 8
1 2 4
4 6 14
3 6 4
9 7 6
7 6 2
8 9 7
5 6 10
3 4 7
1 8 8
4 5 9
-----------------
8 1 8
1 2 4
6 3 4
3 4 7
4 5 9
6 7 2
7 8 1
3 9 2



*/
