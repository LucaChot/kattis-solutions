//https://open.kattis.com/problems/gourmeten?editsubmit=10831066

#include <iostream>
using namespace std;

int main(){
    int g, n;
    cin >> g;
    cin >> n;

    int m[n];
    int a[g+1];
    a[0] = 1;
    
    for(int i = 1; i <= g; i++){
        a[i] = 0;
    }

    for(int i = 0; i < n; i++){
        cin >> m[i];
    }

    for(int i = 1; i <= g; i++){
        for(int j = 0; j < n; j++){
            if(m[j] <= i){
                a[i] += a[i-m[j]];
            }
        }
    }
    
    cout << a[g];
    
    return 0;
}