// Main class for testing methods to work with Polynoms
#include<iostream.h>
#include "SLLPol.h"

void main()
{
	try
	{
                 SLLPol<double> obj;
		 SLLPol<double> obj1;

		 SLLPol<double>  *r = new SLLPol<double>;
		 SLLPol<double>  *s = new SLLPol<double>;

		 SLLNode<double> cv(2,2);

		 // for first list
		 obj.addToHead(0,2);
		 obj.addToHead(1,4);
		 obj.addToHead(3,2);
         	obj.addToHead(5,3);
		 
  
         	// for second list
		 obj1.addToHead(0,2);
		 obj1.addToHead(1,1);
         	 obj1.addToHead(3,3);
		 obj1.addToHead(4,2);
		
		 cout<<"FIRST POLYNOM LOOKS"<<endl;
		 obj.print();
		 cout<<endl;
		 //////////

		 cout<<"SECOND POLYNOM LOOKS"<<endl;
		 obj1.print();
		 cout<<endl;
		 cout<<endl;
		 cout<<endl;
     ////////////////////

	    	// adding two polynoms
 		 cout<<endl<<"SUM LOOKS"<<endl;
	    s = r->add(obj , obj1);
	    s->print();
	    	 cout<<endl;
	////////


		 // multiplying
		 cout<<endl<<"PRODUCT LOOKS"<<endl;
		 r = r->mul(obj , obj1);
		 r->print();
		 cout<<endl;
	}
	catch( char *izuz )
	{
		cout<<izuz<<endl;
	}
}
