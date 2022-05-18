//old solution
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define PA pair<int,int>
using namespace std;

struct vertex
{
	int to;
	int t;
	int cost;
}temp;

int n,m,k;
vector<vertex> gr[100100];
priority_queue<PA, vector<PA>, greater<PA> > spis;
long long opt[100100];
bool used[100100];

void nullify()
{
	fill(used,used+n+1,0);
	fill(opt,opt+n+1,1e11);
	while(!spis.empty()) spis.pop();
}

bool OK(int x)
{
	nullify();
	//printf("x=%d\n",x);
	int node;
	opt[1] = 0;
	spis.push( make_pair(0,1));
	while(!spis.empty())
	{
		node = spis.top().second;
		used[node] = 1;
		spis.pop();
		for(int i = 0; i < gr[node].size(); i++)
		{
			temp = gr[node][i];
			if(used[temp.to] == 1) continue;
			else
			{
				if(temp.cost<=x)
				{
					long long curT = opt[node] + temp.t;
					//printf("node=%d to=%d curt=%d\n",node,temp.to,curT);
					if(curT < opt[temp.to])
					{
						opt[temp.to] = curT;
						spis.push( make_pair(opt[temp.to],temp.to) );
					}
				}
			}//end of if
		}//end of for
	}//end of while
	if(opt[n] <= k) return true;
	return false;
}

void binery_search(int border)
{
	int l =1, r = border;
	int mid, ans = -1;
	//printf("border=%d\n",border);
	while(l<=r)
	{
		mid = (l + r)/2;
		if(OK(mid) == true) 
		{
			//ans = min(mid ,ans);
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	} 
	//if(ans == 1e6+5) printf("-1\n");
	printf("%d\n",ans);
}

void init()
{
	scanf("%d%d%d",&n,&m,&k);
	int a,b,p,tt;
	int rr = 0;
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d%d%d",&a,&b,&p,&tt);
		rr = max(rr,p);
		temp.to = b;
		temp.cost = p;
		temp.t = tt;
		gr[a].push_back(temp);
	}
	binery_search(rr);
}

int main()
{
	init();
}
