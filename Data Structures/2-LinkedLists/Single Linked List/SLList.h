// Class for representing Single Linked List
#include<iostream.h>
#include "SLLNode.h"
template<class t>
class SLList
{

	protected:
		SLLNode<t> *head , *tail; // pointers to list head and tail

	public: // METHODS
		// constructor
		SLList()
		{
            head = NULL;
			tail = NULL;
		}

		// destructor
       ~SLList();
	   
	   // Method for checking if list is empty
	   bool isEmpty()
	   {
         return ( head == NULL );
	   }

	   void addToTail(t el); // Method for adding elements to Tail
	   void addToHead(t el); // Method for adding elements to Head
	   t deleteFromHead(); // Method for deleting elements from Head
	   t deleteFromTail(); // Method for deleting elements from Tail
        
	   void printAll(); // Method for printing
      
	   t suma(); // Method for calculating sum of all elements of the Single Linked List
	   void insertionSort(); // Method to sort Single Linked List - Insertion Sort
};

// destructor
template<class t>
SLList<t>::~SLList()
{
	while( !isEmpty() )
	{
        t tmp = deleteFromHead();
	}

}

// Deleting from Head
template<class t>
t SLList<t>::deleteFromHead()
{
    t el = head->info;
	SLLNode<t> *tmp = head;
    
	// if list has only 1 element
	if( head == tail )
	{
        head = NULL;
		tail = NULL;
	}
   else
       head = head->next;

    delete tmp;
	return el;
}

// Adding to head
template<class t>
void SLList<t>::addToHead(t el)
{
   head = new SLLNode<t>( el, head ); // new Head now points to old Head

   if( tail == NULL )  
	    tail = head;    
}

// method for printing
template<class t>
void SLList<t>::printAll()
{
	for( SLLNode<t> *tmp = head; tmp != NULL; tmp = tmp->next )
		cout<<tmp->print()<<"  ";
}

// Adding to Tail
template<class t>
void SLList<t>::addToTail(t el)
{
	if ( isEmpty() )
		head = tail = new SLLNode<t> (el );
	else
	{
         tail->next = new SLLNode<t>( el );
		 tail= tail->next;
	} 
}

// Deleting from Tail
template<class t>
t SLList<t>::deleteFromTail()
{
   t el = tail->info;

   SLLNode<t> * zadnji = tail;

   if ( head == tail )
   {
	   head = tail = NULL;
   }
   else
   {
     SLLNode<t> *tmp;
	 tmp = head;
	   
	    while( tmp->next != tail )
			tmp = tmp->next;

		tail = tmp;
		tail->next = NULL;
   }


   delete zadnji;
   return el;
}

//Method for calculating sum of all elements of the Single Linked List
template<class t>
t SLList<t>::suma()
{
   t s = 0;

   SLLNode<t> *tmp;

     for( tmp=head; tmp->next!=NULL; tmp = tmp->next )
		 s = s + tmp->info;

   return s;
}

// Method to sort Single Linked List - Insertion Sort
template<class t>
void SLList<t>::insertionSort()
{
	SLLNode<t> *ispredI = head->next->next; // pretpostavimo da ima barem 2 elementa u listi

	while( ispredI != NULL )
	{
		SLLNode<t> *tmp = head;


		while( tmp != ispredI )
		{
			if( tmp->info > ispredI->info )
			{
				t pom = tmp->info;
				tmp->info = ispredI->info;
				ispredI->info = pom;
			}

			tmp=tmp->next;
		}

		ispredI= ispredI->next;
	}
}