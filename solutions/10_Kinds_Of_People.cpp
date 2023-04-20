#include <iostream>
using namespace std;

  int r, c, num_inputs;
  bool map[1000][1000];
  bool bmap[1000][1000];


bool solve(int sr, int sw, int er, int ew, bool val){
  //cout << sr << " " << sw << " " << er << " " << ew << " " << val << "\n";
  if(sr < 0 || sr >= r || sw < 0 || sw >= c || bmap[sr][sw] || map[sr][sw] != val){
    return false;
  }
  bmap[sr][sw] = true;
  //cout << "Visited: " << sr << " " << sw << "\n";
  if(sr == er && sw == ew){
    //cout << "Found\n";
    return true;
  }
  return solve(sr-1, sw, er, ew, val) || solve(sr, sw+1, er, ew, val) || solve(sr+1, sw, er, ew, val) || solve(sr, sw-1, er, ew, val);
}

void path(int sr, int sw, int er, int ew){
  //cout << "Called";
  if(map[sr][sw] != map[er][ew]){
    cout << "neither" << "\n";
    return;
  }
  if(solve(sr, sw, er, ew, map[sr][sw])){
    //cout << "Done" << " " << map[sr][sw] << " " << sr << " "<< sw;
    if(map[sr][sw]){
      cout << "decimal" << "\n";
    }
    else{
      cout << "binary" << "\n";
    }
  }
  else
    cout << "neither" << "\n";
}

int main() {
  cin >> r >> c;
  long int line;
  for(int i = 0; i < r; i++){
    cin >> line;
    for(int j = 0; j < c; j++){
      map[i][(c-1)-j] = line%10;
      line = line / 10;
    }
  }
  //cout << "\n" << map[1][0] << "\n";
  int sr, sw, er, ew;
  cin >> num_inputs;
  int list[num_inputs][4];
  for(int i = 0; i < num_inputs; i++){
    cin >> sr >> sw >> er >> ew;
    list[i][0] = sr;
    list[i][1] = sw;
    list[i][2] = er;
    list[i][3] = ew;
  }

  //cout << "DONE" << " " << num_inputs;
  for(int i = 0; i < num_inputs; i++){
    //cout << list[i][0]-1 << " " << list[i][1]-1 << " " << list[i][2]-1 << " "<<  list[i][3]-1 << "\n";
    //cout << "Done";
    path(list[i][0]-1, list[i][1]-1, list[i][2]-1, list[i][3]-1);
  }
}