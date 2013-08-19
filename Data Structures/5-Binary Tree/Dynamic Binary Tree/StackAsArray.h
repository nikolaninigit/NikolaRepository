// Class for stack data structure
template<class T>
class StackAsArray
{
	private:
		T *array;
		int size;
		int top;

	public:	

		StackAsArray(int vel)
		{
			size=vel;
			top=-1; // empty stack
			array=new T[size];
		}
		
		bool isEmpty()
		{
			return (top== -1);
		}

		int numberOfElements()
		{
			return (top+1);
		}

		~StackAsArray()
		{
			delete []array;
		}

		void push(T el)
		{
			if(size== (top+1))
				throw "Pun je magacin";
			else
			{
				top++;
				array[top]=el;
			}
		}

		T pop()
		{
			if(top==-1)
				throw "Stack is empty";
			else
			{
				T result=array[top];
				top--;
				return result;
			}
		}
		
		T getTop()
		{
			if(top==-1)
				throw "Stack is empty";
			else
				return array[top];
		}
		
		int getsize()
		{
			return size;
		}
};