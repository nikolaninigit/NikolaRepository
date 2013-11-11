// Class for representing the "Node" of Singly Linked List
template<class t>
class SLLNode
{
   public:
           t info; // info -> generaly Node value
   	SLLNode<t> *next; // pointer to next node

   public: // Methods
	   // default constructor
    	SLLNode() { next = NULL; }
          
   	SLLNode( t i ) // constructor with arguments
   	{
   	   info = i;
	   next = NULL;
   	}

   	// constructor with arguments
   	SLLNode(t i , SLLNode<t> * n)
   	{
	    info = i;
	    next = n;
   	}

   	// destructor
   	~SLLNode()
   	{
	}

   	// method for getting info value
   	t print()
   	{
  	 	return info;
   	}

	// method for checking if argument is equal to info 'value'
   	bool isEqual(t el)
   	{
   		return (info == el);
   	}
};
