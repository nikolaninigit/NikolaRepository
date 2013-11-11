// Template Class for Dequeue - Queue with methods for adding and taking elements both from head and tail
#include<iostream.h>
template<class t>
class DequeueAsArray
{
	public:
		t * niz; // pointer to array
		int size; // maximum size of the queue
		int numOfElements; // number of elements in the deqeuue
		int head; // begining of the dequeue
		int tail; // ending of the dequeue
	
	DequeueAsArray( int n) // constructor 
	{
		size = new t[n];
		numOfElements = 0;
		head = -1;
		tail = -1;
	
	}
	
	~DequeueAsArray() // destructor
	{
		delete [] niz;
		numOfElements = 0;
		head = -1;
		tail = -1;
	}
	
	bool isEmpty(); // checks if dequeue is empty    
	void enqueueTail(t elem); // function for adding elements to the "end-tail" of the Dequeue
	t dequeueTail(); // function for taking elements from the "end-tail" of the Dequeue
	void enqueueHead(t elem); // function for adding elements to the "begining-head" of the Dequeue
	t dequeueHead(); // function for taking elements from the "end-tail" of the Dequeue
};
	template<class t> // checks if dequeue is empty
	bool DequeueAsArray<t>::isEmpty()
	{
	  return ( numOfElements ==0 )
	}
	
	template<class t> // function for adding elements to the "end-tail" of the Dequeue
	void DequeueAsArray<t>::enqueueTail(e elem)
	{
	   if ( numOfElements == size )
		    throw "EXCEPTION-DEQUEUE IS FULL ";
	   
	   tail = tail+1;
	   if ( tail == size )
		   tail ==0;
	
	   niz[tail] = elem;
	
	   if( numOfElements ==0 )
		     head = tail;
	    
	    numOfElements= numOfElements+1;
	}
	
	template<class t> // function for taking elements from the "end-tail" of the Dequeue
	t DequeueAsArray<t>::dequeueTail()
	{
	   if( numOfElements == 0 )
		   throw "EXCEPTION-DEQUEUE IS FULL";
	
	    	t elem = niz[tail];
	    
		tail = tail -1;
		if(tail <0)
			tail = size -1;
	     	numOfElements--;
		return elem;
	}
	
	template<class t> // function for adding elements to the "begining-head" of the Dequeue
	void DequeueAsArray<t>::enqueueHead(t elem)
	{
	    if( numOfElements == size )
			throw "EXCEPTION-DEQUEUE IS EMPTY";
	
		if( numOfElements ==0)
		{ 
			head = 0;
			tail = 0;
		}
		else
		{
	       	  head = head-1;
		   if(head <0)
			   head = size -1;
		}
		niz[head] = elem;
		numOfElements = numOfElements + 1;
	}
