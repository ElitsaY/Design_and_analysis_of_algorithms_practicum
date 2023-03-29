#include <bits/stdc++.h>

using namespace std;

#define MAX 110
#define eps 0.0000001

int n, a[MAX], b[MAX], c[MAX];

double ansx, ansy, ansz;

double calc(double x, double y, double z)
{
	double ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans = max(ans, sqrt((x - a[i]) * (x - a[i]) + (y - b[i]) * (y - b[i]) + (z - c[i]) * (z - c[i])));
	}
	return ans;
}

double solve_for_third(double x, double y)
{
	double l, r, m1, m2, opt, s1, s2;
	l = -11000;
	r = 11000;
	while(fabs(r - l) >= eps)
	{
		m1 = l + (r - l) * (1.0 / 3);
		m2 = l + (r - l) * (2.0 / 3);
		s1 = calc(x, y, m1);
		s2 = calc(x, y, m2);
		if(s1 > s2)
		{
			l = m1;
			ansz = m2;
			opt = s2;
		}
		else
		{
			r = m2;
			ansz = m1;
			opt = s1;
		}
	}
	return opt;
}

double solve_for_second(double x)
{
	double l, r, m1, m2, opt, s1, s2;
	l = -11000;
	r = 11000;
	while(fabs(r - l) >= eps)
	{
		m1 = l + (r - l) * (1.0 / 3);
		m2 = l + (r - l) * (2.0 / 3);
		s1 = solve_for_third(x, m1);
		s2 = solve_for_third(x, m2);
		if(s1 > s2)
		{
			l = m1;
			ansy = m2;
			opt = s2;
		}
		else
		{
			r = m2;
			ansy = m1;
			opt = s1;
		}
	}
	return opt;
}

double solve_for_first()
{
	double l, r, m1, m2, opt;
	l = -11000;
	r = 11000;
	while(fabs(r - l) >= eps)
	{
		m1 = l + (r - l) * (1.0 / 3);
		m2 = l + (r - l) * (2.0 / 3);
		if(solve_for_second(m1) > solve_for_second(m2))
		{
			l = m1;
			ansx = m2;
		}
		else
		{
			r = m2;
			ansx = m1;
		}
	}
	return opt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++)cin >> a[i] >> b[i] >> c[i];
	
	solve_for_first();
	
	cout << setprecision(7) << fixed << ansx << " " <<  ansy << " " << ansz << endl;
	return 0;
}
