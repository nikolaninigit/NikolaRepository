// Class for Stack data structure with virtual methods
template<class t>

class Stack
{
	public:
	
	virtual t getTop()    // virtual function for getting from the top
	{
	throw "exception - call virtuAl function";
	};
	
	virtual void push( t elem ) // virtual function for adding elements 
	{
	throw "exception-virtual function call";
	};
	
	virtual t pop() // virtual function for getting elements
	{
	throw "Exception-virtual function call";
	}; 
	
	virtual bool isEmpty() { return true; }; // checking if stack is empty
	virtual int numOfElements() {return 0 ;} ; // returning number of elements from the stack
};
