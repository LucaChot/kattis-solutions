#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        bool minus = false;
        int pointer = 0;
        while(s[pointer] == ' ' && pointer < len) pointer++;
        if(s[pointer] == '-'){
            minus = true;
            pointer++;
            
        } 
        else if(s[pointer] == '+') pointer++;
        long acc = 0;
        while(pointer < len && s[pointer] >= '0' && s[pointer] <= '9'){
            acc = (acc * 10) + (s[pointer] - '0');
            if(minus && acc >= -INT_MIN) return INT_MIN;
            if(!minus && acc >= INT_MAX) return INT_MAX;
            pointer++;
        }
        if(minus) return -acc;
        return acc;
    }
};

int main(){
    Solution s;
    int r = s.myAtoi("42");
    cout << r;
}
