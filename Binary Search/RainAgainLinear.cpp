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

int findAnswer()
{
	nullify();	
	int key = 1;
	int potBr = l/d;
	for(int i = 0; i < n; i++)
	{
		int curDrop = drop[i]/d;
		potMin[curDrop] = min(potMin[curDrop], drop[i]);
		potMax[curDrop] = max(potMax[curDrop], drop[i]);
		
		while(key <= potBr && potMin[key] - potMax[key-1] <= d) 
		{
			//printf("potMin[%d] = %d potMax[%d] = %d\n", key, potMin[key], key-1, potMax[key-1]);
			key++;
		}
		if(key > potBr) 
		{
			i++;
			return i;	
		}
	}
	return -1;
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
	
	int ans = findAnswer();
	printf("%d\n", ans);
}
