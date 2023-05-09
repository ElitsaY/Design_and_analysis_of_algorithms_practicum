#include <cstdio>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
using p = pair<int, int>;

bool used[10001];
int opt[10001];
int parent[10001];
priority_queue<p, vector<p>, greater<p> > spis;
int n, m ;
int minutes[10001];
vector<p> gr[10001];

void init(){
    scanf("%d%d",&n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &minutes[i]);
    }
    for(int i = 0; i < m; i++){
        int from, to, w;
        scanf("%d %d %d", &from, &to, &w);
        gr[from].push_back({to, w});
        //gr[to].push_back({from, w});
    }
}

int main(){
    init();
    const int inf = 1e9;
    fill(opt, opt + 10001, inf);
    opt[1] = 0;
    spis.push({0, 1}); // пътя до върха; връх 
    parent[1] = 1;
    while(!spis.empty()){
        int node = spis.top().second;
        used[node] = 1;
        spis.pop();
        for(int i = 0; i < gr[node].size(); i++){
            int to = gr[node][i].first; 
            int edgeCost = gr[node][i].second;
            //first - връх 
            //second - реброто, по което отиваме 
            if(!used[to]){
                //ако все още търсим най-малкият път
                // от 1 до to
                int curPath = opt[node] + edgeCost;
                if(curPath % minutes[to] && to != n){
                    int x = curPath / minutes[to];
                    curPath = (x + 1) * minutes[to];
                }

                if(curPath < opt[to]){
                    parent[to] = node;
                    opt[to] = curPath;
                    spis.push({opt[to], to});
                }
            }
        }
    }
    if(opt[n] == inf){
        printf("-1\n");
    }
    else{
        printf("%d\n",opt[n]);
        vector<int> path;
        int node = n;
        path.push_back(node);
        while(node != parent[node]){
            node = parent[node];
            path.push_back(node);
            
        }
        printf("%d\n", path.size());
        for(int i = path.size() - 1; i > 0; i--){
            printf("%d ", path[i]);
        }
        printf("%d\n", path[0]);
    }

}