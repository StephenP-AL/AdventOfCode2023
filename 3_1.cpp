#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
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
//		cout << line << endl;
		for(int i = 0; i < line.length(); i++){
			seg.push_back(line[i]);
		}
		map.push_back(seg);
	/*	for(auto i:seg){
			if(int(i) < 46 || int(i) == 47 || int(i) > 57 ){
				cout << i;
			}
		}
		cout << endl;*/
	}
	for(auto i:map){
		for(auto j:i){
			cout << j;
		}
		cout << endl;
	}
	return 0;
}
