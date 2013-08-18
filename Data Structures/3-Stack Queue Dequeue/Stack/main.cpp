// Main class for trying methods fot the stack
#include<iostream.h>
#include "StackAsArray.h"
#include <string.h>

#include<stdlib.h>

void main()
{
   try
   {
    
	   StackAsArray<int> obj(10);
	   StackAsArray<int> obj1(10);
	   
	   obj.push(1);
	   obj.push(2);
	   obj.push(3);
	   obj.push(4);
       obj.push(5);
	   obj.push(6);
	   obj.push(7);

	    obj.print();
		cout<<endl;

///////////////////////

  obj.reverse();
  obj.print();
   }
   catch( char *e )
   {
       cout<<e<<endl;
   }

   
}

