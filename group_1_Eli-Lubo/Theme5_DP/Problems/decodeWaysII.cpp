/**
 * @author Lyuben Georgiev
 * @brief Problem: https://leetcode.com/problems/decode-ways-ii/description/
 * @date 25/05/2023
 * 
*/

class Solution {
public:
    const long long MOD = 1000000007;
    long long cnt[100001] = {0,};

    long long singleDecode(char c)
    {
        return (c == '*') ? 9 : (c == '0' ? 0 : 1);
    }

    long long doubleDecode(char f, char s)
    {
        if (f == '*' && s == '*')
            return 15;
        else if (f == '*')
            return 1 + (s <= '6');
        else if (s == '*')
            return f == '1' ? 9 : (f == '2' ? 6 : 0);
        else if (f == '1' || (f == '2' && s <= '6'))
            return 1;

        return 0;
    }

    int numDecodings(const string &s) {
        int n = s.size();
        cnt[n-1] = singleDecode(s[n - 1]);
        if (n == 1)
            return cnt[n-1];

        cnt[n-2] = singleDecode(s[n - 2]) * cnt[n-1] + doubleDecode(s[n-2], s[n-1]);

        for (int i = n - 3; i >= 0; --i)
        {
            cnt[i] = (singleDecode(s[i]) * cnt[i+1]) % MOD;
            cnt[i] = (cnt[i] + doubleDecode(s[i], s[i+1]) * cnt[i+2]) % MOD;
        }

        return cnt[0];
    }
};