#include <bits/stdc++.h>

using namespace std;

#define MAX 510000

long long n, m, q, dst[MAX];

pair<long long, long long> c[MAX];

struct point
{
	long long x, y, dst = LLONG_MAX / 123;
} p[MAX];

long long ans[MAX];

pair<long long, long long> e[MAX]; 

long long dist(long long x, long long y)
{
	return abs(x - y);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)cin >> c[i].first >> c[i].second;
	for(int i = 0; i < m; i++)cin >> p[i].x >> p[i].y;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> e[i].first;
		e[i].first /= 2;
		e[i].second = i;
	}
	sort(e, e + q);
	
	sort(c, c + n);
	sort(p, p + m, [](const point& l, const point& r)
	{
		return l.x < r.x;
	});
	
	int idx = 0;
	for(int i = 0; i < m; i++)
	{
		while(idx + 1 < n && dist(p[i].x, c[idx].first) >= dist(p[i].x, c[idx + 1].first))
		{
			idx++;
		}
		p[i].dst = min(p[i].dst, dist(p[i].x, c[idx].first));
	}
	
	sort(p, p + m, [](const point& l, const point& r)
	{
		return l.y < r.y;
	});
	
	sort(c, c + n, [](const pair<long long, long long>& l, const pair<long long, long long>& r)
	{
		return l.second < r.second;
	});
	
	idx = 0;
	for(int i = 0; i < m; i++)
	{
		while(idx + 1 < n && dist(p[i].y, c[idx].second) >= dist(p[i].y, c[idx + 1].second))
		{
			idx++;
		}
		p[i].dst = min(p[i].dst, dist(p[i].y, c[idx].second));
	}
	
	
	sort(p, p + m, [](const point& l, const point& r)
	{
		return l.dst < r.dst;
	});
	
	idx = 0;
	for(int i = 0; i < q; i++)
	{
		while(idx < m && p[idx].dst <= e[i].first)idx++;
		
		ans[e[i].second] = idx;
	}
	for(int i = 0; i < q; i++)cout << ans[i] << " ";
	cout << endl; 
	return 0;
}

/*


*/
