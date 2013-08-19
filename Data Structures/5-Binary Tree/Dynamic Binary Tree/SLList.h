// Class for Single Linked List
#include<iostream.h>
#include "SLLNode.h"

template<class t>
class SLList
{

  public:
	  SLLNode<t> *head , *tail; // pointert to head and tail of the list
	  
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
	  void printAll(); // method for printing

      SLLNode<t> * getHead() // method for returning head element of the list
	  {
		  return head;
	  }

	  SLLNode<t> * getTail() // method for returning tail element of the list
	  {
		  return tail();
	  }

	  t deleteFromHead(); // method for deleting head element of the list
	  void addToTail(t elem); // method for adding new element to the end of the list
	  t deleteFromTail(); // method for deleting elements from the end of the list
      void deleteElem(t el); // method that deletes element 'el' from the list
	  void insertNode( SLLNode<t> cv ); // method for inserting new node into sorted list
	  void bubbleSort(); // method for sorting list as bubble sort algorithm
	  void removeNegatives(SLList<t> *rhs ); // method for getting nodes with negative 'info' values and puts them into second list

      t getHeadEl() // method for returning head element from the list
	  {
         if( head == NULL )
			 throw "Izuzetak getHeadEl() - LISTA JE PRAZNA";
	      
		 return  head->info;
	  }

	  t getNextEl( t el ) // method for getting the next element of 'el' from the list
	  {
		  SLLNode<t> *tmp;

		  tmp = head;

		  while( (tmp != NULL) && !( tmp->isEqual(el) ) )
			  tmp = tmp->next;

		  if (tmp == NULL)
			  throw "Izuzetak 1 - getNextEl() -  NEMA ELEMENTA U LISTI";

		  if( tmp->next == NULL )
			  throw "Izuzetak 2 - getNextEl() -  NEMA ELEMENTA U LISTI";
	  
	       return ( tmp->next->info );
	  }

	  int brojElemenataListe() // method for getting number of elements from the list
	  {
		  int s=0;
		  SLLNode<t> *p = head;

		  while( p!= NULL )
		  {
			  s++;
			  p = p->next;
		  }

		  return s;
	  }

	  bool ifElementIsInList( t el ) // function that checks if some element is in the list
	  {
		  bool postoji = false;
          SLLNode<t> * r ;
		  r = head;

		  while ( r != NULL )
		  {
			  if ( r->isEqual( el ) == true )
				  postoji = true;

			  r= r->next;
		  }

		  return postoji;
	  }
};

	template<class t> // method for adding elements to the begining of the list
	void SLList<t>::addToHead(t elem)
	{
		if(head!=NULL)
		{
		  head=new SLLNode<t>(elem,head);
		}
		  else
		  tail=head=new SLLNode<t>(elem);
	}

	template<class t> // function for printing elements of the list
	void SLList<t>::printAll()
	{
		if( head == NULL )
			  throw "IZUZETAK ZA printAll() - LISTA JE PRAZNA";

		SLLNode<t> *tmp = head;

		while( tmp != NULL )
		{
			cout<<tmp->info<<"   ";
			tmp = tmp->next;
		}
	}

	template<class t> // // method for deleting head element of the list
	t SLList<t>::deleteFromHead()
	{
		if( head == NULL )
			 throw "IZUZETAK deleteFromHead() - LISTA JE PRAZNA";

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
		else  // if list has two elements
		{
			  pom = head;
			  head = head->next;
			  delete pom;
		}

	   return elem;
	}

	template<class t> // method for adding new element to the end of the list
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

	template<class t> // method for deleting elements from the end of the list
	t SLList<t>::deleteFromTail()
	{
		if( head == NULL )
			throw "IZUZETAK deleteFromTail() - LISTA JE PRAZNA";

		t elem = tail->info;

		SLLNode<t> *pom;
		SLLNode<t> * last;

		// if list has only 1 element
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

	template<class t> // method that deletes element 'el' from the list
	void SLList<t>::deleteElem(t elem)
	{
		if ( head == NULL)
			   throw "LISTA JE PRAZNA - IZUZETAK U deleteElem()";

		SLLNode<t> * prev , *sl;

		// if it is first element
		if ( head->info == elem )
			deleteFromHead();
		else
			// if it is last element
			if( tail->info == elem )
				deleteFromTail();
			else
			{ // if is some other element
			   prev = head;
			   sl = head->next;

			   while ( (sl != NULL) && !( sl->isEqual(elem) ) )
			   {
				   prev = prev->next;
				   sl = sl->next;
			   }

			   // in this case I delete element
			   if( sl->isEqual(elem) )
			   {
				   prev->next = sl->next;
				   delete sl;
			   }
			}
	}

	template<class t> // method for inserting new node into sorted list
	void SLList<t>::insertNode(SLLNode<t> cv)
	{
		SLLNode<t> *prev;
		SLLNode<t> *sled;

		SLLNode<t> *novi;

		// if list is empty
		if ( head == NULL )
			 addToHead( cv.info );
		else
			// if it is greather than first element
			if( cv.info >= head->info )
				addToHead(cv.info);
			else
				// if is less than last element
				if ( tail->info >= cv.info )
					addToTail(cv.info);
		 // until I get to element
		else
		{
			prev = head;
			sled = head->next;

			while( sled->info >= cv.info )
			{
				sled = sled->next;
				prev = prev->next; 
			}
			// find where to insert new element
			if( sled != NULL )
			{
			  novi = new SLLNode<t>(cv.info);
			  novi->next = sled;
			  prev->next = novi;
         
			}
		}
	}

	template<class t> // // method for sorting list as bubble sort algorithm
	void SLList<t>::bubbleSort()
	{
		t zam;
		SLLNode<t> *ptail;
		SLLNode<t> *phead;

		// if list is empty
		if( head == NULL )
			throw "IZUZETAK - bubbleSort() - LISTA JE PRAZNA";

		// if list has two elements
		 if( head->next == tail )
		 {
			 if( head->info >= tail->info )
			 {
				 zam = head->info;
				 head->info=tail->info;
				 tail->info = zam;
			 }
		 }
		 else
		  // if list has more than two elements
		 {
			ptail = head->next; 
			while( ptail != NULL )
			{
				phead = head;

				while( phead != ptail && (phead->next != NULL) )
				{
					if( phead->info >= phead->next->info)
					{
						zam = phead->info;
						phead->info = phead->next->info;
						phead->next->info = zam;
					}

					phead = phead->next;
				}
				ptail = ptail->next;
			}

		 }
	}

	template<class t> // method for getting nodes with negative 'info' values and puts them into second list
	void SLList<t>::removeNegatives(SLList<t> *rhs)
	{
		if( head == NULL )
			throw "EXCEPTION - removeNegatives() - List is empty";

		SLLNode<t> *pom;

		SLLNode<t> *pred;
		SLLNode<t> *sled;

		// if list has only 1 element
		if( head->next == tail)
		{
			// if head and tail are less than 0
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
			pred = head;
			sled = head->next;

			while( sled != NULL )
			{
			   if( pred->info <= 0 )
			   {
				   rhs->addToHead(pred->info);
				   pom = pred;
				   sled= sled->next;
				   pred=pred->next;
				   pom->next = NULL;
			   }
			   else
			   {  
				 pred = pred->next;
				 sled = sled->next;
			   }
			}
		}
	}