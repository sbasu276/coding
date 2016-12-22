//============================================================================
// Name        : practice.cpp
// Author      : Soumen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template <class T>
T sum(T a, T b) {
	return a+b;
}


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int a = 5, b = 6;
	double x = 4.5 , y = 3.4;

	cout << sum(a,b) << endl << sum(x,y);
	return 0;
}
