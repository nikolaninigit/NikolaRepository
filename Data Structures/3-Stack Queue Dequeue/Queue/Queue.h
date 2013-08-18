// Template class for Queue data structure with some virtual methods
template<class t>
class Queue
{
	public:
	
 	virtual t getHead() // for taking elements from the start of the queue
	{
		throw "IZUZETAK U POZIVU VIRTUELNE FUNKCIJE";
	}; 
      
	virtual void enqueue( t elem ) // for adding elelemnt to the queue
	{
		throw "IZUZETAK - VIRTUELNI POZIV"; 	  
	}; 

  	virtual t dequeue() // for taking elements from  the end of the queue
	{
       throw "IZUZETAK - VIRTUELNI POZIV";
	};

	virtual bool isEmpty() // checks if queue is empty
	{
      throw "POZIV VIRTUELNE FUNKCIJE";
	};
};