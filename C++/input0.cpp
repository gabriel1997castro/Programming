#include <iostream>
using namespace std;

int main(){
	int input_var = 0;

	while(input_var != -1){
		cout << "Enter a number (-1 = quit)" << endl;
		if(!(cin >> input_var)){
			cout << "You entered a non-numeric input, exiting..." << endl;
			break;
		}
		if(input_var != -1){
			cout << "You entered " << input_var << endl;
		}
	}

	cout << "All done!" << endl;

	return 0;
}