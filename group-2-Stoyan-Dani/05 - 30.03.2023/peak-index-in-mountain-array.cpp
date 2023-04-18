class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int l = 0, r = arr.size() - 1;
        while (l + 2 < r)
        {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;

            if (arr[m1] < arr[m2])
            {
                l = m1;
            }
            else
            {
                r = m2;
            }
        }

        int maxInd = l;
        for (int i = l + 1; i <= r; i++)
        {
            if (arr[i] > arr[maxInd])
            {
                maxInd = i;
            }
        }

        return maxInd;
    }
};
