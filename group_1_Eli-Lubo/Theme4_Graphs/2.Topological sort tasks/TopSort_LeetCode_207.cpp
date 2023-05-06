#include<vector>
#include<iostream>

class Solution {
public:
    int inDegrees[2000];
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> gr(numCourses + 1);
        int m = prerequisites.size();
        for(int i = 0; i < m; i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            inDegrees[a]++;
            gr[b].push_back(a);
           }
        vector<int> topSort;
        for(int i = 0; i < numCourses; i++){
            if(inDegrees[i] == 0){
                topSort.push_back(i);
            }
        }
        cout<<topSort.size()<<endl;
        for(int boss = 0; boss < topSort.size(); boss++){
            int theBoss = topSort[boss];
            for(int i = 0; i < gr[theBoss].size(); i++){
                inDegrees[gr[theBoss][i]]--;
                cout<< gr[theBoss][i]<<" "<<inDegrees[gr[theBoss][i]];
                if(inDegrees[gr[theBoss][i]] == 0){
                    topSort.push_back(gr[theBoss][i]);
                }
            }
        }
        return topSort.size() == numCourses;
    }
};