#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void dispGear(vector<vector<char>> &map, int i, int j);
int gearValue(vector<vector<char>> &map, int i, int j);
bool isNumber(char a);

int main(){
	vector<vector<char>> map;

	ifstream infile;
	infile.open("3.txt");
	if (!infile){
		cout << "Failed to open data file\n";
		return 1;
	}
	else{
		cout << "Data file opened\n";
	}
	string line;
	while(!infile.eof()){
		vector<char> seg;
		getline(infile,line);
		if (line.length() < 1){
			continue;
		}
		for(int i = 0; i < line.length(); i++){
			seg.push_back(line[i]);
		}
		map.push_back(seg);
	}
	vector<vector<int>> sym(map.size(),vector<int>(map[0].size(),0));

	int sum = 0;
	for(int i = 0; i < map.size(); i++){
		for (int j = 0; j < map[i].size(); j++){
			if (int(map[i][j]) == '*'){
				sum += gearValue(map,i,j);
			}
		}
	}
	cout <<  "end sum: " <<  sum << endl;
	return 0;

}

int gearValue(vector<vector<char>> &map, int i, int j){
	int minH = max(0,i - 1);
	int maxH = min(int(map.size()-1),i + 1);
	int minW = max(0,j - 1);
	int maxW = min(int(map[0].size()),j + 1);
	vector<int> values;

	for (int k = minH; k <= maxH; k ++){
		int m = minW;
		if (isNumber(map[k][m])){
			while(isNumber(map[k][m])){
				m--;
			}
			m++;
		}
		for(int n = m; n <= maxW; n++){
			if(isNumber(map[k][n])){
				string p = "";
				while(isNumber(map[k][n])){
					p += map[k][n];
					n++;
				}
				values.push_back(stoi(p));
			}
		}
	}
	if(2 == values.size()){
		int product = 1;
		for (auto p:values){
			product *= p;
		}
		return product;
	}
	else{
	return 0;
	}
}

bool isNumber(char a){
	return (int(a) > 47 && int(a) < 58);
}

void dispGear(vector<vector<char>> &map, int i, int j){
	int minH = max(0,i - 1);
	int maxH = min(int(map.size()-1),i + 1);
	int minW = max(0,j - 3);
	int maxW = min(int(map[0].size()),j + 3);
	cout << minH << " " << maxH << " " << minW << " " << maxW << endl;
	for (int n = minH; n <= maxH; n++){
		for (int m = minW; m <= maxW; m++){
			cout << map[n][m];
		}
		cout << endl;
	}
	cout << endl;
	return;
}
