// Template class for umplementing methods for manipulation with Stack
#include<iostream.h>
#include "Stack.h"
#include <string.h>

	template<class t>
	class StackAsArray : public Stack<t>
	{
	   protected:
		   t *niz; // * pointer to array
		   int size; // size of the stack
		   int top; // top of the stack
	
	   public:
		   StackAsArray() // default constructor
		   {
	         size = 0; 
	         niz = 0;
			 top = -1;
		   }
		   
		   StackAsArray( int n ) // constructor with parameters
		   {
	          size = n;
			  niz = new t[n];
	
			  top = -1;
		   }
	  
		   int getSize() // returning size of the stack
		  {
				return size;
		  }
	
		   ~StackAsArray() // destructor
		   {
	          delete [] niz;
			  top = -1;
			  size = 0;
		   }
	
		 bool isEmpty(); 
	     int numOfElements(); // method that returns number of elements
		 void print(); // method for printing
		 void push( t elem ); // PUSH -> adding elements to stack
		 t pop(); // POP -> taking element from the top of the stack
		 t getTop(); // method that returns value of element from the top of the stack but not POP
		 StackAsArray<t> & operator=( StackAsArray<t> &rhs ); // operator =
		 bool checkBrackets( char *s ); // method to check if brackets are valid, e.g. (2+(2*7)) is valid, and 2*(7+*5( is not valid
		 void smestiBroj( char *s );  // method for summing two alrge numbers
		 StackAsArray<t> * saberi( StackAsArray<t>  st2); // method that sums two large numbers
	     void reverse(); // method that reverses order of elements in the stack
	};
	
	template<class t> // // method that checks if stack is empty
	bool StackAsArray<t>::isEmpty()
	{
	    return ( top == -1 );
	} 
	
	template<class t> // method that returns number of elements
	int StackAsArray<t>::numOfElements()
	{
	   return (top+1);
	}
	
	template<class t> // method for printing
	void StackAsArray<t>::print()
	{
	   int i;
	   
	   if ( isEmpty() )
		   throw "IZUZETAK - Magacin je prazan";
	   else
	   {
	      for ( i = top; i>=0; i--)
			  cout<<niz[i]<<" "; 
	   }
	}
	
	template<class t> // PUSH -> adding elements to stack
	void StackAsArray<t>::push(t elem)
	{
	   if( top >= size - 1 )
		   throw "IZUZETAK - Magacin je pun";
		  
		   else
	   {
	      top = top + 1;
		  niz[top] = elem;
	   }
	
	}
	
	template<class t>  // POP -> taking element from the top of the stack
	t StackAsArray<t>::pop()
	{
		t pom;
	
	   if ( isEmpty() )
		   throw "IZUZETAK - NE MOZE POP U PRAZNOM MAGACINU";
	     else
	   {
	     pom = niz[top];
		 top = top -1;
	     return pom;
	   }
	
	}
	
	template<class t> // method that returns value of element from the top of the stack but not POP
	t StackAsArray<t>::getTop()
	{ 
	   int pom;
	
	   if ( isEmpty() )
		   throw "IZUZETAK - STEK JE PRAZAN";
	     else
		 {
	       pom = niz[top];
		   return pom;
		 }
	}
	
	template<class t> // method to check if brackets are valid, e.g. (2+(2*7)) is valid, and 2*(7+*5( is not valid
	bool StackAsArray<t>::checkBrackets(char *s)
	{
		int i=0;
	
		while ( i < strlen(s) )
		{
			if ( s[i] == '(' )
				push( s[i] );
	
			if ( s[i] ==')' )
				pop();
	
			i = i+1;
		}
		
		if ( isEmpty() )
			return true;
		  else
			  return false;
	
	}
	
	template<class t> // method that sums two large numbers
	void StackAsArray<t>::smestiBroj(char *s)
	{
		int i=0;
		while ( i<strlen(s) )
		{
	       push( s[i] -'0');
	
	      i = i+1;
		}
	
	}
	
	template<class t> // operator =
	StackAsArray<t> & StackAsArray<t>::operator=(StackAsArray<t> &rhs )
	{
		int i;
	
		size = rhs.size;
	    top =  rhs.top;
	    delete [] niz;
	
	   niz = new t[ size ];
	
		for ( i=0; i<size; i++ )
			niz[i] = rhs.niz[i];
	
		return *this;
	
	}
	
	template<class t> // method that sums two large numbers
	StackAsArray<t> * StackAsArray<t>::saberi(  StackAsArray<t>  st2 )
	{
	  // assum that first number has more digits
	   StackAsArray<t> *rez = new StackAsArray(size);
	
	   int pom;
	   int cifra = 0;
	   int prenos = 0;
	   int vr;
	
	   int b1 , b2;
	
	   // dok se ne isprazni jedan od stekova
	   while( (top !=-1 ) && ( st2.top != -1 )  )
	   {
	      b1 = pop();
		  b2 = st2.pop();
		  pom = b1+b2 + prenos;
	      
		  cifra = pom%10;
		  prenos = pom/10;
	
	      rez->push(cifra);
	   }
	
	   if( top == -1 )
	   {
	      while ( st2.top !=-1 )
		  {
	        vr = st2.pop();
			rez->push(vr);
		  }
	   }
	  else
	    if( st2.top == -1 )
	   {
	      while ( top != -1 )
		  {
	        vr = pop();
			rez->push(vr);
		  }
	   }
	    return rez;
	}
	
	template<class t> // method that reverses order of elements in the stack
	void StackAsArray<t>::reverse()
	{
	   StackAsArray<t> pom(size);
	   t el; 
	
	   while( top !=-1 )
	   {
	     el = pop();
		 pom.push(el);
	   }
	   *this = pom;
	}

