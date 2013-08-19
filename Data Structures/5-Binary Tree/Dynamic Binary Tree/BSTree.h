// Class for Binary Tree
#include<iostream.h>
#include "BSTNode.h"
#include "StackAsArray.h"
#include "SLList.h"
#include "QueueAsArray.h"
template<class t>

class BSTree
{
	public:
		int numOfElements; // number of elements in Binary Tree
		BSTNode<t> *root; // root node of Binary tree

    public:
		BSTree() // constructor
		{
			root = NULL;
			numOfElements = 0;
		}

		void deleteRoot(BSTNode<t> * p) // Method for deleting root node 
		{
			if ( p != NULL )
			{
				deleteRoot( p->left );
				deleteRoot( p->right );
				delete p;
			}
		}

		~BSTree() // destructor
		{
			deleteRoot( root );
		}

		void insert( t el ) // Method for inserting new element into Binary tree
		{
			BSTNode<t> *p;
			BSTNode<t> *prev;
			p = root;
			prev = NULL;

			while ( p != NULL )
			{
				prev = p;

				if ( p->isLT(el)  )
					p = p->right;
				  else
					p = p->left;  
			}
           // to determine if it is root or deeper
			if ( root == NULL )
				root = new BSTNode<t>(el);
			else
				if( prev->isLT(el) )
					 prev->right = new BSTNode<t>(el);
				else
					 prev->left = new BSTNode<t>(el);

				numOfElements++;
		}

		void inorder( BSTNode<t> *p ) // Inorder Tree Tranversal
		{
			 if( p != NULL )
			{
				inorder(p->left);
				p->visit();
				inorder( p->right );
			}
		}

		void preorder( BSTNode<t> *p)  // Preorder tree tranversal
		{
			 if ( p != NULL )
			 {
				 p->visit();
				 preorder( p->left );
				 preorder( p->right);
			 }
		}
		
		void iterativePreorder() // Iterative Preorder tranversal
		{
			StackAsArray< BSTNode<t> *> stack(numOfElements);
			BSTNode<t> *p = root;
			
			if( p!= NULL )
			{ 
				stack.push(p);
				while( stack.isEmpty() == false )
			   {
				   p = stack.pop();
				   p->visit();

				   if ( p->right != NULL )
					   stack.push( p->right );

				   if( p->left != NULL )
					   stack.push( p->left );
			   }
			}
		}

		int isLeaf( BSTNode<t> *p ) // Method to check if Node is Leaf
		{
			if( (p->left == NULL) && (p->right == NULL ) )
			  return 1;
		    else
			  return 0;
		}

		int countLeaves( BSTNode<t> *p ) // Method for counting Leaf nodes
		{
			int s =0;
			 if( p!= NULL )
			 {
				 s = s + isLeaf(p);
				 s = s + countLeaves( p->left );
				 s = s +  countLeaves( p->right );
			 }
		  return s;
		}

	
		BSTNode<t> * search( BSTNode<t> *p , t el ) // Method that finds node with info value 'el', starting from node 'p'
		{
			while ( p != NULL )
			{
				if ( p->isEQ(el) )
					return p;
				else
					if ( p->isGT(el) )
						 p = p->left;
					else
						 p = p->right;
			}
				return NULL; 
		}

		void breadthTranversal() // Breadth tranversal of Binary Tree
		{
			BSTNode<t> *p = root;
			QueueAsArray< BSTNode<t> *>  queueTmp( numOfElements );

			 if( p != NULL )
			 {
				 queueTmp.enqueue( p );
				 while( queueTmp.isEmpty() == false )
				 {
					 p = queueTmp.dequeue();
					 p->visit();

					 if( p->left != NULL )
						 queueTmp.enqueue( p->left );

					 if( p->right != NULL )
						 queueTmp.enqueue( p->right );
				 }
			 }
		} 
  

		int countDifferentNodes() // Method that counts different nodes in Binary Tree
		{
			int count = 0;
			BSTNode<t> *p = root;
			SLList<t> obj;
			QueueAsArray< BSTNode<t> * > queueTmp(numOfElements);

			if( p != NULL )
			{
				queueTmp.enqueue( p );
				while ( queueTmp.isEmpty() == false )
				{
					p = queueTmp.dequeue();

					if ( obj.postojiUlisti( p->key ) == false )
					{
						// ako ne postoji u listi dodaj ga //
						obj.addToHead( p->key );
						count++;
					}

					if( p->left != NULL )
						queueTmp.enqueue( p->left );

					if( p->right != NULL )
						queueTmp.enqueue( p->right );
				}
			}
			return count;
		}

	
		int countNodes() // Method for counting number of Nodes in Binary Tree
		{
			int s = 0;
			BSTNode<t> *p = root;
			QueueAsArray< BSTNode<t> * > queueTmp( numOfElements );

			if ( p!= NULL )
			{
				queueTmp.enqueue(p);

				while ( queueTmp.isEmpty() == false )
				{
					p = queueTmp.dequeue();
					s++;
				
				  
					if( p->left != NULL )
						queueTmp.enqueue( p->left );

					if ( p->right != NULL )
						queueTmp.enqueue( p->right );
				}
			}
		  return s;
		}

	int numberOfLeaves() // Method for counting number of Leaves
	{
		BSTNode<t> *p = root;
		QueueAsArray< BSTNode<t> * > queueTmp(numOfElements);

		int s = 0;

		if ( p != NULL )
		{
			queueTmp.enqueue(p);

			while ( queueTmp.isEmpty() == false )
			{
              p = queueTmp.dequeue();

			  if ( ( p->left == NULL ) && ( p->right == NULL ) )
				  s++;

			  if ( p->left != NULL )
				  queueTmp.enqueue( p->left );

			  if ( p->right != NULL )
				  queueTmp.enqueue( p->right );
			}
		}
		return s;
	}
	
    // Method that inserts new element in Binary search tree so left child  
	//has greather value than root node, and right child has least value than root node	
	void insertMirror( t el ) 
	{
		BSTNode<t> *p ;
		BSTNode<t> *prev;
		p = root;
		prev = NULL;

		while( p != NULL )
		{
			prev = p;

			if( p->isLT(el) )
				p = p->left;
			else
				p = p->right;
		}
	  if ( root == NULL )
		   root = new BSTNode<t>(el);
      else 
         if ( prev->isLT(el) )
		   prev->left = new BSTNode<t>(el);
	   else
		   prev->right = new BSTNode<t>(el);
	   numOfElements++;
	}
	
	void createMirror( BSTree<t> *mir ) // Method for creating Mirror Binary tree
	{
		BSTNode<t> *p = root;
		QueueAsArray< BSTNode<t> * > queueTmp( numOfElements );

		if ( p != NULL )
		{
			queueTmp.enqueue(p);

			while ( queueTmp.isEmpty() == false )
			{
				p = queueTmp.dequeue();
				mir->insertMirror( p->key );
				
				'if ( p->left != NULL )
					queueTmp.enqueue(p->left)
				if ( p->right != NULL )
					queueTmp.enqueue(p->right);
			}
		}	
	}

	void deleteLeaf( t el ) // Method that deletes leaf node with value 'el'
	{
		BSTNode<t> *p;
		BSTNode<t> *prev;
		int s = 0;
		p = root;
        prev = NULL;

		while ( p != NULL  )
		{
			prev = p;

			if ( p->isLT(el) )
				p = p->right;
			  else
                p = p->left;

			  if ( p != NULL && p->isEQ(el) && ( p->left == NULL ) && ( p->right == NULL ) )
			  {
				  s = 1;
				  if ( prev->right == p )
					  prev->right = NULL;
				    else
                      prev->left = NULL;
					delete p;
					numOfElements--;
					return;
			  }
		}     
		if ( s ==0 )
            throw "izuzetak - deleteLeaf() - NEMA TAJ CVOR";
	}

	void deleteAllLeaves() // Method that deletes all Leaves
	{
		BSTNode<t> *p;
		QueueAsArray< BSTNode<t> *> queueTmp( numOfElements );
		p = root;

		if ( p != NULL )
		{
			queueTmp.enqueue(p);

			while ( queueTmp.isEmpty() == false )
			{
			   p = queueTmp.dequeue();

				if ( (p->left == NULL) && (p->right == NULL ) )
					deleteLeaf( p->key );
                else
				{
				 if( p->left != NULL )
					queueTmp.enqueue( p->left );

				 if( p->right != NULL )
					queueTmp.enqueue( p->right );
				}
			}
		}
	}

	int sumAllLeavesRecursive( BSTNode<t> *poc) // Method for summing all leaves - recursive
	{
		int s = 0;
		if ( poc != NULL )
		{
			if ( (poc->left == NULL) && ( poc->right == NULL ) )
				s = s + poc->key;
			s = s + sumAllLeavesRecursive( poc->left);
			s = s + sumAllLeavesRecursive( poc->right);
		}
		return s;
	}
};  