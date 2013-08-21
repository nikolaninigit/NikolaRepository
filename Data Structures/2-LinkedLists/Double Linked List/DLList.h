// Class for Doubly linked list
#include<iostream.h>
#include "DLLNode.h"

template<class t>
class DLList
{
   public:
	   DLLNode<t> *head , *tail;
    
	   DLList() // constructor 
	   {
		   head = NULL;
		   tail = NULL;
	   }
   // function that checks if list is empty
	   bool isEmpty()
	   {
          return ( head == NULL ); 
	   }

	   ~DLList();   // desctructor
	   void printAll();   // desctructor
	   void addToHead( t el ); // function for adding elements to the begining of the list
	   t deleteFromHead(); // function for deleting elements from the begining
	   void addToTail(t el); // function for adding elements to the end of the list
	   t deleteFromTail(); // function for deleting elements from the end of the list

	   // functions for returning "head" and "tail" elements from the list
	   // head
	   DLLNode<t> * getHead()
	   {
		   return head;
	   }
       // tail
	   DLLNode<t> * getTail()
	   {
          return tail;
	   }

};

//functions that prints element from the list
template<class t>
void DLList<t>::printAll()
{
   DLLNode<t> *p = head;

   while( p != NULL )
   {
	   cout<<p->print()<<"   ";
	   p = p->next;

   }
}

//  function for adding elements to the begining of the list
template<class t>
void DLList<t>::addToHead(t el)
{
	// if list is empty
	if( head == NULL )
	{
		head = new DLLNode<t>(el);
		if ( tail == NULL )
			tail = head;
	}
	else  // if list is not empty
	{
       head = new DLLNode<t>(el , NULL , head);
	   head->next->prev = head;
	}
}

// function for deleting elements from the begining
template<class t>
t DLList<t>::deleteFromHead()
{

    // I supose that list is not empty
	t el = head->info;

	DLLNode<t> *tmp = head;

	// if list has only 1 element
	if( head == tail )
	{
       head = NULL;
	   tail = NULL;
	}
   else
   { // if list has more that 1 element
	   
	   head = head->next;
	   head->prev = NULL;
   }

    delete tmp; 
	return el;


}
// destructor
template<class t>
DLList<t>::~DLList()
{
   while ( head != NULL )
	   t tmp = deleteFromHead();
}

// function for deleting elements from the end of the list
template<class t>
t DLList<t>::deleteFromTail()
{
  t el = tail->info;
  DLLNode<t> *tmp = tail;

  // if list has only 1 element
  if ( head == tail )
  {
     head = NULL;
	 tail = NULL;
  }
  else
  //  if list has more than 1 element
  tail = tail->prev;
  tail->next = NULL;

  delete tmp;

  return el;
}

// Function for adding elements to the end of the list
template<class t>
void DLList<t>::addToTail( t el )
{
   // is list is empty
	if( head == NULL )
	{
       head = new DLLNode<t>(el);

	   if ( tail == NULL )
		   tail = head;
	}
	else
	{ // if list has at least one element
		tail->next = new DLLNode<t>(el , NULL , NULL );
		tail->next->prev = tail;
		tail = tail->next;
	}
}