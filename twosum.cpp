#include<iostream>
#include <vector>
#include <map>
using namespace std;

typedef struct pair{
    int first;
    int second;
} Pair;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        map<int, Pair> m;
        for(int i = 0; i < len; i++){
            int val = nums[i];
            map<int,Pair>::iterator it = m.find(val);
            if(it != m.end()){
                Pair* p = &m[val];
                p->first = (p->first)+1;
                p->second = i;
            }else{
                Pair p = {0, i};
                m[val] = p;
            }
        }
        for(int i = 0; i < len; i++){
            int val = nums[i];
            int rest = target - val;
            map<int,Pair>::iterator it = m.find(rest);
            if(it != m.end()){
                if(rest == val){
                    if(m[val].first > 0) {
                        vector<int> r = {i, m[rest].second};
                        return r;
                    } 
                }else{
                    vector<int> r = {i, m[rest].second};
                    return r;
                }
            }
        }
    return vector<int>{0,1};
    }
};

int main(){
    Solution s;
    vector<int>v = {3,2,4};
    vector<int> r = s.twoSum(v, 6);
    cout << r[0] << ' ' << r[1];
}