// Class for Queue data structure
template<class T>
class QueueAsArray
{
	public:

		T *data;
		int head;
		int tail;
		int size;
		int numOfElements;

	public:
		QueueAsArray(int vel)
		{
			size=vel;
			numOfElements=0;
			data=new T[size];
			head=tail=-1;
		}
		
		bool isEmpty()
		{
			return (numOfElements==0);
		}
		
		int numberOfElements()
		{
			return numOfElements;
		}
		
		~QueueAsArray()
		{
			delete [] data;
		}

		T getHead() // gets value of element from the begining but doesn't removes it
		{
			if(numOfElements==0)
				throw "Queue is smpty;";
			return data[head];
		}	
		
		void enqueue(T obj) // adding new element to the end of the queue
		{
			if(numOfElements==size)
				throw "Red je pun";
			else
			{
				tail++;
				// checking if it is end of the queue
				if(tail==size)
					tail=0; // if end is reached, set tail to 0
					
				data[tail]=obj;
				if(numOfElements==0) // if there was no elements at the begining
					head=tail;	   
				numOfElements++;
			}
		}

		T dequeue()
		{
			if(numOfElements==0)
				throw "Red je prazan";
			else
			{
				T result=data[head];
				head++;
				
				if(head==size) // when everything is deleted, head becomes 0
					head=0;
			
				numOfElements--;
				
				if(numOfElements==0)
					head=tail=-1; 

				return result;
			}
		}

		void print()
		{
			for(int i=0;i<numOfElements;i++)
				cout<<data[i]<<" ";
		}
};