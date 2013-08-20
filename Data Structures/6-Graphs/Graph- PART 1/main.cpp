// Main class for testing methods for graph manipulation
#include<iostream.h>
#include "GraphAsList.h"
void main()
{
  try
  {
	GraphAsList<int , int> obj;
	LinkedNode<int , int> *ln = new LinkedNode<int,int>(3); 

	// inserting nodes
	obj.insertNode(1);
	obj.insertNode(2);
	obj.insertNode(3);
	obj.insertNode(4);
	obj.insertNode(5);

	// inserting edges
	obj.insertEdge(1,2);
	obj.insertEdge(1,3);
	obj.insertEdge(2,3);
	obj.insertEdge(2,1);
	obj.insertEdge(2,4);
	obj.insertEdge(1,4);
	obj.insertEdge(3,5);
	obj.insertEdge(2,5);
	obj.insertEdge(5,4);

	// printing
	obj.print();
	cout<<endl;
	cout<<endl;

    // breadth tranversal
	int s =  obj.breadthTranversal(1);
  
	// example - finds node with max out degree
	// obj.MaxOutDegree();
  

	// example - finds node with max in degree
	//obj.maxInDegree();

	/*
	// example - finds all nodes with out degree equal zero
    int *n = obj.NodesWithOutDegreeZero();
    for ( int i=0; i<obj.brojEl; i++ )
		if ( n[i] != 0 )
			cout<<n[i]<<"  ";
		cout<<endl;
	*/  
	
	/*
	// example - finds nodes with in degree zero and prints them
	//int *n = obj.NodesWithInDegreeZero(); 
	for ( int i=0; i<obj.brojEl; i++ )
		if ( n[i] != 0 )
			cout<<n[i]<<"  ";
		cout<<endl;
	*/

	/*
	// example - checks if graph has strong connection
	bool p = obj.hasStrongConnection();

	if ( p == true )
		cout<<"jeste"<<endl;
	else
		cout<<"nije"<<endl;    
	*/
  }
  catch ( char *izuz )
  {
	  cout<<izuz<<endl;
  }
}