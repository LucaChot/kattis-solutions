//Problem E Integer Lists
//https://open.kattis.com/contests/xjhzmw/problems/integerlists

#include <iostream>
using namespace std;

void solve(){
    string action;
    cin >> action;
    int length;
    cin >> length;
    int list[length];
    char buff;
    string l;
    cin >> l;
    int listpointer = 0, pointer = 1, llen = l.length();
    while(listpointer < length){
        list[listpointer] = 0;
        while(l[pointer] != ',' && l[pointer] != ']'){
            list[listpointer] = list[listpointer] * 10 + (l[pointer]-48);
            pointer += 1;
        }
        listpointer+= 1;
        pointer += 1;
    }
    int start = 0, end = length-1, dir = 1;
    int apointer = 0, alen = action.length();
    //cout << start << ' ' << end << '\n';
    while(apointer < alen){
        switch (action[apointer]) {
        case 'R': {
            int z = start;
            start = end;
            end = z;
            dir = -dir;
            break;
        }
        case 'D':{
            if(start *dir > end * dir){
                cout << "error";
                return;
            }
            start += dir;
            break;
        }
    }
    apointer += 1;
    //cout << start << ' ' << end << '\n';
    }
    cout << '[';
    pointer = start;
    while(pointer * dir <= end * dir){
        if(pointer == end) cout << list[pointer];
        else cout << list[pointer] << ',';
        pointer += dir;
    }
    cout << ']';
}

int main(){
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        solve();
        cout << '\n';
    }
    
    return 0;
}