#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAX_VERTEX_COUNT = 2005;

std::vector<int> graph[MAX_VERTEX_COUNT];
std::queue<int> spis;
std::vector<int> answer;

int vertexCount, edgeCount;
bool visited[MAX_VERTEX_COUNT];
int component[MAX_VERTEX_COUNT];

void bfs(int startNode, int componentInd)
{
	spis.push(startNode);
	component[startNode] = componentInd;
	int node; // current node
	while(!spis.empty())
	{
		node = spis.front();
		component[node] = componentInd;
		spis.pop();
		for(int i = 0; i < graph[node].size(); i++)
		{
			if(!visited[graph[node][i]])
			{
				visited[graph[node][i]] = true;
				spis.push(graph[node][i]);
			}
		}
	}
}

void findComponents()
{
	int componentInd = 1;
	for(int node = 1; node <= vertexCount; node++)
	{
		if(visited[node] == false) 
		{
			bfs(node, componentInd);
			componentInd++;
		}
			
	}
}

void input()
{
	scanf("%d%d",&vertexCount, &edgeCount);
	int vertexFrom, vertexTo;
	for(int i = 0; i < edgeCount; i++)
	{
		scanf("%d%d", &vertexFrom,&vertexTo);
		graph[vertexFrom].push_back(vertexTo);
		graph[vertexTo].push_back(vertexFrom);
	}
}

void print()
{
	int size = answer.size();
	for(int i = 0; i < size; i++)
	{
		printf("%d",answer[i]);
	}
	printf("\n");
}

void query()
{
	int from, to, q;
	scanf("%d",&q);
	for(int i = 0; i <q; i++)
	{
		scanf("%d%d",&from, &to);
		if(component[from] == component[to]) 
		{
			answer.push_back(1);
		}
		else
		{
			answer.push_back(0);
		}
	}
	print();
}

int main()
{
	input();
	findComponents();
	query();
}

/*
9 9 
1 2
3 4
5 6
7 8
9 5
7 2
8 2
6 9
1 7
3
1 8
6 2
4 7
*/
