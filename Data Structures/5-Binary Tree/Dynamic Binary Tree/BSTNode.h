// Class for Dynamic Binary tree
#include<iostream.h>
template<class t>

class BSTNode
{
	public:
		t key; // info part of the node
        BSTNode<t> *left , *right; // pointers to left and right child

	public:
		BSTNode() // constructor
		{
			left = NULL;
			right = NULL;
		}

		BSTNode( t el )
		{
			key = el;
			left = NULL;
			right = NULL;
		}

		BSTNode( t el , BSTNode<t> *l , BSTNode<t> *r )
		{
			key = el;
			left = l ;
			right = r;
		}
		
		~BSTNode() // destructor
		{
		}
		
		bool isEQ(t el) // method that checks if value is equal to info value of the node
		{
			return ( key == el  );
		}

		bool isGT( t el ) // method that checks if value is greather than info value of the node
		{
			if ( key > el )
				return true;
			else
				return false;
		}

		bool isLT(t el) // method that checks if value is less than info value of the node
		{
			if ( key < el )
				return true;
			else
				return false;
		}

		void setKey( t el ) // Method that sets info value of the node
		{
			key = el;
		}

		t getKey() // method that returns info value of the node
		{
			return key;
		}

		void visit() // method for printing
		{
			cout<<key<<"  ";
		}
};