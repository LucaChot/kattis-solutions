//Problem A Cut the Negativity
//https://open.kattis.com/contests/xjhzmw/problems/cutthenegativity

#include <iostream>
using namespace std;

int main(){
    int no_towns;
    cin >> no_towns;
    int costs[no_towns][no_towns];
    int total = 0;
    for(int i = 0; i < no_towns; i ++){
        for(int j = 0; j < no_towns; j++){
            int cost;
            cin >> cost;
            costs[i][j] = cost;
            if(cost != -1){
                total += 1;
            }
        }
    }

    cout << total << '\n';

    for(int i = 1; i <=no_towns; i ++){
        for(int j = 1; j <= no_towns; j++){
            if(costs[i-1][j-1] != -1){
                cout << i << ' ' << j << ' ' << costs[i-1][j-1] << '\n';
            }
        }
    }
    
    return 0;
}