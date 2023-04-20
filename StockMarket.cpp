#include <iostream>

using namespace std;

int main(){
    int days;
    double cost;
    cin >> days >> cost;
    float amount = 100;
    float stocks = 0;
    float min, max = 0;
    float today = 0;
    for(int t = 0;  t < days; t++){
        float tomorrow;
        cin >> tomorrow;
        if(tomorrow > today && amount > cost){
            amount -= 2 * cost;
            stocks = tomorrow / amount;
            amount = cost;
        }

        if(tomorrow > today && amount > cost){
            amount -= 2 * cost;
            stocks = tomorrow / amount;
            amount = cost;
        }
    }
    return 0;
}