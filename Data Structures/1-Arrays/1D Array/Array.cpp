// EXAMPLE OF METHODS DEFINED IN Array.h
#include "Array.h"
#include <iostream.h>
void main()
{
	Array<int> obj(5,5);
	try
	{ // inserting elements into array
      obj.insert(3,9);
	obj.insert(2,8);
	obj.insert(1,7);
	obj.insert(0,6);
	obj.insert(-1,5);
	
    // creating another object and trying out functions	
	Array<int> obj1(10,5);
	obj1=obj;
	obj.print();
	
	cout<<obj[5]<<endl;
	cout<<obj[6]<<endl;
	cout<<obj[7]<<endl;
	cout<<obj[8]<<endl;
	obj1.print(); // printing array
	obj1.bubble(); // bubble sort
	obj1.print(); // printing array
	cout<<obj.getBase()<<endl;
	obj.setBase(10);
	cout<<obj.getBase()<<endl;
	cout<<"Array has size "<<obj.getLength()<<endl;
	
	Array<int> obj2(6); // trying for the second array
	obj2.insert(3,0);
	obj2.insert(7,1);
	obj2.insert(3,5);
	obj2.insert(4,3);
	obj2.insert(2,2);
	
	// trying out function for the first derivative
	cout<<"Polynom: ";
	obj2.print();
	int stepen=2;
	Array<int> obj3(6);
	obj3.nThDerivative(obj2,stepen);
	cout<<stepen<<". nThDerivative:";
	obj3.print();
	
	/*Array<int> obj4(6);
	obj4=obj2.nThDerivative(1);
	obj4.print();*/
	}
	catch(char* e)
	{
		cout<<e<<endl;
	}
	
}

