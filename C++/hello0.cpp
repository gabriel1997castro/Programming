// hello0.cpp : Gabriel Guimarães Almeida de Castro
#include <iostream>
// we need the following include for setw() in some c++ implementations like print it in a field of 17 spaces

#include <iomanip>

using namespace std;

int main(){
	int i, j;
	// set up cout to right-align
	cout <<  setiosflags(ios::left);
	for(i=0; i<6;i++){
		for(j=0; j<4; j++)
			// setw(int) sets the column width
			cout << setw(17) << "Hello World!";
    // this  next line is a part of the first for loop
    // and causes the new line
		cout << endl;
	}
	return 0;
}