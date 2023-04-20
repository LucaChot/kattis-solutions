#include <iostream>
#include <cmath>
using namespace std;

int small;

float solve(int pages[small-1]){
	float length = 0;
	int used[small-1];
	for(int i = 0; i < small-1; i++){
		used[i]=0;
	}
	int goal = pow(2, small-1);
	int current = 0;
	int index = 0;
	while(index < small - 1 && current < goal){
		if(pages[index] != 0){
			current += pow(2, small-2-index);
			used[index] += 1;
			//cout << index + 1 << " " << current << ' ' << used[index] << "\n";
			pages[index] -= 1;
		}else{
			index +=1 ;
		}
	}
	if(current != goal){
		return -1;
	}
	index = small-2;
	while(index >= 0){
		if(used[index] >= 2){
			if(index % 2 == 0){
				length+= pow(2, -3.0 / 4.0 - index / 2.0);

			}else{
				length += pow(2, -5.0 / 4.0 - (index-1) /2.0);
			}
			used[index-1] += 1;
			used[index] -= 2;
		}else{
			index -= 1;
		}
	}
	return length;
}


int main() {
	cin >> small;
	int pages[small-1];
	for(int i=0; i < small-1; i++){
		cin >> pages[i];
		//cout << pages[i];
	}
	//cout << pages[2];
	float cost = solve(pages);
	if(cost < 0){
		cout << "impossible";
	}else{
		cout << cost;
	}
	
	return 0;
}
