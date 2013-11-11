// Main class for Queue data structure
#include<iostream.h>
#include "QueueAsArray.h"
void main()
{
	try
	{
		QueueAsArray<int> obj(8); 
		obj.enqueue(1);
		obj.enqueue(2);
		obj.enqueue(3);
		obj.enqueue(4);
		obj.enqueue(5);
		obj.print();

		obj.dequeue();
		obj.dequeue();
		cout<<endl;
		obj.print();
	}
	catch( char *e )
	{
      cout<<e<<endl;
	}
}
