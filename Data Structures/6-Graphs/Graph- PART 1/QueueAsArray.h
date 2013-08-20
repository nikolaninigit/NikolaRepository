// Class for Queue data Structure
template<class T>
class QueueAsArray
{
	public:
		T *data;
		int head;
		int tail;
		int maxSize;
		int numOfElements;

	public:
		QueueAsArray(int vel) // constructor
		{
			maxSize=vel;
			numOfElements=0;
			data=new T[maxSize];
			head=tail=-1;
		}
		
		bool isEmpty() // Method that checks if queue is empty
		{
			return (numOfElements==0);
		}
		
		int numberOfElements() // Method that returns number of elements
		{
			return numOfElements;
		}
		
		~QueueAsArray() // destructor
		{
			delete [] data;
		}

		T getHead() // get value of element from the start but not remove it from the queue 
		{
			if(numOfElements==0)
				throw "Queue is empty;";
			return data[head];
		}	
		
		void enqueue(T obj)
		{
			if(numOfElements==maxSize)
				throw "Red je pun";
			else
			{
				tail++;
				if(tail==maxSize)
					tail=0;
					
				data[tail]=obj;
				if(numOfElements==0)
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
				
				if(head==maxSize)
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