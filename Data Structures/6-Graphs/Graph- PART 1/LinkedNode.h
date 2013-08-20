// Class for representing Node of the Graph
#include "Edge.h"
#include<iostream.h>

template<class t , class w>
class LinkedNode
{
    public:
		 t node; // info part of the Node
         Edge<t , w> *adj; // pointer to the first in neighbours list
		 LinkedNode<t , w> *next; // pointer to the next node 
		 int status; // very useful- may be used as various marker
		 int distance;

	public:
    LinkedNode() // constructor
	{
       next = NULL;
	   adj = NULL;
	   status = 0;
	  
	}

	LinkedNode(t n) // constructor with arguments
	{
		node = n;
		adj = NULL;
        next = NULL; 
		status = 0;
	}

	LinkedNode( t n , Edge<t , w> *en ) // constructor with arguments
	{
		status = 0;
		node = n;
		adj = en;
		next = NULL;
	}

    // constructor with arguments
	LinkedNode(t n , Edge<t , w> *a , LinkedNode<t , w> * nn , int stat)
	{
		next = nn;
		adj = a;
		node = n;
		status = stat;
	}

	void visit() // Method for printing Node
	{
		cout<<node<<" -> ";
	}
};