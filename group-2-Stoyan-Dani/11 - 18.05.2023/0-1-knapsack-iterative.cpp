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

    int dp[MAX_N + 5][MAX_W + 5];

    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                dp[i][w] = -1e9;
            }

            for (int w = 0; w <= W; w++)
            {
                if (i != 0)
                {
                    dp[i][w] = max(dp[i][w], dp[i - 1][w]);
                    if (wt[i] <= w)
                    {
                        dp[i][w] = max(dp[i][w], dp[i - 1][w - wt[i]] + val[i]);
                    }
                }

            }
            dp[i][wt[i]] = max(dp[i][wt[i]], val[i]);
        }

        int ans = 0;
        for (int w = 0; w <= W; w++)
        {
            ans = max(ans, dp[n - 1][w]);
        }

        return ans;
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
