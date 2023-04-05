class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end(), greater <int> ());

        int64_t sum = 0, coef = 0;
        for (int x : satisfaction)
        {
            if (coef + sum + x > coef)
            {
                coef += sum + x;
                sum += x;
            }
        }

        return coef;
    }
};
