#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;


int main(){

	ifstream infile;
	infile.open("4.txt");
	if (!infile){
		cout << "Failed to open data file\n";
		return 1;
	}
	else{
		cout << "Data file opened\n";
	}
	int sum = 0;
	string line;
	while(!infile.eof()){
		getline(infile,line);
		if (line.length() < 1){
			continue;
		}
		// Set of winning numbers
		set<int> win;
		for (int j = 10; j < 40; j += 3){
			win.insert(stoi(line.substr(j,2)));
		}
		// Set of numbers we have
		set<int> have;
		for (int j = 42; j < line.length(); j += 3){
			have.insert(stoi(line.substr(j,2)));
		}
		// Intersection of win and have
		set<int> match;
		set_intersection(win.begin(),win.end(),have.begin(),have.end(),inserter(match,match.begin()));
		// Score calculation
		int score;
		if (match.size() == 0){
			score = 0;
		}
		else{
			score = 1;
		}
		
		for (int i = match.size(); i > 1; i--){
			score *= 2;
		}
		sum += score;

	}
	cout << "Score: " << sum << endl;

	return 0;
}
