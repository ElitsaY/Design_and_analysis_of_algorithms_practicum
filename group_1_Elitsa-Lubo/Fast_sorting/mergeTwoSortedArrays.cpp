#include <cstdio>


void mergeArr(const int arr1[], const int arr2[], int n, int m, int result[])
{
    int i = 0, j = 0, k = 0;

    while(i < n && j < m)
    {
        if(arr1[i] <= arr2[j])
        {
            result[k++] = arr1[i++];
        }
        else
        {
            result[k++] = arr2[j++];
        }
    }

    while(i < n)
    {
        result[k++] = arr1[i++];
    }

    while(j < m)
    {
        result[k++] = arr2[j++];
    }
}

int main(){
    int arr1[] = { 1, 2, 3, 5, 6, 8, 12 };
    int arr2[] = { 0, 4, 5, 5, 11, 15 };

    const int n = 7, m = 6;

    int result[n + m];

    mergeArr(arr1, arr2, n, m, result);

    for(int i = 0; i < n + m; ++i)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}