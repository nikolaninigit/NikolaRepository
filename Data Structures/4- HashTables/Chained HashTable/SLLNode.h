// Class for Node of Singly Linked List
template<class t>
class SLLNode
{
   public:
	   t info;
	   SLLNode<t> *next;

	   SLLNode() // constructor
	   {
		   next = NULL;
	   }

	   SLLNode(t vr) // constructor with argument 
	   {
		   info = vr;
		   next = NULL;
	   }
	   
	   SLLNode( t vr , SLLNode<t> *pok ) // constructor with arguments
	   {
		   info = vr;
		   next = pok;
	   }

	   ~SLLNode() // destructor
	   {
	   }

	   t print() // method for printing info value of the node
	   {
		   return info;
	   }

	   bool isEqual(t el) // Method for checking if 'el' is equal to info value of the node
	   {
			return  el == info;
	   }
};