#include<vector>
using namespace std;

//Problem: https://leetcode.com/problems/sort-an-array/


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int posNums[50002] = {0,};
        int negNums[50002] = {0, };

        //for(int i = 0; i < 50002; i++){
        //    posNums[i] = 0;
        //    negNums[i] = 0;
        //}

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                posNums[nums[i]]++;
            }
            else{
                negNums[(-nums[i])]++;
            }

        }
         vector<int> res;
         for(int i = 50000; i > 0; i--){
              while(negNums[i] > 0){
                  res.push_back(-i);
                  negNums[i]--;
              }
         }
         
         for(int i = 0; i < 50001; i++){
             while(posNums[i] > 0){
                 res.push_back(i);
                 posNums[i]--;
             }
         }
         return res;
    }
};