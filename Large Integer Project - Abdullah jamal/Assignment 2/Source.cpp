#include<iostream>
#include <string>
#include"MyLargeInt.h"
using namespace std;

void checkCopyCons(LargeInteger L)
{
	L.write(cout);
}

int main()
{
	LargeInteger L1(10), L2(10), L3(10);
	L1.read(cin);
	L2.read(cin);

	L3 = L1 + L2;
	L1.write(cout);
	cout << " + ";
	L2.write(cout);
	cout << " = ";
	L3.write(cout);
	cout << endl;
	cout << endl;


	L3 = L1 - L2;
	L1.write(cout); 
	cout << " - ";
	L2.write(cout); 
	cout << " = ";
	L3.write(cout);
	cout << endl;
	cout << endl;


	L3 = L1 * L2;
	L1.write(cout);
	cout << " * ";
	L2.write(cout);
	cout << " = ";
	L3.write(cout);
	cout << endl;
	cout << endl;
	if (L1 == L2) cout << "equal" << endl;
	else if (L1 < L2) cout << "less" << endl;
	else cout << "greater" << endl;
	checkCopyCons(L1);
	
	



}