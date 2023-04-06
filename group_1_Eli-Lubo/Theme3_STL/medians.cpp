/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/124
 * @date 30/03/2023
 * 
*/

#include <cstdio>
#include <queue>


int n, num;


int main()
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> minPQ;
    std::priority_queue<int> maxPQ; // Default heap is max heap
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &num);

        if(maxPQ.empty() || (num < maxPQ.top()))
        {
            maxPQ.push(num);
        }
        else
        {
            minPQ.push(num);
        }
        
        // rebalance the two halfs to make sure the length difference is no larger than 1
        if(maxPQ.size() > (minPQ.size() + 1))
        {
            minPQ.push(maxPQ.top());
            maxPQ.pop();
        }
        else if(maxPQ.size() + 1 < minPQ.size())
        {
            maxPQ.push(minPQ.top());
            minPQ.pop();
        }

        double res;
        if (maxPQ.size() == minPQ.size())
        {
            res = (maxPQ.top() + minPQ.top()) / 2.0;
        }
        else
        {
            res = (maxPQ.size() > minPQ.size()) ? maxPQ.top() : minPQ.top(); 
        }

        printf("%0.1f ", res);
    }

    return 0;
}