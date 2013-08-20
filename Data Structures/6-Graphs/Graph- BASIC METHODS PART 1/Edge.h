// Class for Edge of the graph
#include<iostream.h>

template<class t , class w> class LinkedNode;
template<class t , class w>

class Edge
{
   public:
	   LinkedNode<t , w> *dest; // pointer to the Node with who this Node is connected
	   Edge<t , w> *link; // pointer to the next edge
	   w weight; // weight of the edge
 
   public:
	   Edge() // constructor
	   {
		   dest = NULL;
		   link = NULL;
	   }
	   // constructor with arguments
	   Edge( LinkedNode<t , w> *ln , Edge<t , w> *en )
	   {
		   dest = ln;
		   link = en;
	   }
};