#include <bits/stdc++.h>

using namespace std;

#define MAX 1100

int n, k, f, m, idx = 1, cnt[MAX];

vector<int> gr[MAX];

vector<string> ans;

bool used[MAX];

string a, b, names[MAX];

map<string, int> mp;

void topo()
{
	int node;
	queue<int> q;
	for(int i = 1; i <= n; i++)if(cnt[i] == 0)q.push(i);
	
	while(!q.empty())
	{
		node = q.front();
		q.pop();
		if(used[node] == true)continue;
		used[node] = true;
		ans.push_back(names[node]);
		for(int i = 0; i < gr[node].size(); i++)
		{
			cnt[gr[node][i]]--;
			if(used[gr[node][i]] == false && cnt[gr[node][i]] <= 0)q.push(gr[node][i]);
		}
	}
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++)cout << ans[i] << " ";
	cout << endl;
	return;
}

bool elem(int el, const vector<int>& v)
{
	for(int i = 0; i < v.size(); i++)if(v[i] == el)return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k >> f >> m;
	
	fill(cnt, cnt + n + 2, k);
	
	for(int i = 0; i < f; i++)
	{
		cin >> a;
		if(mp.count(a) == 0)
		{
			mp[a] = idx;
			names[idx++] = a;
		}
		cnt[mp[a]] = 0;
	}
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		
		if(mp.count(a) == 0)
		{
			mp[a] = idx;
			names[idx++] = a;
		}
		if(mp.count(b) == 0)
		{
			mp[b] = idx;
			names[idx++] = b;
		}
		
		if(elem(mp[b], gr[mp[a]]) == false)gr[mp[a]].push_back(mp[b]);
		if(elem(mp[a], gr[mp[b]]) == false)gr[mp[b]].push_back(mp[a]);

	}

	topo();
	
	return 0;
}
