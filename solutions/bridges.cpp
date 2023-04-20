//https://open.kattis.com/problems/bryr?editsubmit=10830627

#include <iostream>
using namespace std;

int get_pos(short n, short a, short b){
    return (n * (n+1) / 2) - ((n-a) * (n-a+1) / 2) + (b-a);
}

int main(){
    short n, r;
    cin >> n;
    cin >> r;
    int len = n * (n+1) / 2;
    short m[len];
    for(int i = 0; i < len; i++){
        m[i] = n;
    }
    for(; r > 0; r--){
        short a, b, bridge;
        cin >> a >> b >> bridge; 
        if(a < b){
            m[get_pos(n, a-1, b-1)] = bridge;
        }else{
            m[get_pos(n, b-1, a-1)] = bridge;
        }
    }
    bool change = true;
    while(change){
        change = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    short d1, d2;
                    if(i < k){
                        d1 = m[get_pos(n, i, k)];
                    }else{
                        d1 = m[get_pos(n, k, i)];
                    }
                    if(j < k){
                        d2 = m[get_pos(n, j, k)];
                    }else{
                        d2 = m[get_pos(n, k, j)];
                    }
                    short d = d1 + d2;
                    int pos;
                    if(i < j){
                        pos = get_pos(n, i, j);
                    }else{
                        pos = get_pos(n, j, i);
                    }
                    if(d < m[pos]){
                        m[pos] = d;
                        change = true;
                    }
                }
            }
        }
    }
    cout << m[get_pos(n, 0, n-1)];
    return 0;
}