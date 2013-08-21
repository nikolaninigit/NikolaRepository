// Class for modeling HashObject
#include<iostream.h>
template<class t , class r>
class HashObject
{
  protected:
	  t key; // key
	  r * record; // pointer to some data

  public:
	  HashObject() // constructor
	  {
		  key = (t) 0;
		  record = NULL;
	  }
	  
	  HashObject(t k) // constructor with argument
	  {
		  key = k;
		  record = NULL;
	  }

     HashObject( t keyValue , r * rec ) // constructor with arguments
	 {
		 key = keyValue;
		 record = rec;
	 }
	 
	 ~HashObject() // destructor
	 {
	 }

	 t getKey()
	 { 
		 return key;
	 }
	 
	 r * getRecord()
	 {
		 return record;
	 }

	 HashObject & operator=( HashObject & rhs )
	 {
		 key = rhs.key;
		 record = rhs.record;
		 return *this;
	 }

	 bool operator==( HashObject & rhs )
	 {
		 return ( record == rhs.record );
	 }

	 bool isEqualKey( t klj )
	 {
		 return (key == klj);
	 }

	 void Print()
	 {
		 cout<<key<<" +  "<<record<<" ";
	 }

	 void deleteRecord() // Method for deleting record
	 {
		 if( record != NULL )
		 {
		 delete record;
		 record = NULL;
		 }
	 }
};