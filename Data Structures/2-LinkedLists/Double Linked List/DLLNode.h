// Node class for Double Linked List
template<class t>
class DLLNode
{
	public:
    t info;
	DLLNode<t> *prev, *next;

	// default constructor
	DLLNode()
	{
		prev = NULL;
        next = NULL;
	}

	// constructor with arguments-only value
	DLLNode( t el )
	{
       info = el;
	   next = NULL;
	   prev = NULL;
	}
	// constructor with parameters- "value" and
	DLLNode(t el , DLLNode<t> *p , DLLNode<t> *s )
	{
       info = el;
	   prev = p ;
	   next = s;
	}

	// destructor
	~DLLNode()
	{

	}

	//for ptinting
	t print()
	{
		return info;
	}

	// if node value is equal to some value
	bool isEqual( t el )
	{
       return ( el == info );
	}
};