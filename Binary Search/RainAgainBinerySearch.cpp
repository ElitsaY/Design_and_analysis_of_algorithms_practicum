#include<iostream>
using namespace std;

const int maxLen = 10000050;
int n, l, d;
int first, a, b;
int drop[maxLen];
int potMax[maxLen], potMin[maxLen];

void nullify()
{
	for(int i = 0; i < l/d; i++)
	{
		potMax[i] = i*d;
		potMin[i] = (i+1)*d;
		//potMin[i] = (i+1)*d;
	}
	potMax[l/d] = l;
	potMin[l/d] = l;
}

bool OK(int drops)
{
	nullify();
	for(int i = 0; i < drops; i++)
	{
		int curDrop = drop[i]/d;
		potMax[curDrop] = max(potMax[curDrop], drop[i]);
		potMin[curDrop] = min(potMin[curDrop], drop[i]);	
	}
	//link
	for(int i = 1; i <= l/d; i++)
	{
		if(potMin[i] - potMax[i-1] > d) return false;
	}
	return true;
}

int main()
{
	scanf("%d%d%d",&n, &l, &d);
	scanf("%d%d%d", &first, &a, &b);
	
	drop[0] = first;
	
	for(int i = 1; i < n; i++)
	{
		drop[i] = ((long long)drop[i-1]*a + b) % (l+1);
		//printf("%d ", drop[i]);
	}
	
	int l = 1, r = n;
	int mid, ans = -1;
	while(l <= r)
	{
		mid = (l + r)/2 ;
		if(OK(mid) == true)
		{
			ans = mid;
			r = mid -1;
		}
		else l = mid + 1;
	}
	printf("%d\n", ans);
}
