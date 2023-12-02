#include <iostream>
#include <fstream>
using namespace std;

int main(){

	ifstream infile;
	string line;
	infile.open("1_1.txt");
	int sum = 0;
	if(!infile){
		cout << "Failed to open\n";
		return 1;
	}
	while(!infile.eof()){
		getline(infile,line);
		if(line.length() < 1){
			continue;
		}
		int a = -1;
		int b = -1;
		cout << line << endl;
		for(int i = 0; i < line.length(); i++ ){
			cout << line[i] << "-" << int(line[i]) << "-" << int(line[i]) - 48 << " ";
			if (58 > int(line[i])){
				a = int(line[i]) - 48;
				break;
			}
		}
		cout << endl << "a == " << a << endl;

		for(int i = line.length() - 1; i >= 0 ; i-- ){
			if (58 > int(line[i])){
				b = int(line[i]) - 48;
				break;
			}
		}
		if (a < 0 || b < 0){
			cout << "error\n";
			return 2;
		}
		sum += ((10 * a) + b);
		cout << "Sum: " << sum << endl;
	}
	infile.close();
		
	cout << "\n\nFinal Sum: " << sum << endl;
	return 0;
}
