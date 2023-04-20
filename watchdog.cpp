#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <typeinfo>
using namespace std;

class Coord {
    int x;
    int y;
public:
    Coord(){};
    Coord(int x1, int y1) : x(x1), y(y1) {}

    bool operator==(Coord b){
        return x==b.x && y==b.y;
    }

    int distance(Coord b){
        return ((x-b.x) * (x-b.x)) + ((y - b.y) * (y - b.y));
    }
};

void solution(void){
    int s, test;
        cin >> s >> test;
        Coord coordinates[test];
        for(int a = 0; a < test; a++){
            int x, y;
            cin >> x >> y;
            coordinates[a] = Coord(x,y);
        }
        bool success = false;

        for(int i = 1; i < s ; i++){
            for(int j = 1; j < s; j++){
                Coord curr = Coord(i,j);
                int d = min(min(s - i, i), min(s - j, j));
                d = d * d;
                bool fits = true;
                for(int c = 0; c < test; c++){
                    if((coordinates[c] == curr) || curr.distance(coordinates[c]) > d){
                        fits = false;
                        break;
                    }
                }
                if(fits){
                    cout << i << ' ' << j << '\n';
                    return;
                }
            }
        }
        cout << "poodle\n";
        return;
}

int main(){
    int test_number;
    cin >> test_number;
    for(int t = 0;  t < test_number; t++){
        solution();
    }
    return 0;
}