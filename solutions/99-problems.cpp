//https://open.kattis.com/problems/99problems

#include <iostream>
#include <cmath>
using namespace std;

int num;

int main() {
    cin >> num;
    int x = (num / 100) * 100 + 99;
    int y = ((num / 100) -1) * 100 + 99;
    if(y < 0 || abs(num - x) <= abs(num - y)){
        cout << x;
    }else{
        cout << y;
    }
    return 0;
}