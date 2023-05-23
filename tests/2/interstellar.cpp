#include <bits/stdc++.h>

using namespace std;

#define MAX 1024

int n, m, a, b, c, deg[MAX], par[MAX];

vector<pair<int, int> > gr[MAX];

bool okay(int x, bool flag)
{
	fill(deg, deg + n + 1, 0);
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < gr[i].size(); j++)
		{
			if(gr[i][j].second <= x)deg[gr[i][j].first]++;
		}
	}
	
	int cnt = 0, node;
	priority_queue<int, vector<int>, greater<int> > q;
	
	for(int i = 1; i <= n; i++)
	{
		if(deg[i] == 0)q.push(i);
	}
	
	while(!q.empty())
	{
		cnt++;
		node = q.top();
		q.pop();
		
		if(flag)cout << node << " ";
		
		for(int i = 0; i < gr[node].size(); i++)
		{
			if(gr[node][i].second <= x)
			{
				deg[gr[node][i].first]--;
				if(deg[gr[node][i].first] == 0)q.push(gr[node][i].first);
			}
		}
	}
	
	if(flag)cout << endl;
	return (cnt == n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		gr[b].push_back({a, c});
	}
	
	int l = 1, r = 110000, mid, opt = -1;
	
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(okay(mid, false))
		{
			opt = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	
	if(opt == 110000)cout << "-1" << endl;
	else cout << opt << endl;
	
	okay(opt, true);
	
	return 0;
}

/*

7 13 
2 1 6 
6 4 64 
1 6 42 
4 3 17
4 7 12
3 7 20
7 6 19
6 7 11
7 5 35
3 5 4
3 2 13
7 2 55
2 5 1 


4 3
2 1 6
4 2 6
3 1 6

*/
