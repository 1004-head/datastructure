#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int k, n;
    cin >> k >> n;

    int park[k] ={0,};    
    int size = 0, last=0;
    for(int i = 0; i < n; i++){
        int car;
        cin >> car;
        if(car > 0){
            size++;
            last++;
            if(size == k && size == last){
                k *= 2;
                int tmp[k] = {0,};
                for(int i=0; i<k/2; i++) tmp[i] = park[i];
                *park = *tmp;
            }else{
                
            }
        }else{
            car *= -1;
            size--;
            for(int i=0; i<=size; i++){

            }
        }
    }
    return 0;
}