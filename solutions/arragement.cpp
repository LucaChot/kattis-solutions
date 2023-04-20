#include <cstddef>
#include <iostream>
using namespace std;
/*
int main(){
    int n;
    cin >> n;

    int non_zero = 0;
    int zero = 0; 
    
    for(int i = 0; i < n-1;){
        int x;
        cin >> x;
        int next_non_zero, next_zero;
        if(x != 0){
            next_non_zero = non_zero + x * (i+1);
            if(non_zero > zero){
                next_zero = non_zero + x * (i+2);
            }else{
                next_zero = zero + x * (i+2);
            }
            non_zero = next_non_zero;
            zero = next_zero;
            i++;
        }
    }
    if(non_zero > zero){
        cout << non_zero;
    }else{
        cout << zero;
    }

    
    return 0;
}
*/

int main(){
    int n;
    cin >> n;

    int m[n-1];
    int start = 0;
    
    for(int i = 0; i < n-1;){
        int x;
        cin >> x;
        if(x != 0){
            m[i] = x;
            start += x * (i+1); 
            i++;
        }
    }


    int end = 0;
    int maximum = start + end;
    //cout << start + end << '\n';
    for(int i = n-2; i >= 0; i--){
        start -= m[i] *(i+1);
        end += m[i] * (i+2);
        if(start + end > maximum){
            maximum = start + end;
        }
    }

    cout << maximum;
    return 0;
}