// Class for Modeling Hash Object
#include<iostream.h>
template<class t , class r>
class HashObject
{
	public:
		t key;
		r * record;
	public:
		HashObject() // constructors
		{
			key = (t) 0;
			record = NULL;
		}
        // constructor with parameters
		HashObject( t klj )
		{
			key = klj;
			record = NULL;
		}
		// constructor with parameters
		HashObject( t klj , r * rec )
		{
			key = klj;
			record = rec;
		}
		// desructor
		~HashObject()
		{
		}
 
		// Methods for getting Key and Record Value
		int getKey()
		{
			return key;
		}

		r * getRecord()
		{
			return record;
		}
		
		// Operators = and ==
		HashObject & operator=( HashObject &rhs )
		{
			key = rhs.key;
			record = rhs.record;

			return *this;
		}

		bool operator==(HashObject & rhs )
		{
			return ( record == rhs.record );
		}

		// Method for deleting
		void deleteRecord()
		{
			if ( record != NULL )
			{
			  delete record;
			  record = NULL;
			}
		}
		
		void print() // method for printing
		{
			cout<<key<<"  |  "<<record;
		}

		bool isEqualKey(t klj) // method to check if key is equal 
		{
           return key == klj;
		}
};