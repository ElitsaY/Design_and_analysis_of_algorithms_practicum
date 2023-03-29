#include <bits/stdc++.h>

using namespace std;

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void solve()
{
	int x1, x2, y1, y2, v1, v2;
	cin >> x1 >> y1 >> x2 >> y2 >> v1 >> v2;
	double l = min(x1, x2), r = max(x1, x2), m1, m2, st1, st2;
	
	for(int i = 0; i < 100; i++)
	{
		m1 = l + (r - l) * (1.0 / 3);
		m2 = l + (r - l) * (2.0 / 3);
		st1 = dist(x1, y1, m1, 0) / v1 + dist(m1, 0, x2, y2) / v2;
		st2 = dist(x1, y1, m2, 0) / v1 + dist(m2, 0, x2, y2) / v2;
		if(st1 > st2)l = m1;
		else r = m2;
	}
	cout << setprecision(5) << fixed << st1 << endl;
	return ;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)solve();
	
	return 0;
}
