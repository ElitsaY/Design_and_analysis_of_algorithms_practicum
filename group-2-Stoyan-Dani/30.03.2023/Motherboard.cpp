#include <bits/stdc++.h>
using namespace std;

#define MAX 105

long long n, x[MAX], y[MAX], l, r, m1, m2, opt, t;

long long calc(int yt)
{
	long long tmp, mi = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			tmp = abs(y[i] - yt) + abs(x[i] - x[j]) + abs(y[j] - yt);
			mi = max(mi, tmp);
		}
	}
	return mi;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	opt = 1000000000000;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		l = min(l, y[i]);
		r = max(r, y[i]);
	}
	while(l <= r)
	{
		m1 = l + (r - l) / 3;
		m2 = l + 2 * (r - l) / 3;
		if(calc(m1) < calc(m2))
		{
			r = m2 - 1;
			opt = min(opt, calc(m1));
		}
		else
		{
			l = m1 + 1;
			opt = min(opt, calc(m2));
		}
	} 
	cout << opt << endl;
	return 0;
}

/*


*/
