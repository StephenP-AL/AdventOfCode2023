#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int isPart(vector<vector<char>>& map, int row, int start, int end);

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
	int sum = 0;
	for(int i = 0; i < map.size(); i++){
		for (int j = 0; j < map[i].size(); j++){
			if (int(map[i][j]) > 47 && int(map[i][j]) < 58){
				int k = j;
				while (int(map[i][k]) > 47 && int(map[i][k]) < 58 && k < map[i].size()){
					k++;
				}
				
				sum += isPart(map, i,j,k);
//				cout << "sum: " << sum << endl;
				j = k;
			}
		}
	}
	cout <<  "end sum: " <<  sum << endl;
	return 0;
}


int isPart(vector<vector<char>> &map, int row, int start, int end){
	int minH = max(0,row - 1);
	int maxH = min(int(map.size()),row + 2);
	int minW = max(0,start - 1);
	int maxW = min(int(map[row].size()),end + 1);

	string part = "";
	for (int i = start ; i < end; i++){
		part += map[row][i];
	}
	int partNo = stoi(part);
	cout << "\npart number: " << part << endl;
	for (int i = minH; i < maxH; i++){
		for (int j = minW; j < maxW; j++){
			if(int(map[i][j]) < 46 || int(map[i][j]) == 47 || int(map[i][j]) > 57 ){
				cout << "Symbol: " << map[i][j] << endl;
				return partNo;
			}
		}
	}
	return 0;
}
