#include <bits/stdc++.h>

using namespace std;

#define MAX 200100

int n, m, a, t[MAX], prv[MAX], totaltime[MAX], node;

vector<int> gr[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> t[i];
		cin >> m;
		prv[i] = m;
		for(int j = 0; j < m; j++)
		{
			cin >> a;
			gr[a].push_back(i);
		}
	}
	
	queue<int> q;
	for(int i = 0; i < n; i++)
	{
		if(prv[i] == 0)
		{
			q.push(i);
			totaltime[i] = t[i];
		}
	}
	
	while(!q.empty())
	{
		node = q.front();
		q.pop();
		for(int i = 0; i < gr[node].size(); i++)
		{
			prv[gr[node][i]]--;
			totaltime[gr[node][i]] = max(totaltime[gr[node][i]], totaltime[node] + t[gr[node][i]]);
			if(prv[gr[node][i]] == 0)
			{
				q.push(gr[node][i]);
			}
		}
	}
	for(int i = 0; i < n; i++)cout << totaltime[i] << '\n';
	return 0;
}
