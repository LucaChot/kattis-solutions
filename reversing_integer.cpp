#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool minus = false;
        long copy = x;
        if(x < 0){
            copy = -copy;
            minus = true;
        }
        unsigned long acc = copy;
        int digits = 0;
        while(acc >= 10){
            acc /= 10;
            digits += 1;
        }
        acc = 0;
        for(int i = 0; i <= digits; i++){
            unsigned int digit = copy % 10;
            unsigned long power = pow(10, digits-i);
            acc += digit * power;
            copy = copy / 10;
        }
        int res;
        if(minus){
            if(acc > (unsigned int) INT_MAX+1){
                return 0;
            }
            res = -acc;
        }else{
            if(acc > INT_MAX){
                return 0;
            }
            res = acc;
        }
        return res;
    }
};

int main(){
    Solution s;
    //int r = s.reverse(1534236469);
    cout << -3%10;
}
