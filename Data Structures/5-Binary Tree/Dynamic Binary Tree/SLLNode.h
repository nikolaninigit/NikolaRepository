// Class Node of Single linked List
template<class t>
class SLLNode
{
   public:
	   t info; // info part of the node
	   SLLNode<t> *next; // pointer to next Node
 
	   SLLNode() // constructor
	   {
		   next = NULL;
	   }
      
	   SLLNode( t vr ) // constructor with arguments
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
   
		t print() // method for printing
	   {
		   return info;
	   }

	   bool isEqual(t el) // method that checks if value is equal
	   {
		  return  (el == info);
	   }
};