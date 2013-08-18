// Class for Queue data structure
#include<iostream.h>
#include "Queue.h"

template<class t>
class QueueAsArray : public Queue<t>
{
	protected:
		t *niz; // * pointer to the queue
		int head; // start of the queue
		int tail; // end of the queue
		int size; // max size of the queue
		int numElements; // number of elements in the queue

	public:
		
		QueueAsArray( int n ) // constructor
		{
          size = n;
		  niz = new t[size];
		  head = -1;
		  tail = -1;
		  numElements = 0;
		}

		~QueueAsArray() // destructor
		{
           delete[] niz;
		   head = -1;
		   tail = -1;
		   numElements = 0;
           size = 0;
		}

    bool isEmpty(); // method that checks if queue is empty
	void enqueue(t elem); // method for adding elements to "end-tail" of the queue
	t dequeue(); // method for taking elements from the "start-head" of the queue
	t getHead(); // method for returning value of the first ("head") element in the queue
	void print(); // method for printing queue
};

template<class t> // method that checks if queue is empty
bool QueueAsArray<t>::isEmpty()
{
	return ( numElements ==0 );
}

template<class t>
void QueueAsArray<t>::enqueue(t elem) // method for adding elements to "end-tail" of the queue
{
   // first check if qeuue is empty
	if( numElements == size )
		throw "IZUZETAK-RED JE PUN-NEMA VISE MESTA";

	// set tail to zero and put first element into the queue
     tail = tail+1;

	  if ( tail == size )
           tail = 0;
	 
	  niz[tail] = elem;
     
	 if( numElements== 0 ) 
		 head = tail;
	 
	 numElements++;
}

template<class t> // method for taking elements from the "start-head" of the queue
t QueueAsArray<t>::dequeue() 
{
	if ( numElements == 0 )
		throw "RED JE PRAZAN";

   t result = niz[head];
   
   head = head+1;
   if ( head == size ) 
	   head =0;

   numElements--;

   if ( numElements ==0 ) 
   {
	   head = -1;
	   tail = -1;
   }
    
   return result;
}

template<class t> // method for returning value of the first ("head") element in the queue
t QueueAsArray<t>::getHead()
{
   if( numElements ==0 )
	   throw "NE MOZE DA SE PROCITA ELEMENT JER JE RED PRAZAN";
   t elem = niz[ head ];

   return elem;
}

template<class t> // method for printing queue
void QueueAsArray<t>::print()
{
	for ( int i=0; i<numElements; i++)
		cout<<niz[i]<<"  ";

	cout<<endl;
}