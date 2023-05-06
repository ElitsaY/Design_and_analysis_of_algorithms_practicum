#include<iostream>
#include<vector>
using namespace std;

const int VERTICES = 1024;
int n; ///брой върхове
int m; //брой ребра
vector<int> gr[VERTICES];
int source, sink;
//source = начален връг
// sink = краен връх

bool used[VERTICES];

void dfs(int node){
    used[node] = 1;
    for(int i = 0; i < gr[node].size(); i++){
        if(!used[gr[node][i]]){
            dfs(gr[node][i]);
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    int from, to;
    for(int i = 1; i <= m; i++){
        scanf("%d %d",&from, &to);
        gr[from].push_back(to);
        gr[to].push_back(from);
    }
    scanf("%d %d",&source, &sink);
    dfs(source);
    if(used[sink] == 1)
        printf("There is a path\n");
}