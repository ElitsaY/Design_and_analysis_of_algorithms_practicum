#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

#define MAX 310000

int n, br[MAX];

string s;

int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	
	n = s.size();
	
	br[0] = 1;
	
	for(int i = 1; i <= n; i++)
	{
		br[i] = br[i - 1];
		if(s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n'))
		{
			br[i] += br[i - 2];
		}
		if(s[i - 1] == 'm' || s[i - 1] == 'w')br[i] = 0;
		br[i] %= MOD;
	}
	
	cout << br[n] << endl;
	
	
	return 0;
}
