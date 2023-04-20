#include <iostream>
#include <vector>
using namespace std;

int gcd(int m,int n){
    if(n > m){
        int z = m;
        m = n;
        n = z;
    }
    int z;
    while(n != 0){
        z = m % n;
        m = n;
        n = z;
    }
    return m;
}

void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    int loops = gcd(len, k);
    cout << loops << '\n';
    for(int i = 0; i < loops; i++){
        int curr = i;
        int buffer = nums[i];
        int pos = -1;
        while(pos != i){
            pos = (curr + k) % len;
            int z = nums[pos];
            nums[pos] = buffer;
            buffer = z;
            curr = pos;
        }
    } 
}

int main(){
    vector<int> m = {1,2,3,4};
    rotate(m, 4);
    for(int i = 0; i < 4; i++){
        cout << m[i] << " ";
    }
    return 0;
}