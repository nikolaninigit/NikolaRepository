// Class for representing Graph data Structure
#include<iostream.h>
#include "LinkedNode.h"
#include "QueueAsArray.h"
#define INFINITY -1

template<class t , class w>
class GraphAsList
{
	public:
		LinkedNode<t , w> * start; // pointer to start node of the graph
		int numberOfElements; 

	public:
		GraphAsList() // constructor
		{
			start = NULL;
			numberOfElements = 0;
		}

		~GraphAsList() // destructor
		{
		}

		// Method for inserting new Node in the graph, 
		//initially no connected with any other node
		bool insertNode( t pod ) 
		{
			LinkedNode<t , w> *newNode = new LinkedNode<t , w>( pod , NULL , start , 0  );
			if ( newNode == NULL )
				  return false;

			start = newNode;
			numberOfElements++;
			return true;
		}

        	LinkedNode<t , w> * findexNode(t el) // Method for findexing Node vith value el in the graph
		{	 
		  LinkedNode<t , w> *ptr = start;
		  while( ptr!= NULL && ptr->node!= el )
			  ptr = ptr->next;

		  return ptr;
		}

		bool insertEdge( t a , t b ) // Method for inserting edge between nodes with values 'a' and 'b'
		{
		  LinkedNode<t , w> *pa = findexNode(a);
		  LinkedNode<t , w> *pb = findexNode(b);

		  if ( (pa == NULL) || (pb == NULL) )
			  return false; // if any of the nodes doesn't exist

		  Edge<t , w> *ptr = new Edge<t , w>( pb , pa->adj );

		  if ( ptr == NULL )
			  return false;
		  
		  pa->adj = ptr; 

		  return true;
		}

		Edge<t , w> *findEdge( t a , t b ) // Method for returning Edge between two nodes
		{
		  LinkedNode<t , w> *pa = findexNode(a);
		  LinkedNode<t , w> *pb = findexNode(b);

		  if ( (pa == NULL) || ( pb == NULL ) )
			  return NULL;

		  Edge<t,w> *ptr = pa->adj;

		  while( (ptr != NULL) && ( pb != ptr->dest ) )
			  ptr = ptr->link;

		  return ptr;
		}

		void print() // Method for graph printing
		{
		  LinkedNode<t , w> *ptr = start;

		  while ( ptr != NULL )
		  {
			  cout<<ptr->node<<" -> ";
			  Edge<t , w> *pa = ptr->adj;

			  while ( pa != NULL )
			  {
				  cout<<pa->dest->node<<" | ";
				  pa = pa->link;
			  }

			  cout<<"\r\n";
			  ptr = ptr->next;
		  }
		}

		bool deleteEdge(t a , t b) // Method for deleting edge between nodes with values 'a' and 'b'
		{
			Edge<t,w> *pot = findEdge(a,b);

			if ( pot == NULL )
				  return false;
			
			LinkedNode<t,w> *pa = findexNode(a);

			//  if it is first Node
			if( pa->adj == pot)
			{
				pa->adj = pot->link;
				delete pot;
				return true;
			}
			
			Edge<t,w> *tpot = pa->adj;

			while( tpot->link != pot )
				 tpot = tpot->link;

			// now delete edge
			tpot->link = pot->link;
			delete pot;
			return true;
		}
		
		// Method that deletes all edges in graph to the node 'ln'
		bool deleteEdgeToNode( LinkedNode<t,w> *ln)
		{
			LinkedNode<t,w> *ptr = start;
			while( ptr != NULL )
			{
				Edge<t,w> *pot = ptr->adj;

				while ( (pot != NULL) && ( pot->dest->node != ln->node ) )
				  pot = pot->link;

				// ako ima potrebe, onda brisi
				if ( pot != NULL )
				  deleteEdge( ptr->node , pot->dest->node );
				  
				ptr = ptr->next;
			}
			return true;
		}


		bool deleteNode(t el) // Method that deletes node in graph with value 'el'
		{
			LinkedNode<t,w> *ptr;

			if ( start == NULL )
				return false;

			// ukoliko brisem prvi cvor
			if( start->node == el )
			{
				Edge<t,w> *pot = start->adj;
				Edge<t,w> *tpot;

				while( pot != NULL  )
				{
				  tpot = pot->link;
				  delete pot;
				  pot = tpot;
				}
				start->adj = NULL;
			
				// delete all edges to that node
				deleteEdgeToNode(start);
				ptr = start;

				// start now points to next
				start = ptr->next;
			
				delete ptr;
				numberOfElements--;
				return true;
			}
			else
			{
			   // if it is not first Node
			   ptr = start->next;
			   LinkedNode<t,w> *par = start;

			   // until I get to that node
			   while( (ptr != NULL) && ptr->node != el )
			   { 
				   par = ptr;
				   ptr = ptr->next;
			   }

			   if ( ptr == NULL )
					return false;

			   // rearrange pointers
			   par->next = ptr->next;

			   Edge<t,w> *pot = ptr->adj;
			   Edge<t,w> *tpot;

			   while( pot != NULL )
			   {
				   tpot = pot->link;
				   delete pot;
				   pot = tpot;
			   }
			   ptr->adj = NULL;
			   deleteEdgeToNode(ptr);
			   delete ptr;
			   numberOfElements--;
			}
				return true;
		}

		int breadthTranversal( t a ) // Breadth tranversal of the graph
		{
			int retVal = 0;
			LinkedNode<t,w> *ptr = start;
			QueueAsArray< LinkedNode<t,w> *> que( numberOfElements );

			// labels	
			// 1 Unvisited
			// 2 in working phase
			// 3 Visited

			// set all to unvisited
			while ( ptr != NULL )
			{
				ptr->status = 1;
				ptr = ptr->next;
			}

			// findex node from where tranversal starts
			ptr = findexNode(a);

			if ( ptr == NULL )
			 return 0;

			que.enqueue(ptr);
			// set status to 'in working phase'
			ptr->status = 2; 

			while ( que.isEmpty() == false )
			{
				ptr = que.dequeue();
				ptr->status = 3;

				ptr->visit();
				retVal++;

				Edge<t,w> *pot = ptr->adj;

				// work with all neighbours
				while ( pot != NULL )
				{
					if ( pot->dest->status == 1 )
					{
						pot->dest->status = 2;
						que.enqueue( pot->dest );
					}
					pot = pot->link;
				}
			}
			return retVal;
		}	

		t MaxOutDegree() // Method that findexs Node with maximum outgoing degree
		{
			if ( start == NULL )
				throw "Exception - MaxOutDegree() - No Nodes in the graph";

			LinkedNode<t,w> *ptr = start;
			LinkedNode<t,w> *pom = ptr;
			Edge<t,w> *pot;
			int counter = 0;
			int max = 0;

			while (ptr != NULL)
			{
				 counter = 0;
				 pot = ptr->adj;
				 
				 // count with how many is connected
				 while (pot != NULL)
				 {
					counter++;
					pot = pot->link;
				 }
				 // remember if necessary 
				 if (counter > max)
				 {
					 pom = ptr;
					 max = counter;
				 }
				ptr = ptr->next;
			}
			cout<<max<<endl;
			return pom->node;
		}


		t maxInDegree() // methods that findexs Node with maximum in degrees
		{
			if ( start == NULL )
				throw "EXCEPTION - maxInDegree() - NO NODES IN THE GRAPH";
	
			LinkedNode<t,w> *ptr = start;
			LinkedNode<t,w> *pom;
			LinkedNode<t,w> *ptrPet;
			Edge<t,w> *pot;

			t prom;
			int counter = 0;
			int max = 0;

			while ( ptr != NULL )
			{
				prom = ptr->node;
			    ptrPet = start; 
				counter = 0;
				
				while ( ptrPet != NULL )
				{  
					pot = ptrPet->adj;
					while ( pot != NULL )
					{
						if ( pot->dest->node == prom )
						   counter++;
						
						pot = pot->link;
					}
					ptrPet = ptrPet->next;
				}
				// replace if necessary
				if (counter > max)
				{
					max = counter;
					pom =  ptr;
				}
				ptr = ptr->next;
			}
			cout<<max<<endl;
			return pom->node;
		} 

		t * NodesWithOutDegreeZero() // Method that findexs Nodes with out degree 0
		{
			if ( start == NULL )
				 throw "EXCEPTION - NodesWithOutDegreeZero() - NO NODES IN THE GRAPH";

			t * array = new t[ numberOfElements ];
			int i;

			for ( i=0; i<numberOfElements; i++)
				array[i] = (t) 0;

			LinkedNode<t,w> *ptr = start;
			Edge<t,w> *pot; 
   
			int index = 0;
			while ( ptr != NULL )
			{
				pot = ptr->adj;
		   
			   if ( pot == NULL)
				 array[index] = ptr->node;

				index++;
				ptr = ptr->next;
			}
			return array;
		}

		t * NodesWithInDegreeZero() // Method that return Nodes with in degree Zero
		{
			if ( start == NULL )
				  throw "EXCEPTION - NodesWithInDegreeZero() - NO NODES IN THE GRAPH";
				  
			t * array;
			LinkedNode<t,w> *ptr = start;
			Edge<t,w> *pot;
			array = new t[numberOfElements];

			for ( int i=0; i<numberOfElements; i++ )
				array[i] = (t) 0;
	
			int index = 0;

			// tranverse and if necessary change status field
			while ( ptr != NULL )
			{	  
				pot = ptr->adj;
				while ( pot != NULL )
				{  
					pot->dest->status++;
					pot = pot->link;
				}
				ptr = ptr->next;
			}
			// nodes with zero set into array
			ptr = start;
			while ( ptr != NULL )
			{
				if ( ptr->status == 0 )
					array[index++] = ptr->node;
				ptr = ptr->next;
			}
			return array;
		}

		bool hasStrongConnection() // Method that checks if graph is Strongly connected
		{
			if ( start == NULL )
				throw "EXCEPTION - hasStrongConnection() - NO NODES IN GRAPH";

			int counter = 0;
			LinkedNode<t,w> *ptr = start; 
			int s; 
		
			// breadthTranversal
			while( ptr != NULL )
			{
				s = breadthTranversal(ptr->node);
				if ( s == numberOfElements )
				counter++;
				
				ptr = ptr->next;
			}

			if (counter == numberOfElements)
				return true;
			else
				return false;
		}
};
