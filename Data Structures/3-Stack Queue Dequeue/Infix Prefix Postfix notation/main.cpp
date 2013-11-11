// Main class for testing infix prefix postfix notation methods
#include<iostream.h>
#include "StackAsArray.h"
void main()
{
	try
	{
		StackAsArray<char *>  obj(50); 
		
		// example 1 
		//char *e ="( ( ( a*b + c*d)^f + (d+e)^m ) / g )";
		// char *e ="(a+(b+c+d)*e)";
		
		// example 2	
		//  char *e="ab+c*d/ef^+g/";
		
		
		// example - from prefix to infix | set template to char *
		char *e="*a/+bcd";
		obj.prefixInfix(e);  
		obj.print(); 
		cout<<endl;
		
		/*
		// example - from prefix to infix | set template to char *
		char *e="ab+c*d/"; 
		obj.postfixInfix(e);
		obj.print();
		 cout<<endl;
		*/
		
		// example 3
		//	char *e="*7/+543";
		//	char *e="+43";
		
		
		/* 
		//example - from prefix to infix | set template to char *	
		char *e="( ( (a+b)*c/d + e^f) /g ) ";
		obj.infixPostfix(e);
		obj.print(); // stampanje magacina za prevodjenje izraza kad koristim //
		
		*/
		
		
		/*  
		  // example - from prefix to infix | set template to char *	
		  char *e="( ( (a+b)*c/d + e^f) /g ) ";
		  obj.infixPrefix(e);
		  obj.print(); // stampanje magacina za prevodjenje izraza kad koristim //
		*/
		
		
		
		/*
		//example - calculating value in postfix notation | set template to double
		 char *e="*7/+543";
		 cout<<obj.racunajPrefix(e);
		 
		 cout<<endl;
		*/
		
		
		/*
		//example - calculating value in postfix notation | set template to double 
		char *e = "72+4*3/";
		cout<<obj.postfix07(e)<<endl;
		*/    
	}
	catch(char *izuz)
	{
       cout<<izuz<<endl;
	}
}
