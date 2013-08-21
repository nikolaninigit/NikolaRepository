// Main class for trying out methods to work with Doubly Linked List
#include<iostream.h>
#include "DLList.h"

void main()
{
	DLList<int> obj;

	obj.addToHead(5);
	obj.addToHead(7);
	obj.addToHead(1);
	obj.addToHead(18);
	obj.addToHead(19);

	obj.printAll();
	cout<<endl;


	obj.addToTail(34);
	obj.printAll();
	cout<<endl;
}