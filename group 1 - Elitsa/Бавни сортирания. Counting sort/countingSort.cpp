// Приемаме че числата са в интеравала [0, 1000].

#include <iostream>

using std::max;
using std::cout;

void sort(int *array, const size_t &size){

    int counter[1002] = { 0, }, m = 0;
    size_t index = 0;

    for(size_t i = 0; i < size; ++i){

        counter[array[i]]++;
        m = max(m, array[i]);

    }
    
    for(size_t i = 0; i <= m; ++i)
        while(counter[i]){
            
            array[index++] = i;
            counter[i]--;

        }

}

int main(){

    int array[] = { 5, 3, 5, 1, 8 };
    size_t size = sizeof(array) / sizeof(int);

    sort(array, size);

    for(size_t i = 0; i < size; ++i)
        cout << array[i] << ' ';
    cout << '\n';

}