// Class for tyring implemented methods for hashTable manipulation
#include<iostream.h>
#include "ChainedScatterTable.h"
#include "KeyWord.h"
void main()
{
	try
	{
		// INSERTING KEYWORDS INTO HASHTABLE
       ChainedScatterTable<int , KeyWord> table(10); 

	   char *key1 = "if";
	   int k1 = table.f(key1);
	   KeyWord *rec1 = new KeyWord(k1 , key1);
	   ChainedScatterObject<int , KeyWord> r1( rec1->getKey() , rec1 );
	  
	   char *key2 = "SWITCH";
	   int k2 = table.f(key2);
	   KeyWord *rec2 = new KeyWord(k2 , key2);
	   ChainedScatterObject<int , KeyWord> r2( rec2->getKey() , rec2 );

	   char *key3 = "CASE";
	   int k3 = table.f(key3);
	   KeyWord *rec3 = new KeyWord(k3 , key3);
	   ChainedScatterObject<int , KeyWord> r3( rec3->getKey() , rec3 );

	   // Inserting
	   table.insert(r1);
	   table.insert(r2);
	   table.insert(r3);

	   // Displaying elements
	   table.display();
	   cout<<endl;

	  // WithDrawing elements
	   table.withdraw( rec1->getKey() );
	   table.display();

	   // Finding element in HashTable
	   ChainedScatterObject<int , KeyWord> p;
	   p = table.find( rec1->getKey() );

	   p.print(); // Printing

	}
	catch( char *izuz )
	{
	   cout<<izuz<<endl;
	}
}