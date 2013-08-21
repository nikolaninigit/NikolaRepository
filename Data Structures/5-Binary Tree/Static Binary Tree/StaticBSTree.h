// Class for Static implementation of Binary Tree
// Binary tree is implemented as an array, node is at position [i], left child is at position [2*i+1], right is at position [2*i+2]
#include<iostream.h>
template<class t>

class StaticBSTree
{
   public:
	   t * tree; // pointer to array that represents static memory for Binary Search Tree
	   int numOfElements; // number of elements in the array
	   int maxSize; // maximum size of the array

   public:
    StaticBSTree( int br ) // constructors
	{
		int i;
		maxSize = br;
		tree = new t[maxSize];
		numOfElements = 0;
		// initially, all is set to -1
		for( i=0; i<br; i++)
			tree[i] = -1;
	}

	~StaticBSTree() // destructor
	{
		delete [] tree;
	}

	void insert( t el , int i ) // Method for inserting elements into Binary Tree -> if node is at position i, left child is at 2*i+1, right child at 2*i+2
	{
		if ( numOfElements < maxSize )
		{
			if ( (tree[i] != -1 ) && ( i < maxSize ) )
			{
				if ( tree[i] < el )
					insert( el , 2*i+2 );
				  else
                    insert( el , 2*i+1 ); 
			}
			else
			{
				tree[i] = el;
				numOfElements++;
			}
		}
		else
			throw "Exception insert() - NEMA MESTA VISE ZA UNOS ELEMENATA";
	}

	void printArray() // method for ordinary printing of the array
	{
		int i;

		if ( numOfElements == 0 )
			 throw "Exception printArray() - NEMA ELEMENATA U STABLU";
		for( i=0; i<maxSize; i++ )
			//if( tree[i] != -1 )
				cout<<tree[i]<<" ";
	}

	int countLeaves() // Method for counting number of leaves
	{
		int s = 0;
        int i;
		
		for ( i=0; i< maxSize; i++)
		{
			// for element on [i] and childs are in tree borders and equal to -1 //
			if ( (tree[i] != -1 ) && ( 2*i+1 < maxSize ) && (2*i+2 < maxSize) )
			{
				// if it is leaf, increase s (s++)
               if( (tree[ 2*i+1 ] == -1) && ( tree[2*i+2] == -1 ) )
               s++;
			}
			else
			{
				// if it is individual withoud left and right child, it is leaf
				if ( tree[i] != -1 )
				{
					if ( 2*i+1 >= maxSize )
					{
						if ( 2*i+2 >= maxSize )
						{
							s++;
						}
					} 
				}
				
			}
		}
		return s;
	}

	void breadthTranversal() // BREADTH TRANVERSAL of Binary tree
	{
		QueueAsArray<t> red(numOfElements);
		int i;
		int p;
		i=0;
		while ( i < maxSize )
		{
			if ( tree[i] != -1 )
			{  
					red.enqueue( i );

					while ( red.isEmpty() == false )
					{ 
							p = red.dequeue();
							cout<<tree[p]<<"  ";

						if( 2*p+1<maxSize )
						{ 

						  if( 2*p+2<maxSize )
						  {
							  // if has left child
							 if( tree[2*p+1] != -1)
							 {
								 red.enqueue( 2*p + 1 );
								 
								 // if has right child
								 if ( tree[2*p+2] != -1 )
								 {
									 red.enqueue( 2*p+2 );
									 i = i+2;
								 }
								 else
								 { // if doesn't have right child
								  i = i+2; 
								 }
							 }
							else
							{
								// if doesn't have left child
								if ( tree[2*p+1] == -1 )
								{
									// if has right child
									if( tree[2*p+2] != -1 )
									{
										red.enqueue( 2*p+2 );
										i = i+2;
									}
									else
									{// if doesn't have right child
									   if ( tree[2*p+2] == -1 )
										   i = i+2;
									}
								}
							}
						  }
						} 
					   else
						{  
							  if ( 2*p+1 >= maxSize )
							  {
								  i = i+1;
							  }
						}
					} 
			}
			else
			   i = i+1;
		}  
	}

	void preorder( int i ) // Preorder tranversal
	{
       if( tree[i] != -1 && (i < maxSize) )
	   {
		   cout<<tree[i]<<" ";
		   preorder( 2*i+1 );
		   preorder( 2*i+2 );
	   }
	}

	void inorder( int i ) // Inorder Tranversal
	{
		if( (i < maxSize) && ( tree[i] != -1 ) )
		{
			inorder( 2*i+1 );
			cout<<tree[i]<<"  ";
			inorder(2*i+2);
		}
	}

	int numberOfDifferentNodes() // Method for counting number of different nodes in Binary tree
	{
		SLList<t> l;
		int i;
		int s = 0;

		for( i=0; i<maxSize; i++ )
		{
          if ( tree[i] != -1 )
		  {
               if ( l.ifElementIsInList(tree[i]) == false )
			   {
			     l.addToHead(tree[i]);
		         s++; 
			   }
		  }
		}
		return s;
	}

	int treeMomentRecursive( int i ) // Method for counting number of nodes in the static Binary Tree
	{
		int s=0;  
		if ( (i<maxSize) && (tree[i] != -1 ) )
			{
				s = s+1;
				s= s + treeMomentRecursive( 2*i+1 );
				s= s + treeMomentRecursive( 2*i+2 );
			}
		return s;
	}

	int numberOfLeavesRecursive( int i ) // Method for counting number of leaves- recursive method
	{
		int s = 0;
	   if ( i < maxSize )
	   {
		   if ( tree[i] != -1 )
		   {
			   if ( (tree[2*i+1] == -1) && ( tree[2*i+2] == -1 ) )
				   s = s+1;
			   else
				   s = s + numberOfLeavesRecursive( 2*i+1 ) + numberOfLeavesRecursive( 2*i+2 ) ;	   
		   }
		   else
			   return 0;
	   }
	  return s;
	}

   void deleteLeaves() // Method for deleting leaves in Binary tree
   {
	   int i=0;

	   for( i=0; i<maxSize; i++)
	   {
		   //if it is potential candidate for deleting
		   if ( tree[i] != -1 )
		   {
			   // if childs are out of the array maximum index
			   if (2*i+1 >= maxSize )
				   tree[i] = -1;
			   else
			   {
				   if ( tree[2*i+1] == -1 )
				   {
					   if ( tree[ 2*i+2] == -1 )
						   tree[i] = -1;
				   }
			   }
		   }
	   }
   }
};