#include <iostream>
using namespace std;

int main(){
	int input_var = 0;

	while(input_var != -1){
		cout << "Enter a number (-1 = quit)" << endl;
		if(!(cin >> input_var)){
			cout << "Please enter number only" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		if(input_var != -1){
			cout << "You entered " << input_var << endl << endl;
		}
	}

	cout << "All done!" << endl;

	return 0;
}