class Solution {
public:

    struct Multiset
    {
        map <int, int> valCnt;

        int sizeUnique() const
        {
            return valCnt.size();
        }

        void add(int x)
        {
            valCnt[x]++;
        }

        void remove(int x)
        {
            if (valCnt.count(x))
            {
                valCnt[x]--;
                if (valCnt[x] == 0)
                {
                    valCnt.erase(x);
                }
            }
        }
    };

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int firstCorrectInd = 0, firstWrongInd = 0;
        Multiset correct, wrong;

        int64_t ans = 0;
        wrong.add(nums[0]);
        correct.add(nums[0]);

        for (int i = 0; i < nums.size(); i++)
        {
            while (firstCorrectInd + 1 < nums.size() && correct.sizeUnique() < k)
            {
                firstCorrectInd++;
                correct.add(nums[firstCorrectInd]);
            }

            while (firstWrongInd + 1 <= nums.size() && wrong.sizeUnique() <= k)
            {
                firstWrongInd++;
                if(firstWrongInd < nums.size())
                {
                    wrong.add(nums[firstWrongInd]);
                }
            }

            if (correct.sizeUnique() == k)
            {
                ans += firstWrongInd - firstCorrectInd;
            }

            correct.remove(nums[i]);
            wrong.remove(nums[i]);
        }

        return ans;
    }
};
