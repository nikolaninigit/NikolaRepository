// Main class for testing HashTable
#include<iostream.h>
#include "HashTable.h"
#include "User.h"
void main()
{
	try
	{
	 HashTable<char * , User> table(10);

	 User *k1 = new User("1234" , "Nikola" , "Mitrovic");	 
	 User *k2 = new User("1384" , "Aca" , "Milic");
	 User *k3 = new User("1734" , "Pera" , "Jovic");
	 User *k4 = new User("3243" , "Kaca" , "Simic");
	 User *k5 = new User("5254" , "Nora" , "Milic");
		
	 HashObject<char * , User> h1( k1->getNumber() , k1 );
	 HashObject<char * , User> h2( k2->getNumber() , k2 );
	 HashObject<char * , User> h3( k3->getNumber() , k3 );
	 HashObject<char * , User> h4( k4->getNumber() , k4 );
	 HashObject<char * , User> h5( k5->getNumber() , k5 );

	 // inserting
	 table.insert(h1);
	 table.insert(h2);
	 table.insert(h3);
	 table.insert(h4);
	 table.insert(h5);

	 // displaying
	 table.Display();
	 cout<<endl<<endl;
	 
	 // withdrawing
	 table.withdraw("1234");
	 table.Display();
	}
	catch( char *izuz )
	{
		cout<<izuz<<endl;
	}
}