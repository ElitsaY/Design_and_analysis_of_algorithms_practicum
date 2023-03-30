#include<iostream>
#include<algorithm>
using namespace std;

int n;      //брой бензиностанции по пътя
int k;      // максимален брой зареждания
int fmi;    // позиция на ФМИ
int stop[100050]; 

bool OK(int capacity){
    int lastStop = 0;        //последната бензиностанция, на която смензаредили
    int refillCount = 0;     // броя пъти, които сме презаредили
    stop[n] = fmi;
    
    for(int i = 0; i <= n; i++){

        if(stop[i] - lastStop > capacity){
            refillCount++;
            lastStop = stop[i - 1];
        }
    }
    return refillCount <= k;
}

int main(){
    scanf("%d %d %d",&n, &k, &fmi);
    int maxDist = 1;
    scanf("%d", &stop[0]);
	for(int i = 1; i < n; i++) {
        scanf("%d",&stop[i]);
        maxDist = max(maxDist, stop[i] - stop[i - 1]);
    }
    maxDist = max(maxDist, fmi - stop[n - 1]);
    // binery search: намираме минималния капацитет на резервоара
    int left = maxDist;
    int right = fmi;
    int mid;
    int minCapacity = fmi; 

    while(left <= right){
        mid = left + (right - left)/2;
        if(OK(mid)){
            right = mid - 1;
            minCapacity = min(minCapacity, mid);
        }
        else{
            left = mid + 1;
        }
    }

    printf("%d\n", minCapacity);
}