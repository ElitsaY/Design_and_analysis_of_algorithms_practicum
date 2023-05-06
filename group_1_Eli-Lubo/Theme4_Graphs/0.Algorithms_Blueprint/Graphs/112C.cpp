#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int VERTICES = 1024;
int n; ///брой върхове
int m; //брой ребра
vector<int> gr[VERTICES];
queue<int> spis;
bool used[VERTICES];
int components[VERTICES];
int comp = 1;

void bfs(int startNode){
    spis.push(startNode);
    used[startNode] = 1;
    components[startNode] = comp;
    while(!spis.empty()){
        int node = spis.front();
        spis.pop();
        for(int i = 0; i < gr[node].size(); i++){
            if(!used[gr[node][i]]){
                used[gr[node][i]] = 1;
                components[gr[node][i]] = comp;
                spis.push(gr[node][i]);
            }
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
    //Намираме всеки връх от коя компонента е
    for(int node = 1; node <= n; node++){
        //ако съм срещнала непосетен връх, значи 
        //не съм обходила неговата компонента
        if(!used[node]){
            //всички върхове ще са от компонента
            //с номер comp
            bfs(node);
            comp++;
        }
    }
    int q;
    scanf("%d",& q);
    for(int i = 0; i < q; i++){
        scanf("%d %d",&from, &to);
        if(components[from] == components[to]){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    printf("\n");
}