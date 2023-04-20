//https://open.kattis.com/problems/pieceofcake2

#include <iostream>
using namespace std;

int main() {
  int n, h, v, x, y;
  cin >> n >>h >>v;
  if(2*h > n){
    x = h;
  }else{
    x = n- h;
  }
  if(2*v > n) {
    y = v;
  }else{
    y = n - v;
  }
  cout << 4 * x * y;
}