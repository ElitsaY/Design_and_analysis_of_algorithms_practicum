#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int VERTICES = 1024;
int n; //брой върхове
int m; //брой ребра
vector<int> gr[VERTICES];
bool used[VERTICES];
queue<int> spis;
int levels[VERTICES];

void bfs(int start){
    //1) маркираме стартовия връх за посетен
    //2) добавяме го в опашката
    used[start] = 1;
    spis.push(start);

    int level = 1; //на кое ниво сме
    int nodesOfLevel = 1; //колко върха имаме от текущото ниво

    //докато имаме върхове в опашката
    while(!spis.empty()){
        //вземаме върха, който е най-отгоре на опашката
        int node = spis.front();
        levels[node] = level;
        //и го махаме
        spis.pop();
        //намаляваме броя на върховете от текущото ниво
        nodesOfLevel--;
        //обхождаме всички непосетени съседи на node
        //маркираме ги за посетени и ги добавяме в опашката
        for(int i = 0; i < gr[node].size(); i++){
            if(!used[gr[node][i]]){
                used[gr[node][i]] = 1;
                spis.push(gr[node][i]);
            }
        }
        if(nodesOfLevel == 0){
            level++;
            nodesOfLevel = spis.size();
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    int from, to;
    for(int i = 0; i < m ; i++){
        scanf("%d %d", &from, &to);
        gr[from].push_back(to);
        gr[to].push_back(from);
    }
    bfs(1);
    for(int i = 1; i <= n; i++){
        printf("%d ", levels[i]);
    }
    printf("\n");
}
/*
    10 13
    1 2
    1 3
    1 4
    1 5
    2 6
    3 5
    3 4
    4 6
    5 10
    5 8
    6 7
    8 9 
    8 7
*/