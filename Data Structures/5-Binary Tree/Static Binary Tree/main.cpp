// Class for manipulation with Static Binary Tree
#include<iostream.h>
#include "BSTree.h"
#include "StaticBSTree.h"

void main()
{
	try
	{
		StaticBSTree< int > sobj(28);
		// inserting elements
		sobj.insert(7 , 0);
		sobj.insert(6 , 0);
		sobj.insert(9 , 0);
		sobj.insert(4 , 0);
		sobj.insert(8 , 0);
		sobj.insert(12 , 0);
		sobj.insert(11, 0);
		sobj.insert(15 , 0);
		sobj.insert(7 , 0);

		sobj.printArray();
		cout<<endl;

	/*
		// example - for deleting Leaves
		sobj.deleteLeaves();
        sobj.printArray();
    */
		

    /*
		// example - counting Leaves in Binary Tree
		cout<<sobj.numberOfLeavesRecursive(0)<<endl;
	*/
	
	//  example - Tree moment - getting number of nodes in BInary TRee
	//	cout<<sobj.treeMomentRecursive(0)<<endl;

    // example - NUmber of different Nodes in Binary Tree
    // cout<<sobj.brojRazlargumentNodeoroveStaticki()<<endl;

     // example - Inorder Tree tranversal
     //	sobj.inorder(0);
     // cout<<endl;


     // example - Preorder Tree tranversal
     //	sobj.preorder(0);
	 //	cout<<endl;

	 // example - breadth tranversal of Binary Tree
	 // sobj.breadthTranversal();

	 // Method for counting Leaves in Binary Tree 
	 //	cout<<sobj.countLeaves()<<endl;

	}
	catch( char *izuz )
	{
		cout<<izuz<<endl;
	}

}