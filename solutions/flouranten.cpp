//https://open.kattis.com/problems/fluortanten

#include <cstddef>
#include <iostream>
using namespace std;

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