// TESTING METHODS FROM Matrix.h
#include<iostream.h>
#include "Matr.h"
void main()
{
	Matr<double> m(3,4);
	Matr<double> jed;
	double niz[] = {1,2,3,4,5,6,7,8,9,10};
	double niz1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};

	m.cisti(); // set to all '0'
	m.print();

	 cout<<endl<<"PRIMER ZA OPERATOR ="<<endl;

	 jed = m;
	 jed.print();
	 cout<<endl<<"nakon primene metode setAt()"<<endl;
	 jed.setAt(0,2 , 4);
	 jed.print();

	 cout<<endl<<"Nakon smestanja po vrstama"<<endl;
	 jed.setRow(niz1 , 17);
	 jed.print();
}