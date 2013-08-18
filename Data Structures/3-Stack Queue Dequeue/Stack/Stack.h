// Class for Stack data structure with virtual methods
template<class t>

class Stack
{
	public:
	
	virtual t getTop()    // virtual function for getting from the top
	{
		throw "IZUZETAK - POZIV VIRTUELNE FUNKCIJE KLASE STACK";
	};

    virtual void push( t elem ) // virtual function for adding elements 
	{
      throw "POZIV VIRTUELNE FUNKCIJE";
	};

    virtual t pop() // virtual function for getting elements
	{
		throw "IZUZETAK - pozov virtuelne funkcije";
	}; 

	virtual bool isEmpty() { return true; }; // checking if stack is empty
	virtual int brojElemenata() {return 0 ;} ; // returning number of elements from the stack
};