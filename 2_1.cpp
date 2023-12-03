#include <iostream>
#include <fstream>
using namespace std;

int main(){

	ifstream infile;
	string line;
	int cubeMin[3] = {12,13,14};
	int red = 12;
	int green = 13;
	int blue =14;
	infile.open("2_1.txt");
	int sum = 0;
	if(!infile){
		cout << "Failed to open\n";
		return 1;
	}
	
	while(!infile.eof()){
		getline(infile,line);
		if(0 == line.length()){
			continue;
		}
		int x = line.find(":");
		int game = stoi(line.substr(5,x - 5));
		int sub = 0;
		int set = x;
		int redS;
		int greenS;
		int blueS;
		string color[3] = {"red","green","blue"};
		for(int i = 0; i < 3; i++){
			int beg = line.find(color[i]);


		}
		
		int r = line.find("red");
		int rb = line.find(" ",r - 5);
		int re = line.find(" ", rb + 1);
		int len = re - rb - 1;
		



		int g = line.find("green");
		int b = line.find("blue");



		while (set > 0){
			int f = line.find(";",set);
			if (f > 0){
				sub++;
			}
			set = f + 1;
			int g = line.find(";",set);


		}

		cout << game << " - " << sub << endl;

	}
	return 0;
}


