// Class for HashTable data structure
#include<iostream.h>
#include "SLList.h"
#include <math.h>
#include "HashObject.h"
template< class t , class r >
class HashTable
{
  protected:
	  int length; // length of the array
	  int count; // number of elements in the table
	  SLList< HashObject<t , r> > *array;

  public: 
	  HashTable(int l) // constructor
	  {
		  count = 0;
		  length = l;
		  array = new SLList< HashObject<t , r>  > [ length ];
	  }
	
	  ~HashTable() // destructor
	  {
		  int i;
		  for( i=0; i<length; i++ )
		  {
	     HashObject<t , r> obj;
			 try
			 {
	         obj = array[i].getHeadEl();
				 while( true )
				 {
					 obj.deleteRecord();
					 obj = array[i].getNextEl( obj );
				 }
			 }
			 catch(char *e )
			 {
			 }
		  }
	    delete [] array;
	  }
	
	 int getLength() // Method for returning length of Hash table
	 {
		return length;
	 }
	
	 int f(int i) // primary transformation - for integer
	 {
		return abs(i);
	 }
	 
	 int f( double d ) // primary transformation - for double
	 {
		 if( d=0 )
			 return 0;
		 else
		 {
			 int exponent;
			 double mantissa = frexp( d , &exponent );
			 return( ( 2*fabs(mantissa) -1 ) * ~0U ) ;
		 }
	 }
	
	int f( char *s ) // primary transformation - for char array
	{
	int res = 0;
	   int a = 7;
	   int i;
	   for( i=0; s[i] != 0; i++ )
		   res = res<<a^s[i];
	   return res;
	}
	
	 int g( int i ) // secundary transformation
	 {
		return ( (i+1)%length ) ;
	 }
	
	// funkcija h
	int h( HashObject<t , r> obj )
	{
	int rez = f(  obj.getKey() ) % length;
	  return rez;
	}
	
	void insert( HashObject<t , r> obj ) // Method for inserting into Hash Table
	{
	array[ h(obj) ].addToHead(obj); 
	   count++;
	}
	
	void withdraw( HashObject<t , r> obj ) // method for withdrawing from hast table
	{
	array[ h(obj) ].deleteElement(obj);
	  count--;
	}
	
	
	HashObject<t , r> find( t key ) // Method that finds Hash object with argument 'key'
	{
		 HashObject<t , r> obj;
		 int i = f(key)%length;
		 obj = array[i].getHeadEl();
	
		 while( !( obj.isEqualKey(key) ) )
			 obj = array[i].getNextEl(obj);
	   return obj;
	}
	
	void withdraw( t key ) // Method that deletes Hash Object with argument 'key'
	{
	   HashObject<t , r> obj = find(key);
	   withdraw( obj );
	}
	
	void Display() // Method For displaying Hash Table
	{
	int i;
	  for ( i=0; i<length; i++ )
	  {
	 cout<<"["<<i<<"]";
	 HashObject<t,r> obj;
	 try
		 {
	   obj = array[i].getHeadEl();
		   while( obj.getRecord() != NULL )
		   {
			  obj.Print();
			  obj = array[i].getNextEl( obj );
		   }
		 }
		 catch( char *izuz )
		 {
			 cout<<endl;
		 }
	  }
	}
};
