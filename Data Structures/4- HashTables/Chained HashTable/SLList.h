// Class for Singly Linked List
#include<iostream.h>
#include "SLLNode.h"
template<class t>
class SLList
{
  public:
	  SLLNode<t> *head , *tail;
	
	  SLList() // constructor 
	  {
		  head = NULL;
		  tail = NULL;
	  }
  
	  ~SLList() // destructor
	  {
	    while (head != NULL)
		  deleteFromHead();
	  }
	  
	  void addToHead(t el); // adding to begining of the list
	  void printAll(); // method for list printing

      SLLNode<t> * getHead() // Method for returning 'head' element of the list
	  {
		  return head;
	  }

	  SLLNode<t> * getTail() // Method for returning 'head' element of the list
	  {
		  return tail();
	  }

	  t deleteFromHead(); // Method for deleting from the head of the list
	  void addToTail(t elem); // Method for adding to the tail of the list
	  t deleteFromTail(); // Method for deleting from the tail of the list
      void deleteElement(t el); // Method for deleting element with value 'el' from the list
	  void addNode( SLLNode<t> argumentNode ); // Method for adding node into sorted list
	  void bubbleSort(); // Method for bubble sorting of the list
	  void getNegatives(SLList<t> *rhs ); // Method that gets negative elements from the list and puts them in second list

      t getHeadEl() // Method for returning head element of the list
	  {
         if( head == NULL )
			 throw "EXCEPTION getHeadEl() - LIST IS EMPTY";
	      
		 return  head->info;
	  }

	  t getNextEl(t el) // Method for returning next node from node with 'info' value el
	  {
		  SLLNode<t> *tmp;
		  tmp = head;

		  while( (tmp != NULL) && !( tmp->isEqual(el) ) )
			  tmp = tmp->next;

		  if (tmp == NULL)
			  throw "EXCEPTION 1 - getNextEl() -  LIST IS EMPTY";

		  if( tmp->next == NULL )
			  throw "EXCEPTION 2 - getNextEl() -  LIST IS EMPTY";
	  
	       return ( tmp->next->info );
	  }
};

	template<class t> // adding to begining of the list
	void SLList<t>::addToHead(t elem)
	{
		if(head!=NULL)
		{
		  head=new SLLNode<t>(elem,head);
		}
		  else
		  tail=head=new SLLNode<t>(elem);
	}

	template<class t> // Method for printing elements of the list
	void SLList<t>::printAll()
	{
		if( head == NULL )
			  throw "EXCEPTION - printAll() - LIST IS EMPTY";

		SLLNode<t> *tmp = head;

		while( tmp != NULL )
		{
			cout<<tmp->info<<"   ";
			tmp = tmp->next;
		}
	}

	template<class t> // Method for deleting elements from begining of the list
	t SLList<t>::deleteFromHead()
	{
		if( head == NULL )
			 throw "EXCEPTION deleteFromHead() - LIST IS EMPTY";

		SLLNode<t> *pom;
		t elem = head->info;

		// if list has only 1 element
		if (head == tail)
		{
			pom = head;
			head = NULL;
			tail = NULL;
			delete pom ;
		}
		else
		// if list has 2 elements
		{
			  pom = head;  
			  head = head->next;
			  delete pom;
		}
	   return elem;
	}

	template<class t> // Method for adding elements to the end of the list
	void SLList<t>::addToTail(t elem)
	{
		// if list is empty
		if( head == NULL )
		{
			head = new SLLNode<t>(elem , head);
			if ( tail == NULL )
				tail = head;
		}
		else
		{	// if list is not empty
			tail->next = new SLLNode<t>(elem , NULL);
			tail = tail->next;
		}
	}

	template<class t> // Method for deleting element from the end of the list
	t SLList<t>::deleteFromTail()
	{
		if( head == NULL )
			throw "EXCEPTION deleteFromTail() - LIST IS EMPTY";

		t elem = tail->info;
		SLLNode<t> *pom;
		SLLNode<t> * last;

		// if List has only 1 element
		if( head == tail)
		{
			pom = head;
			head = NULL;
			tail = NULL;
			delete pom;
		}
		else
		{
			pom = head;
			while( pom->next != tail )
				pom = pom->next;

			last = tail;
			tail = pom;
			tail->next = NULL;
			delete last;
		}
	   return elem;
	}

	template<class t> // Method for deleting Node form the list with info value 'elem'
	void SLList<t>::deleteElement(t elem)
	{
		if ( head == NULL)
			   throw "EXCEPTION - deleteElement() - LIST IS EMPTY";

		SLLNode<t> * prev , *sl;
		// if it is first element
		if ( head->info == elem )
			deleteFromHead();
		else
			// if it is last element
			if( tail->info == elem )
				deleteFromTail();
			else
			{ // not first nor last
			   prev = head;
			   sl = head->next;

			   while ( (sl != NULL) && !( sl->isEqual(elem) ) )
			   {
				   prev = prev->next;
				   sl = sl->next;
			   }
				// delete element
			   if( sl->isEqual(elem) )
			   {
				   prev->next = sl->next;
				   delete sl;
			   }
			}
	}

	template<class t> // Method for inserting new node into sorted list
	void SLList<t>::addNode(SLLNode<t> argumentNode)
	{
		SLLNode<t> *prev;
		SLLNode<t> *nextNode;
		SLLNode<t> *newNode;
		// if list is empty, only adding
		if ( head == NULL )
			 addToHead( argumentNode.info );
		else
			// if it is greather or equal from head node
			if( argumentNode.info >= head->info )
				addToHead(argumentNode.info);
			else
				// if it is less or equal from the last node
				if ( tail->info >= argumentNode.info )
					addToTail(argumentNode.info);
		 // until I get to the element
		else
		{
			prev = head;
			nextNode = head->next;

			while( nextNode->info >= argumentNode.info )
			{
				nextNode = nextNode->next;
				prev = prev->next; 
			}
			// where to insert
			if( nextNode != NULL )
			{
			  newNode = new SLLNode<t>(argumentNode.info);
			  newNode->next = nextNode;
			  prev->next = newNode;
			}
		}
	}

	template<class t> // Method that sorts list in Bubble sort algorithm
	void SLList<t>::bubbleSort()
	{
		t tmpValue;
		SLLNode<t> *ptail;
		SLLNode<t> *phead;

		// if list is empty
		if( head == NULL )
			throw "EXCEPTION - bubbleSort() - LIST IS EMPTY";

		// if list has 2 elements
		 if( head->next == tail )
		 {
			 if( head->info >= tail->info )
			 {
				 tmpValue = head->info;
				 head->info=tail->info;
				 tail->info = tmpValue;
			 }
		 }
		 else // if list has more than two elements
		 {
			ptail = head->next; 
			while( ptail != NULL )
			{
				phead = head;
				while( phead != ptail && (phead->next != NULL) )
				{
					if( phead->info >= phead->next->info)
					{
						tmpValue = phead->info;
						phead->info = phead->next->info;
						phead->next->info = tmpValue;
					}
					phead = phead->next;
				}
				ptail = ptail->next;
			}
		 }
	}

	template<class t> // Method that gets negative elements from the list and puts them in second list
	void SLList<t>::getNegatives(SLList<t> *rhs)
	{
		if( head == NULL )
			throw "EXCEPTION - getNegatives() - LIST IS EMPTY";

		SLLNode<t> *pom;
		SLLNode<t> *previousNode;
		SLLNode<t> *nextNode;

		// if list has only 1 element
		if( head->next == tail)
		{
			// if lirst and last are less than 0
			if( head->info <=0 && tail->info<=0 )
		   {
			   rhs->addToHead(head->info);
			   rhs->addToHead(tail->info);
			   head = NULL;
			   tail = NULL;
		   }
			 else
				 // if first is less than 0
				if( head->info <=0 )
				{
					rhs->addToHead(head->info);
					pom = head;
					head= tail;
					pom->next = NULL;
				}
				else
					// ako je tail <= 0
					if( tail->info <=0 )
					{
						rhs->addToHead(tail->info);
						head->next=NULL;
					}
		}
		else
		{  // if list has more than two elements
			previousNode = head;
			nextNode = head->next;
			while( nextNode != NULL )
			{
			   if( previousNode->info <= 0 )
			   {
				   rhs->addToHead(previousNode->info);
				   pom = previousNode;
				   nextNode= nextNode->next;
				   previousNode=previousNode->next;
				   pom->next = NULL;
			   }
			   else
			   {  
				 previousNode = previousNode->next;
				 nextNode = nextNode->next;
			   }
			}
		}
	}