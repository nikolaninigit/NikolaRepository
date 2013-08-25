// Class for modeling Data for HashTable
#include<iostream.h>
class KeyWord
{
   public:
	   int key; 
	   char * rec; 

   public:
		// constructor
		KeyWord( int k , char *r )
		{
		   key = k;
		   rec = r;
		}

		// destructor
		~KeyWord()
		{
		}
    
		// Method for returning Key value
		int getKey()
		{
			return key;
		}

		// Friendly method for printing
		friend ostream& operator<<(ostream& out, KeyWord *k)
		{
			out<<k->rec<<" ";
			return out;
		}

		void printKeyWord() // Method for printing
		{
			cout<<rec<<endl;
		}
};