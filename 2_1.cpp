#include <iostream>
#include <fstream>
using namespace std;

int main(){

	string line;
	int cubeMin[3] = {12,13,14}; //red, green and blue maximum possible values
	string color[3] = {"red","green","blue"}; //So we can for loop through the colors
	int sum = 0; //Score

	ifstream infile;
	infile.open("2_1.txt");
	if(!infile){
		cout << "Failed to open\n";
		return 1;
	}
	
	while(!infile.eof()){
		//Read line by line
		getline(infile,line);
		if(0 == line.length()){
			continue;
		}
//		int sets = 1;
		int end = line.find(";"); //location of the first set delimiter
/*		while (end > 0){
			end = line.find(";",end + 1);
			sets++;
		}*/

		int x = line.find(":");
		int game = stoi(line.substr(5,x - 5)); // Integer value of the game number
	
		bool met = true; //Assume the game is possible
		int beg = x; //Beginning of the first set
//		end = line.find(";");
		bool exit = false;

		while(!exit){
			if (0 == beg){
				exit = true;
				continue;
			}
			//Loop through colors
			for(int i = 0; i < 3; i++){
				if(!met){
					continue;
				}
				//Find the integer value for each color in the set
				int nb = line.find(" ",line.find(color[i],beg) - 5);
				if (0 > nb || (end < nb && end != -1)){
					continue;
				}
				int ne = line.find(" ",nb + 1);
				int val = stoi(line.substr(nb + 1, ne - nb - 1));
				//Check the color value against the maximum possible cubes
				if(val > cubeMin[i]){
					met = false;
					exit = true;
					cout << game << " is impossible :" << color[i] << "-" << val << endl;;
					continue;
				}
			}
			//Move to next set
			beg = end + 1;
			end = line.find(";",beg);
		}
		//Tally the score
		if (met){
			sum += game;
		}
	}
	//Print the final score
	cout << "\n\nFinal Sum: " << sum << endl;
	return 0;
}


