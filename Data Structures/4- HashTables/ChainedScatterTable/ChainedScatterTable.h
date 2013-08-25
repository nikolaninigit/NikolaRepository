// class for modeling Chained Scatter table
#include<iostream.h>
#include "HashTable.h"
#include "ChainedScatterObject.h"
template< class t , class r >
class ChainedScatterTable : public HashTable<t , r>
{
   public:
	   ChainedScatterObject<t , r> *array;
   public:
		ChainedScatterTable(int len) // constructor
		{
			 count = 0;
			 length = len;
			 array = new ChainedScatterObject<t , r> [length];
			 int i; 
			 for( i=0; i<len; i++ )
			 {
				 array[i] = ChainedScatterObject<t , r>();
				 array[i].free = true;
				 array[i].next = -1;
			 }
		}

		~ChainedScatterTable() // destructor
		{
			 int i;

			 for ( i=0; i<length; i++ )
				 array[i].deleteRecord();

			 delete [] array;
		}
		
		// Method for inserting ChainedScatterObject into ChainedScatterTable
		void insert(ChainedScatterObject<t , r> obj )
		{
			 int probe;
			 int tail;
			 if ( count == getLength() )
				 throw " EXCEPTION - insert() - Error in Insert Method";
			 probe = h( obj );
			 
			 if( array[probe].free != true  )
			 {
					 while( array[probe].next != -1 ) // get to the elelemnt that pointes to yhe last one
						 probe = array[probe].next;
						 tail = probe;
						 
						 probe = g(probe); //secondary transformation

						 while( ( array[probe].free != true  )   &&  (probe != tail)  )
							   probe = g(probe);
					   if( probe == tail )
							throw "EXCEPTION - insert( ChainedScatterObject<t , r> obj ) - Bad Secondary transformation";
					   array[tail].next = probe;	 
			 }
			array[probe] = obj;
			array[probe].next = -1;
			array[probe].free = false;

			count++; // increase number of elements
		}
  
		ChainedScatterObject<t , r> find(t key) // Finding element with key value 'key'
		{
			 int probe = f(key) % length;
			 while( probe != -1 )
			 {
				if( array[probe].isEqualKey(key) )
					return array[probe];
				probe = array[probe].next;
			 }

			 if( probe == -1 && array[probe].isEqualKey(key) )
				 return array[probe];
			 else
				 throw "EXCEPTION - find(t key) - No element with that key";
		}

 
		void withdraw( t key ) // Method for deleting element with key value 'key'
		{
			 if ( count == 0 )
				  throw "EXCEPTION - withdraw( t key ) - No elements for deleting";

			 int prev = -1;
			 int probe = f(key)%length;
			 
			 //  get to certain element
			 while( probe != -1 && (array[probe].isEqualKey(key) == false) )
			 {
				 prev = probe;
				 probe = array[probe].next;
			 }

			 // if no element with that key
			 if ( probe == -1 )
				throw "EXCEPTION - Withdraw() - No element with that key";

			 if( prev != -1 )
			 {
				// it is not first element
				 array[prev].next = array[probe].next;
				 array[probe].deleteRecord();
				 array[probe].free = true;
			 }
			 else
			 {
			   // if it is first and only element
				 if( array[probe]. next == -1 )
				 {
					 array[probe].free = true;
					 array[probe].deleteRecord();
				 }
				else
				{
					// if has synonyms
					int nextEl = array[probe].next;
					array[probe].deleteRecord();
					array[probe] = array[nextEl];
					array[probe].next = array[nextEl].next;

					array[nextEl] =  ChainedScatterObject<t,r>();
					array[nextEl].free = true;
				}
			 }
			 count--;
		}
  
		void display() // Method for Displaying elements
		{
			  int i;
			  for ( i=0; i< length; i++)
			  {
				 if (array[i].free == false )
				 {
				 cout<<"[ "<<i<<" ] ";
				 array[i].print();
				 cout<<array[i].next<<endl;
				 }
				 else
					 cout<<"[ "<<i<<" ]"<<endl;
			  }
		}
};