// Main class for testing Methods of Singly Linked List
#include<iostream.h>
#include "SLList.h"

void main()
{
	SLList<int> obj;

	obj.addToHead(1);
	obj.addToHead(6);
	obj.addToHead(2);
	obj.addToHead(4);
	obj.addToHead(3);
	obj.addToHead(0);
	obj.addToHead(7);
	obj.addToHead(5);

	obj.printAll();
	cout<<endl;
 
	// sortiranje//
	cout<<"After sorting"<<endl;
	obj.insertionSort();
	obj.printAll();
	cout<<endl;

	// Adding to tail //
	obj.addToTail(1234);
        obj.printAll();
}
