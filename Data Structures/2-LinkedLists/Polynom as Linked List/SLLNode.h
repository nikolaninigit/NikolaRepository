// Node in Singly Linked List represented as a Polynom
template<class t>
class SLLNode
{
     public:
     t exp; // Node exponent
	t koef; // Node Value
	SLLNode<t> *next; // Pointer to next Node
	
	// constructor
	SLLNode()
	{
	next = NULL;
	}
	
	// constructor with arguments
	SLLNode(t ex , t kf)
	{
	   exp = ex;
	   koef = kf;
	   next = NULL;
	}
	
	//constructor with arguments
	SLLNode(t ex , t kf , SLLNode<t> * n)
	{
	exp = ex;
	  koef = kf;
	  next = n;
	}
	
	// destructor
	~SLLNode()
	{
	}
};
