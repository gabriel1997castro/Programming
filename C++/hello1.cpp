//hello1.c: Gabriel Guimarães Almeida de Castro
//This program will show 'I am beautiful' 5 times
//a line and 100 lineas using 20 spaces left-aligned for each 
//'I am beautiful'
#include <iostream>
#include <iomanip>

using namespace std;
int main(){
	int i, j;
	cout << setiosflags(ios::left);
	for(i=0; i<100; i++){
		for(j=0; j<5; j++){
			cout << setw(20) << "I am beautiful";
		}
		cout << endl;
	}
	return 0;
}