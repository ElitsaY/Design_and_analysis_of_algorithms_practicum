class Solution {
public:

    bool check(int goal, const vector <int> &nums)
    {
        int64_t carry = 0;
        for (int i = nums.size() - 1; i >= 1; i--)
        {
            if (nums[i] + carry > goal)
            {
                carry = nums[i] + carry - goal;
            }
            else
            {
                carry = 0;
            }
        }

        return nums[0] + carry <= goal;
    }

    int minimizeArrayValue(vector<int>& nums)
    {
        int l = 0, r = 1e9, mid;
        while (l + 1 < r)
        {
            mid = (l + r) / 2;

            if (check(mid, nums))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        if (check(l, nums))
        {
            return l;
        }
        return r;
    }
};
