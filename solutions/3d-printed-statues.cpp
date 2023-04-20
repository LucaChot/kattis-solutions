//https://open.kattis.com/problems/3dprinter

#include <iostream>
#include <cmath>
using namespace std;

int num;


int main() {
    cin >> num;
    int x = ceil(log2(num * log(2)));
    cout << (x + ceil(num/ pow(2, x)));
    return 0;
}
