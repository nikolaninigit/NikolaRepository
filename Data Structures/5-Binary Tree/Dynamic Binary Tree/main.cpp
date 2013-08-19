// Class for Dynamic Binary Tree
#include<iostream.h>
#include "BSTree.h"
#include "StaticBSTree.h"

void main()
{
	try
	{   // Creating Binary Tree Object
		BSTree<int> obj;
		BSTree<int> *obj1 = new BSTree<int> ;

		obj.insert(7);
		obj.insert(6);
		obj.insert(9);
		obj.insert(4);
		obj.insert(8);
		obj.insert(12);
		obj.insert(11);
		obj.insert(15);
		obj.insert(7);

		obj.breadthTranversal();
		cout<<endl;

	/*
		// example - sum of all leaves - recursive
		cout<<obj.sumAllLeavesRecursive( obj.root );
	*/


	/*
		// example - creating Mirror Binary tree
		obj.createMirror(obj1);
        obj1->breadthTranversal();	
        delete obj1;  // da obrisem dinamicki alociran obj1 !!!
	*/		

	/*
      // example - deleting all leaves from Binary Tree   
		obj.deleteAllLeaves();
		obj.breadthTranversal();
	*/
	}
	catch( char *izuz )
	{
		cout<<izuz<<endl;
	}

}