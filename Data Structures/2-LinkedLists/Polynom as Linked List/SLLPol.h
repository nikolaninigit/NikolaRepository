// Template class for representing Polynom as a Single Linked List
#include<iostream.h>
#include "SLLNode.h"
template<class t>
class SLLPol
{
  public:
	  SLLNode<t> *head , *tail; 
	  
	  SLLPol() // constructor
	  {
		  head = NULL;
		  tail = NULL;
	  }

	  ~SLLPol() // destructor
	  {
	  }

	  void addToHead( t ex , t kf ); // add element to head pointer of the list

	  void addToTail(t ex , t kf); // add element to tail pointer of the list
       
	  void print(); // method for printing polynom

	  SLLPol<t> * add( SLLPol pol1 , SLLPol pol2 ); // method for summing two polynoms

	  void umetniCvor( SLLNode<t> *cv ); // method for inserting new element of polynom

	  SLLPol<t> *mul(SLLPol<t> pol1 , SLLPol<t> pol2 ); // function for multiplying two polynoms
};

// add element to head pointer of the list
template<class t>
void SLLPol<t>::addToHead(t ex , t kf)
{
   head = new SLLNode<t>( ex , kf, head );
     if( tail == NULL )
		 tail = head;
}

// method for printing polynom
template<class t>
void SLLPol<t>::print()
{
	if( head == NULL)
		  throw "IZUZETAK - print() - LISTA JE PRAZNA";
    
	SLLNode<t> *pom;

	pom = head;

	while( pom != NULL )
	{
		if( pom->koef<0 )
			cout<<"("<<pom->koef<<"*x^"<<pom->exp<<")+  ";
        else
		   cout<<pom->koef<<"*x^"<<pom->exp<<"+  ";

		pom = pom->next;
	}
}

// method for summing two polynoms
template<class t>
SLLPol<t> * SLLPol<t>::add(SLLPol<t> obj1 , SLLPol<t> obj2)
{
 
  SLLPol<t> *rez = new SLLPol<t>;
  
  SLLNode<t> *pom; // from head to tail of list1
  SLLNode<t> *pomobj2; // from head to tail of list2
  t s;

   // for simplicity i suppose that max degree is for obj1
  if( obj1.head->exp >= obj2.head->exp )
  {
      pom = obj1.head;

	  // this elements will be placed in the result for sure
	  while( pom != NULL )
	  {
         s = pom->koef;
		  pomobj2 = obj2.head;

		  while( pomobj2 != NULL )
		  {
			  if( pom->exp == pomobj2->exp )
				  s = s + pomobj2->koef;
			  pomobj2 = pomobj2->next;
		  }
        
		  rez->addToTail(pom->exp , s);

		  pom = pom->next;
	  }
  
	// now I go through second list and if degrees are equal, I add that elements to the sum
	  pomobj2 = obj2.head;

	  while( pomobj2 != NULL )
	  {
		  rez->umetniCvor( pomobj2 );
		  pomobj2 = pomobj2->next;
	  }
  }
  return rez;
}

// Function for inserting Node into 
template<class t>
void SLLPol<t>::umetniCvor(SLLNode<t> *cv)
{
	SLLNode<t> *prev;
	SLLNode<t> *sled;

	SLLNode<t> *novi;

	// if is greather than the first element
   if( cv->exp > head->exp )
   {
	   addToHead(cv->exp , cv->koef);
   }
   else
    // if it is less than the last one
     if( cv->exp < tail->exp )
	 {
		 addToTail( cv->exp , cv->koef );
	 }
	 else
	  //  if list has two elements
	  if( head->next == tail )
	  {
		  novi = new SLLNode<t>( cv->exp, cv->koef);

		  head->next = novi;
		  novi->next = tail;
	  }
	   else
		// if list has more than two elements
	   {
          prev = head;
		  sled = head->next;

		  // I look exponat in the list which is less than one I want to insert
		  while( (sled->exp > cv->exp) && (sled != NULL) )
		  {
			  prev = prev->next;
			  sled=sled->next;
		  }
          
		  // i found the element with lowest degree, but maybe they are the same
		  // if degree is maybe equal to the one I am adding
		  // if it is not, then i make summing
		  if(cv->exp != sled->exp)
		  {    
		     novi = new SLLNode<t>( cv->exp, cv->koef );
          
		     prev->next = novi;
		     novi->next = sled;
		  }
	   
	   }

}


// add element to tail pointer of the list
template<class t>
void SLLPol<t>::addToTail(t ex , t kf)
{
	// if list has only 1 element
   if( head == NULL )
   {
	   addToHead(ex , kf);
   }
   else
	   // if list has more than one element
   {
	   tail->next = new SLLNode<t>(ex , kf);
	   tail = tail->next;
   }
}

// METHOD FOR MULTIPLYING TWO POLYNOMS
template<class t>
SLLPol<t> * SLLPol<t>::mul(SLLPol<t> pol1 , SLLPol<t> pol2)
{
  SLLPol<t> *rez = new SLLPol<t>;

  SLLNode<t> *pom;
  SLLNode<t> *pobj2;
  t s; // for product value
  t p; // for the sum of coeficients

 
  SLLNode<t> *pred; // pointer for going through product list - previous
  SLLNode<t> *sled; // pointer for going through product list - current
  
  SLLNode<t> *novi; // new node which will be added

  pom = pol1.head;

  while( pom != NULL )
  {
     pobj2 = pol2.head;
     
	 while( pobj2 != NULL )
	 {
        s = pom->exp  + pobj2->exp;
		p = pom->koef * pobj2->koef;

		// if result is empty
		if( rez->head == NULL )
			rez->addToTail(s , p);
         else
		  // if product is not empty, this is special case where I add second element
		   if( rez->head == rez->tail )
			   rez->addToTail( s , pom->koef * pobj2->koef  );
		   else
			   // if is less than degree of last element, then add to tail
			   if( s < rez->tail->exp )
				   rez->addToTail(s,p);
           else
		   { // if there are two or more elements
               pred = rez->head;
			   sled = rez->head->next;
               // I go through result to compare degrees or add to the tail 
			     while( (sled != NULL) && ( sled->exp > s  )  )
				{
					pred = pred->next;
					sled = sled->next;
				}
		   
				// if I reached end of the list
		       if( sled == NULL )
				   rez->addToTail(s,p);
                else
					// if I haven't reached the end
					// and degree is equal to that degree
                  if( sled->exp == s )
					  sled->koef = sled->koef+p;
				    else
						// if node needs to be inserted
					//	if( sled->exp < s )
						{
							novi = new SLLNode<t>( s , p );
							pred->next = novi;
							novi->next = sled;
						}
		   }
		 pobj2 = pobj2->next;
	 }
	 pom = pom->next;
  }
  return rez;
}