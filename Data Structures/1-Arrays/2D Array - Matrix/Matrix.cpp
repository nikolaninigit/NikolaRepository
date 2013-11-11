// TESTING METHODS FROM Matrix.h
#include<iostream.h>
#include "Matr.h"
void main()
{
	Matr<double> m(3,4);
	Matr<double> m1;
	double array[] = {1,2,3,4,5,6,7,8,9,10};
	double array1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};

	m.clear(); // set to all '0'
	m.print();

	cout<<endl<<"EXAMPLE FOR OPERATOR ="<<endl;
	
	m1 = m;
	m1.print();
	cout<<endl<<"After method setAt()"<<endl;
	m1.setAt(0,2 , 4);
	m1.print();
	
	cout<<endl<<"After inserting by rows"<<endl;
	m1.setRow(array1 , 17);
	m1.print();
}
