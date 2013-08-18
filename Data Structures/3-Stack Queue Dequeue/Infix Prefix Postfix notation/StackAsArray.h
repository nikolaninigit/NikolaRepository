#include<iostream.h>
#include "Stack.h"
#include<string.h>

template<class t>
class StackAsArray :  public Stack<t>
{
	protected:
		t *niz; // pointer to array
		int size; // max number of elements in the stack
		int top; // top of the stack
	
	public:

	StackAsArray(int n) // default constructor
	{
        size = n;
		niz = new t[size];
		top = -1;
	}

	~StackAsArray()// destructor
	{
		delete[] niz;
		size = 0;
		top = -1;
	}
    
     void push(t elem); // method for adding elements
	 t pop(); // method for getting elements from the top of the stack
	 t getTop(); //method for getting value of element from the top of the stack
	 void print(); // function for printing elements from the stack
	 void reverse(); // function for reversing order of elements in the stack
	 void infixPostfix( char *e ); // function for translating "infix" into "postfix" notation
	 void printOdDna(); // function that prints elelemnt from bottom to the top
	 void postfixInfix( char *e ); // function for translating "postfix" into "infix" notation 
	 double postfix07(char *izraz); // calculating value for postfix notation
	 void infixPrefix( char *e ); // function for translating "infix" into "prefix" notation
     void prefixInfix( char *e ); // function for translating "prefix" into "infix" notation
	 double racunajPrefix(char *e); // calculating value for prefix notation
};

template<class t> // method for adding elements
void StackAsArray<t>::push(t elem)
{
   if( top >= (size -1) )
	   throw "IZUZETAK - STEK JE PUN, NE MOZE SE DODATI ELEMENT";
    top = top+1;
	niz[top] = elem;
}

template<class t> // method for getting elements from the top of the stack
t StackAsArray<t>::pop()
{
    if (top == -1 )
		throw "IZUZETAK - STEK JE PRAZAN-NE MOZE POP";
 
	t elem = niz[top];
	top = top-1;

   return elem;
}

template<class t> //method for getting value of element from the top of the stack
t StackAsArray<t>::getTop()
{
    if ( top == -1 )
		 throw "IZUZETAK - NE MOZE getTop() DA SE ZOVE ZA PRAZAN STEK";

	t vred = niz[top];
	return vred;
}

template<class t> //function for printing elements from the stack
void StackAsArray<t>::print()
{
    if ( top == -1 )
		throw "NE MOZE print() , PRAZAN JE STEK";

	int i;

	for( i = top; i>=0; i-- )
		cout<<niz[i]<<"  ";
}

template<class t>  //function for reversing order of elements in the stack
void StackAsArray<t>::reverse()
{
   StackAsArray<t> p1(size);
   StackAsArray<t> p2(size);
   int pom; 

   // i put elelemnts in the help stack
   while( top != -1 )
   {
     pom = pop();
	 p1.push(pom);
   }

   // from help stack to other help stack
   while( p1.top != -1 )
   {
	   pom = p1.pop();
	   p2.push(pom);
   }

   // from second help stack i return elements to original
   while( p2.top != -1 )
   {
     pom = p2.pop();
	 push(pom);
   }

}

template<class t> // function for translating "infix" into "postfix" notation
void StackAsArray<t>::infixPostfix(char *e)
{
	// help stack
  StackAsArray<t> ps(size);
  int i=0;

  while( i < strlen(e) )
  {
	  // if is '(' than put to stack
	  if (  e[i]=='(' )
		  ps.push( e[i] );
        else
			if( e[i]>='a' && e[i]<='z' )
				push( e[i] ); // if it is some operand, put it on ordinary stack
              else
				  // if it is operator + or - 
				  if( (e[i] == '+') || ( e[i] == '-' ) )
				  {
				       
					 // if on stack is operator with same or higher priority
                      if( (ps.getTop() =='+') || ( ps.getTop() == '-' ) || ( ps.getTop() =='*') || ( ps.getTop() =='/') || ( ps.getTop() == '^') )
					  {
                         push( ps.pop() );
						 ps.push( e[i] );
					  }
                      else
						  // put on stack
						  ps.push( e[i] );

				  }
                    else
					 // if is operator * or /
                      if(  (e[i] =='*') || ( e[i] =='/' ) )
					  {
                           // if on stack is operator with same or higher priority
	                      if( (ps.getTop() =='*') || ( ps.getTop() == '/' ) || ( ps.getTop() == '^' ) )
						  {
                             push( ps.pop() ); // remove from top of the stack
						     ps.push( e[i]  ); // put on stack
						  }
				          else
							  // in other cases, put on stack
							  ps.push( e[i] );
					
					  }
                        else
						 // if is operator ^
						  if ( e[i] =='^')
						  {
                            // c
							  if ( ps.getTop() == '^' )
							  {
                                  push( ps.pop() );
                                  ps.push( e[i] );  
							  }
						     else
						        // if on stack is operator with NOT higher priority 
								ps.push( e[i] );
						  }
                         else
							 // if is symbol )
							 if( e[i] ==')' )
							 {
                               while( ps.getTop() != '(' )
							   {
                                 push( ps.pop() );

							   }
							      ps.pop(); 
							 }
						
         i = i+1;
  }

} 

template<class t> // function that prints elelemnt from bottom to the top
void StackAsArray<t>::printOdDna()
{
    if ( top == -1 )
		throw "IZUZETAK ZA printOdDna() - STEK JE PRAZAN";

    int i;

	for (i = 0; i<= top; i++)
		cout<<niz[i]<<"  ";
}

template<class t> // function for translating "postfix" into "infix" notation
void StackAsArray<t>::postfixInfix(char *e)
{
   int br = strlen(e);

   int i=0;
   int j;
   int ind;

   while( i< strlen(e) )
   {   
	   // if it is not operator, put in on the stack
      if( (e[i]>='a') && (e[i]<='z') )
	  {
          char *p = new char[2];
		  p[0] = e[i];
		  p[1] = '\0';

		  push(p);

	  }
	  else
	      // if is '+', then include brackets
		 if( (e[i] =='+') || (e[i] =='-') )
		{
			 char *s1 = pop();
			 char *s2 = pop();

			 char *sab = new char[ strlen(s1)+ strlen(s2) +2]; // +2 is for brackets, one for start and end bracket

			 sab[0] = '(';
             
			 for(ind=0; ind<strlen(s2); ind++)
				 sab[ind+1] = s2[ind];
             sab[ind+1] = e[i];
			 
			 for( j=0; j<strlen(s1); j++ )
				 sab[ind+2+j] = s1[j];

			 sab[ind+2+j] =')';

			 sab[ind+3+j] ='\0';
			 push(sab);
		 }
	   else
           // if it is some other operand
         if( (e[i] == '*') || (e[i] == '/') || (e[i] == '^') )
		 {
             char *pr1 = pop();
			 char *pr2 = pop();

			 char *rez = new char[ strlen(pr1) + strlen(pr2) + 1];

			 // take first element
			 for( ind=0; ind < strlen(pr2); ind++)
				 rez[ind] = pr2[ind];
           
			 // put the operand
			 rez[ind] = e[i] ;

			 // second element
			 for( j=0; j<strlen(pr1); j++ )
				 rez[ind+j+1] = pr1[j];
			 
			 rez[ind+j+1]='\0';

			 push(rez);
		 }
	  i=i+1;
   }
}

template<class t> // calculating value for postfix notation
double StackAsArray<t>::postfix07(char *e)
{
   int i;
 
   i=0;
   double p;
   double rez = 0;
   double vr1;
   double vr2;

   while( i < strlen(e) )
   {
	   // if it is digit
      if( (e[i]>='0' ) && ( e[i] <='9' ) )
	  {
        p = e[i] -'0';
		push(p);
	  }
     else
	   // if it is some sign
	    if ( e[i] =='+' ) 
		{
              vr2 = pop();
			  vr1 = pop();

			  rez = vr1+vr2;
              push(rez);
		}
          else
		      if ( e[i] =='*' )
			  {
                 vr2 = pop();
			     vr1 = pop();

			     rez = vr1*vr2;
                 push(rez);
			  }
               else
		         if ( e[i] =='-' )
				 {
                   vr2 = pop();
			       vr1 = pop();

			       rez = vr1-vr2;
				   push(rez);
				 }
                 else
			       if ( e[i] =='/' )
				   {
                     vr2 = pop();
			         vr1 = pop();

			         rez = vr1/vr2;

			         push(rez);
				   }

     i = i+1;
   }
   return pop();
}

template<class t> // function for translating "infix" into "prefix" notation
void StackAsArray<t>::infixPrefix(char *e)
{
	// help stack
	StackAsArray<t> pom(size);

	int i = strlen(e) -1 ;

	while( i>=0 )
	{
		// if it is ')' bracket 
		if( e[i] == ')' )
			pom.push(e[i]);
		else
			// if it is variable
			if( ( e[i]>='a' ) && ( e[i] <='z' ) )
				push(e[i]);
			else
				// if it is operator '+' or operator '-'
				if( (e[i] =='+' ) || ( e[i] == '-' ) )
				{
                   // if on stack is operator with same or high priority
					if( (pom.getTop() == '+' ) || (pom.getTop() == '-' ) || (pom.getTop() == '*' ) || (pom.getTop() == '/' ) || (pom.getTop() == '^' ) )
					{
                       // get operator into notation and put other on stack
						push( pom.pop() ) ;
						pom.push( e[i] );
					}
					else
					  pom.push( e[i] );

				}
				else
					// if it is operaor '*' or operator '/'
					if( (e[i] =='*' ) || ( e[i] == '/' )  )
					{   
						// if on stack is operator with same or high priority
						if( (pom.getTop()=='*') || (pom.getTop()=='/') || (pom.getTop()=='^') )
						{
							push( pom.pop() );
							pom.push( e[i] );
						}
						else
							pom.push(e[i]);

					}
					else
						// if it is operator ^
						if( e[i] =='^' )
						{
                          if( pom.getTop()=='^' )
						  {
							  push( pom.pop() );
							  pom.push(e[i]);
						  }
						  else
							  pom.push(e[i]);
						}
						else
							// if it is bracket (
							if( e[i] == '(' )
							{
								while( pom.getTop() != ')' )
								    push( pom.pop()  ); 
							
							 // at the end, I remove bracket from the stack 
							   pom.pop();
							}
	   i= i-1;
	}
//	reverse();
}

template<class t> // function for translating "prefix" into "infix" notation
void StackAsArray<t>::prefixInfix(char *e)
{ 
	int i = strlen(e)-1;
    int ind , j;

   while( i>=0 )
   {
      if( (e[i]>='a') && (e[i]<='z') )
	  {
         char *p = new char[2];
		 p[0] = e[i];
		 p[1] = '\0';
         push(p);

	  }
	  else
		  if( (e[i]=='+') || (e[i]=='-') )
		  {
             char *s1 = pop();
			 char *s2 = pop();

			 // length of first+length of second + for brackets
			 char *rez = new char[ strlen(s1)+strlen(s2) +4];

               rez[0] = '(';

			   for( ind=0; ind<strlen(s1); ind++ )
				   rez[ind+1] = s1[ind];

			   rez[ind+1] = e[i];

			   for(j=0; j<strlen(s2); j++)
				   rez[ind+j+2] = s2[j];

			   // to close bracket
			   rez[ind+j+2] = ')';

			   // for the end of the array
			   rez[ind+j+3] = '\0';
		  
		     push(rez);
		  }
		  else
			  if( (e[i] =='*') || (e[i] =='/') || (e[i] =='^'))
			  {
                 char *z1 = pop();
				 char *z2 = pop();

				 char *r1 = new char[ strlen(z1) + strlen(z2) +2 ];
				 
				 for ( ind = 0; ind < strlen(z1); ind++ )
					 r1[ind] = z1[ind];

				 r1[ind] = e[i];

				 for( j=0; j<strlen(z2); j++ )
					 r1[ind+j+1] = z2[j] ;

				 r1[ind+j+1] = '\0';
			  
			    push(r1);
			  }

		  

	  i = i-1;
   }
}

template<class t> calculating value for prefix notation
double StackAsArray<t>::racunajPrefix(char *e)
{
  double rez;
  double s;

  int i= strlen(e)-1;
  double p1 , p2;
   

  while( i>=0 )
  {
     if( (e[i]>='0') && (e[i]<='9'))
	 {
		 s = e[i] -'0';
         push(s);
	 }
     else
	  // if is '+' operation
	   if( e[i] =='+' )
	   {
          p1 = pop();
		  p2 = pop();
		  rez=p1+p2;

		  push(rez);
	   }
        else
	  // if is '-' operation
	   if( e[i] =='-' )
	   {
          p1 = pop();
		  p2 = pop();
		  rez=p1*p2;

		  push(rez);
	   }
        else
	  // if is '*' operation
	   if( e[i] =='*' )
	   {
          p1 = pop();
		  p2 = pop();
		  rez=p1*p2;

		  push(rez);
	   }
	    else
	  // if is '/' operation
	   if( e[i] =='/' )
	   {
          p1 = pop();
		  p2 = pop();
		  rez=p1/p2;

		  push(rez);
	   }

	i=i-1;
  }
   return pop();
}
