// Class for modeling Hash table
#include<iostream.h>
#include "HashObject.h"
#include <math.h>
template<class t , class r>
class HashTable
{
   protected:
       int count; // number of elements in the table
	   int length; // size of hashTable
   public:
       // Hash fucntion  
		int h(HashObject<t,r> obj)
		{
			return (f(obj.key)%length);
		}
		
		// Primary transformations - For Int, Double, char *
		
		int f(int key)
		{
			return abs(key);
		}

		int f(double key)
		{
			if(key==0)
				return 0;
			else
			{
				int exp;
				double mant=frexp(key, &exp);
				return ((2*fabs(mantisa)-1) *~0U);
			}
		}
		
		int f(char *s)
		{
			int res=0;
			int a=7;
			for(int i=0; s[i]!=0;i++)
				res=(res<<a)^s[i];
			return res;
		}

		// Secundary transformation
         int g(int i)
		{
			return (i+1)% length; 
		}

		int getLength() // Method for returning length of HashTable
		{
			return length;
		}
};