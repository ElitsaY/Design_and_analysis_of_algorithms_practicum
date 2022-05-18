#include<iostream>
using namespace std;

int n, k;
unsigned int l;
unsigned int len[100005];

bool OK(int x)
{
	//corner cases
	if(x < len[0]) return false;
	if(l - len[n - 1] > x) return false;
	int lastStop = 0, br = 0;
	for(int i = 0; i < n; i++)
	{
		if(len[i] - lastStop > x)
		{
			//trqbva da zaredq na prednata benzinostanciq
			lastStop = len[i-1];
			if(len[i] - lastStop > x) return false;
			br++; // broj zarejdaniq
		}
	}
	if(l-lastStop > x) br++;
	if(br <= k) return true;
	return false;
}

int main()
{
	scanf("%d%d%d",&n, &k,&l);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&len[i]);
	}
	int left = 0, r = l;
	int mid, ans = l;
	while(left <= r)
	{
		mid = (left + r) / 2;
		//printf("mid = %d\n", mid);
		if(OK(mid) == true) 
		{
			ans = min(ans, mid);
			r = mid - 1;
		}
		else left = mid + 1;
	}
	printf("%d\n", ans);
}

/*
11 42
33 17 42 13 7 5 23 20 1 18 6
*/

/*
8 2 1337
13 133 411 730 733 911 1113 1276
*/
