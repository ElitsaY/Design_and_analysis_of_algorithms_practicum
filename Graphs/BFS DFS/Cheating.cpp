#include<iostream>
#include<cstdio>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

struct vertex
{
	int to;
	int danger;
}temp;

int n,m,k;
vector<vertex> gr[10100];
deque<int> spis;
bool used[10100];
int opt[10100];

void bfs()
{
	int node;
	fill(opt,opt+n,1e9);
	opt[n] = 0;
	spis.push_front(n);
	while(!spis.empty())
	{
		node = spis.front();
		used[node] = 1;
		spis.pop_front();
		
		for(int i = 0; i < gr[node].size(); i++)
		{
			temp = gr[node][i];
			
			if(used[temp.to] == 1) continue;
			else
			{
				int dist = opt[node] + temp.danger;
				if(dist < opt[temp.to])
				{
					opt[temp.to] = dist;
					if(temp.danger == 0) spis.push_front(temp.to);
					else spis.push_back(temp.to); 
				}
			}//end of if
		}//end of for
	}//end of while
	if(opt[1] == 1e9) printf("-1\n");
	else printf("%d\n",opt[1]);
}

void init()
{
	int a,b;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d",&a,&b);
		temp.to = b;
		temp.danger = 0;
		gr[a].push_back(temp);
		temp.to = a;
		gr[b].push_back(temp);
	}
	for(int i = 0; i < k; i++)
	{
		scanf("%d%d",&a,&b);
		temp.to = b;
		temp.danger = 1;
		gr[a].push_back(temp);
		temp.to = a;
		gr[b].push_back(temp);
	}
	bfs();
}

int main()
{
	init();
}
