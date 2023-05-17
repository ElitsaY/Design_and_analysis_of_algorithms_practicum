//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:

    static const int MAX_N = 1000;
    static const int MAX_W = 1000;
    static const int inf = 1e9;

    int memo[MAX_N + 5][MAX_W + 5];

    int biggestVal(int ind, int W, int wt[], int val[], int n)
    {
        if (ind == n)
        {
            return 0;
        }
        if (memo[ind][W] != -1)
        {
            return memo[ind][W];
        }

        int ans = biggestVal(ind + 1, W, wt, val, n);
        if (wt[ind] <= W)
        {
            ans = max(ans, biggestVal(ind + 1, W - wt[ind], wt, val, n) + val[ind]);
        }

        memo[ind][W] = ans;
        return ans;
    }

    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                memo[i][w] = -1;
            }
        }

        return biggestVal(0, W, wt, val, n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;

        int val[n];
        int wt[n];

        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];

        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;

    }
	return 0;
}
// } Driver Code Ends
