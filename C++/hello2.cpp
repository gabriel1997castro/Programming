#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int i, j;

	cout << setiosflags(ios::left);
	for(i=0; i<3; i++){
		for(j=0; j<3 ; j++){
			cout << setw(30) << "c++";
		}
		cout << endl;
	}
	return 0;
}