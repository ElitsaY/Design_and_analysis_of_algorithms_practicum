#include <bits/stdc++.h>

using namespace std;

#define MAX 110000

int n, ans, br = 1;

string m[MAX];

void sort(string& a)
{
	int q[30]{};
	for(int i = 0; i < a.size(); i++)q[a[i] - 'a']++;
	a = "";
	for(int i = 0; i < 29; i++)
		for(int j = 0; j < q[i]; j++)a += i + 'a';
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++)cin >> m[i];
	
	for(int i = 0; i < n; i++)sort(m[i]);
	
	sort(m, m + n);
	
	for(int i = 0; i < n; i++)
	{
		if(i < n - 1)if(m[i] == m[i + 1])br++;
		else br = 1;
		if(br > ans)ans = br;
	}
	
	cout << ans << endl;
	return 0;
}

