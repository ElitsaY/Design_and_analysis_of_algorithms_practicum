#include <random>
#include <vector>
#include <iostream>

using namespace std;

mt19937 rnd(22);

int findKthLargest(vector<int> v, int k)
{
    k--;
    while (true)
    {
        int pivot = v[rnd() % v.size()];

        int biggerCnt = 0, equalCnt = 0;
        for (int x : v)
        {
            if (x > pivot)
            {
                biggerCnt++;
            }
            else if (x == pivot)
            {
                equalCnt++;
            }
        }

        if (biggerCnt <= k && k <= biggerCnt + equalCnt - 1)
        {
            return pivot;
        }

        if (k < biggerCnt)
        {
            vector <int> newV;
            for (int x : v)
            {
                if (x > pivot)
                {
                    newV.push_back(x);
                }
            }

            v = newV;
        }
        else
        {
            vector <int> newV;
            for (int x : v)
            {
                if (x < pivot)
                {
                    newV.push_back(x);
                }
            }

            k -= biggerCnt + equalCnt;
            v = newV;
        }
    }
}

int main()
{

}
