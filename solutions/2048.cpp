//https://open.kattis.com/problems/2048

#include <iostream>
using namespace std;

int map[4][4];
bool has_merged[4][4];

void swap(int ar, int ac, int br, int bc, int m[4][4]){
    int z = m[ar][ac];
    m[ar][ac] = m[br][bc];
    m[br][bc] = z;
}

void swap(int ar, int ac, int br, int bc, bool m[4][4]){
    int z = m[ar][ac];
    m[ar][ac] = m[br][bc];
    m[br][bc] = z;
}



void left(){
    for(int i =0; i < 4; i++){
        for(int j = 0; j < 4; j ++){
            if(map[i][j] != 0){
                bool stopped = false;
                int current = j;
                while(!stopped && current > 0){
                    if(map[i][current-1] == 0){
                        swap(i, current-1, i, current, map);
                        swap(i, current-1, i, current, has_merged);
                        //cout << "Swapped at: " << i << " " << current-1 << '\n';
                        current -= 1;
                    }else{
                        if(map[i][current-1] == map[i][current] && !has_merged[i][current-1] && !has_merged[i][current]){
                            map[i][current-1] = 2 * map[i][current-1];
                            map[i][current] = 0;
                            has_merged[i][current-1] = true;
                            //cout << "Merged at: " << i << " " << current-1 << '\n';
                            current -= 1;
                        }else{
                            stopped = true;
                        }
                    }
                }
            }
        }
    }
}

void right(){
    for(int i =0; i < 4; i++){
        for(int j = 3; j >= 0; j--){
            if(map[i][j] != 0){
                bool stopped = false;
                int current = j;
                while(!stopped && current < 3){
                    if(map[i][current+1] == 0){
                        swap(i, current+1, i, current, map);
                        swap(i, current+1, i, current, has_merged);
                        current += 1;
                    }else if(map[i][current+1] == map[i][current] && !has_merged[i][current+1] && !has_merged[i][current]){
                        map[i][current+1] = 2 * map[i][current+1];
                        map[i][current] = 0;
                        has_merged[i][current+1] = true;
                        current += 1;
                    }else{
                        stopped = true;
                    }

                }
            }
        }
    }
}

void down(){
    for(int i =0; i < 4; i++){
        for(int j = 3; j >= 0; j--){
            if(map[j][i] != 0){
                bool stopped = false;
                int current = j;
                while(!stopped && current < 3){
                    if(map[current+1][i] == 0){
                        swap(current+1, i, current, i, map);
                        swap(current+1, i, current, i, has_merged);
                        current += 1;
                    }else if(map[current+1][i] == map[current][i] && !has_merged[current+1][i] && !has_merged[current][i]){
                        map[current+1][i]= 2 * map[current+1][i];
                        map[current][i] = 0;
                        has_merged[current+1][i] = true;
                        current += 1;
                    }else{
                        stopped = true;
                    }

                }
            }
        }
    }
}

void up(){
    for(int i =0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(map[j][i] != 0){
                bool stopped = false;
                int current = j;
                while(!stopped && current > 0){
                    if(map[current-1][i] == 0){
                        swap(current-1, i, current, i, map);
                        swap(current-1, i, current, i, has_merged);
                        current -= 1;
                    }else if(map[current-1][i] == map[current][i] && !has_merged[current-1][i] && !has_merged[current][i]){
                        map[current-1][i]= 2 * map[current-1][i];
                        map[current][i] = 0;
                        has_merged[current-1][i] = true;
                        current -= 1;
                    }else{
                        stopped = true;
                    }

                }
            }
        }
    }
}




int main() {
    int move;
    for(int i = 0; i < 4; i++){
        cin >> map[i][0] >> map[i][1] >> map[i][2] >> map[i][3];
    }



    cin >> move;
    switch(move){
        case 0: left();
            break;
        case 1: up();
            break;
        case 2: right();
            break;
        case 3: down();
             break;
    }
    for(int i = 0; i < 4; i++){
        cout << map[i][0] << ' ' << map[i][1] << ' ' << map[i][2] << ' ' << map[i][3] << '\n';
    }
    return 0;
}