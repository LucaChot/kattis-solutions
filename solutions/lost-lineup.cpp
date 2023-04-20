//https://open.kattis.com/problems/lostlineup

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int p [n];
  p[0] = 1;
  for(int i = 1; i < n; i++){
    int pos;
    cin >> pos;
    p[pos+1] = i+1;
  }
  for(int i = 0; i < n; i++){
    cout << p[i] << " ";
  }
}