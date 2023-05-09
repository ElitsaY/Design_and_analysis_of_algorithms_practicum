#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool color[102];
    bool used[102];

    void dfs(int node, bool c, vector<vector<int>>& gr, bool& ans){
        used[node] = 1;
        color[node] = c;
        for(int i = 0; i < gr[node].size(); i++){
            if(!used[gr[node][i]]){
                dfs(gr[node][i], !c, gr, ans);
            }
            else{
                if(color[node] == color[gr[node][i]]){
                    ans = false;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        bool ans = true;
        for(int i = 0; i < graph.size(); i++){
            if(!used[i]){
                dfs(i, 0, graph, ans);
            }
        }
        return ans;   
    }
};