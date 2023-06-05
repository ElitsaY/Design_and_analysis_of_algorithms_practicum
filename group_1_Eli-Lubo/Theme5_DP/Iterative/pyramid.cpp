/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/196
 * @date 01/06/2023
 * 
*/

#include <iostream>
#include <algorithm>

struct Block
{
    int start;
    int end;

    bool operator <=(const Block &other)
    {
        return start >= other.start && end <= other.end;
    }

    friend std::istream& operator >>(std::istream &in, Block &block)
    {
        return in >> block.start >> block.end;
    }
};

int n;
Block blocks[51];
int res[51];

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> blocks[i];

        res[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (blocks[i] <= blocks[j])
            {
                res[i] = std::max(res[i], res[j] + 1);
            }
        }
    }

    printf("%d", *std::max_element(res, res + n));

    return 0;
}