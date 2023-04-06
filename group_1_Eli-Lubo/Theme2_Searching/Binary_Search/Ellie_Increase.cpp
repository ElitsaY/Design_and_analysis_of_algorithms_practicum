#include<iostream>
#include<algorithm>
using namespace std;

int n;
int m;
int arr[100'002];

bool OK(long long k){
    //алгоритъм на Кадан:
    
    long long sum = 0;
    long long maxSum = 0;
    for(int i = 0; i < n ; i++){
        sum += (arr[i] + (i + 1)*k);
      
        if(sum >= maxSum)
            maxSum = sum;
        if(sum < 0)
            sum = 0;
    }
   return maxSum >= m;
}

void binarySearch(){
    long long left = - 1'000'000'002;
    long long right = 1'000'000'002;
    long long mid;
    long long ans = right;

    while(left <= right){
        mid = (left + right)/2;
        if(OK(mid)) {
            right = mid - 1;
            ans = mid;
           
        }
        else{
            left = mid + 1;
        }
    }
    printf("%lld\n", ans);
}

void init(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    binarySearch();
}

int main(){
    init();   
}