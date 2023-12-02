#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){

	vector<string> nums{"zero","one","two","three","four","five","six","seven","eight","nine"};
	ifstream infile;
	string line;
//	infile.open("test.txt");
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
//		cout << line << endl;
		for(int i = 0; i < line.length(); i++ ){
//			cout << line[i] << "-" << int(line[i]) << "-" << int(line[i]) - 48 << " ";
			if (58 > int(line[i])){
				a = int(line[i]) - 48;
				for(int j = 0; j < 10; j++){
					int f = line.find(nums[j]);
					if (f < 0){
						continue;
					}
					if (f < i){
						a = j;
						i = f;
					}

				}
				break;
			}
		}

		for(int i = line.length() - 1; i >= 0 ; i-- ){
			if (58 > int(line[i])){
				b = int(line[i]) - 48;
				for(int j = line.length() - 1; j > i; j--){
					for (int k = 0; k < 10; k++){
						int f = line.find(nums[k],j);
						if (f < 0){
							continue;
						}
						if(f > i){
							b = k;
							i = f;
							break;
						}
					}
					
				}
				
				break;
			}
		}
		if (a < 0 || b < 0){
			cout << "error\n";
			return 2;
		}
		cout << line << " -- value: " <<  a << b << endl;
		sum += ((10 * a) + b);
//		cout << "Sum: " << sum << endl;
	}
	infile.close();
		
	cout << "\n\nFinal Sum: " << sum << endl;
	return 0;
}
