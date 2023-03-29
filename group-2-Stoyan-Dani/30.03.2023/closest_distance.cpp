#include <bits/stdc++.h>

using namespace std;

int t;

double ax, ay, bx, by, cx, cy, dx, dy;

double value(double p)
{
	double nx, ny, mx, my;
	nx = ax + (bx - ax) * p;
	ny = ay + (by - ay) * p;
	mx = cx + (dx - cx) * p;
	my = cy + (dy - cy) * p;
	return (nx - mx) * (nx - mx) + (ny - my) * (ny - my);
}

void solve(int k)
{
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
	double l = 0.0, r = 1.0, m1, m2, v1, v2, opt;
	for(int i = 0; i <= 1000; i++)
	{
		m1 = l + (r - l) * (1.0 / 3);
		m2 = l + (r - l) * (2.0 / 3);
		v1 = value(m1);
		v2 = value(m2);
		if(v1 < v2)
		{
			opt = v1;
			r = m2;
		}
		else
		{
			opt = v2; 
			l = m1;
		}
	}
	cout << "Case " << k << ": " << setprecision(13) << sqrt(opt) << endl;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	for(int i = 1; i <= t; i++)solve(i);
	
	
	return 0;
}
/*

3
0 0 5 0 5 5 5 0
0 0 5 5 10 10 6 6
0 0 5 0 10 1 1 1


*/
