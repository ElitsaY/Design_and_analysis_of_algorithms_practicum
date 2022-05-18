//old solution
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define PA pair<int,int>
using namespace std;

struct edge
{
	//int from;
	int to;
	int path;
}temp;

int n, m;
int bus[10005];
vector<edge> gr[10005];
vector<int> ans;
priority_queue< PA, vector<PA>, greater<PA> > spis;
int used[10005];
int opt[10005];
int p[10005];

void init()
{
	int a,b,c;
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n ; i++) scanf("%d",&bus[i]);
	for(int i = 0; i < m ; i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		temp.to = b;
		temp.path = c;
		gr[a].push_back(temp);
	}
}

void short_path()
{
	fill(opt,opt+n+1,1e8+9);
	spis.push( make_pair(0,1) );
	opt[1] = 0;
	int node;
	while(!spis.empty())
	{
		node = spis.top().second;
		used[node] = 1;
		//printf("%d\n",node);
		spis.pop();
		for(int i = 0; i < gr[node].size(); i++)
		{
			temp = gr[node][i];
			if(!used[temp.to])
			{
				int curP = opt[node] + temp.path;
				int wait,x;			
				
				if(temp.to == n || curP % bus[temp.to] == 0) wait = 0;
				else 
				{
					x = curP / bus[temp.to];
					wait = bus[temp.to]*(x+1) - curP;
				}
				//printf("to=%d wait=%d x=%d curP=%d\n",temp.to,wait,x,curP);
				if(curP + wait < opt[temp.to])
				{
					opt[temp.to] = curP + wait;
					p[temp.to] = node;
					spis.push( make_pair(opt[temp.to],temp.to) );
				}
			}
		}//end of for
	}//end of while
	
}

void output()
{
	cout<<opt[n]<<endl;
	int ver = n;
	ans.push_back(n);
	while(ver != 1)
	{
		ver = p[ver];
		ans.push_back(ver);
	}
	int s = ans.size();
	printf("%d\n",s);
	for(int i = s-1 ; i >= 1; i--)
	{
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[0]);
}

int main()
{
	init();
	short_path();
	if(opt[n] == 1e8+9) printf("-1\n");
	else output();
}
/*
5 6
3 19 9 11 5
1 2 17
1 4 3
2 3 8
4 3 18
4 5 33
3 5 15

3 2
6 6 6
1 2 13
3 2 13
*/
