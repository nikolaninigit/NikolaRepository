// TEMPLATE CLASS FOR WORKING WITH MultiDimensionalArray , e.g. 3D, 4D, 5D, ... NDimensions
#include <String.h>
#include <iostream.h>
template<class T>
class MultiDimensionalArray
{
private:
	int dimension;//number of dimensions
	int* dim; // dimensions pointer
	int* fac; // pointer to array factors
	T* data; // data pointer
	int base; // base value

public: /// METHODS AND CONSTRUCTORS  
	MultiDimensionalArray(int* arg,int d, int b)
	{
	   	base=b;
		dimension=d;
		dim=new int[dimension];
		fac=new int[dimension];
		int product=1;
		for(int i=dimension-1;i>=0;i--)
		{
			dim[i]=arg[i];
			fac[i]=product;
			product=product*dim[i];
		}
		data=new T[product];
	}
	
    	// destructor 
	~MultiDimensionalArray()
	{
	}
	
    	// Method to set element to certain position
	void setAt(T el, int* indices, int n)
	{
		data[getOffset(indices,n)]=el;
	}
    
    	// Method for getting element from certain position
	T getAt(int* indices, int n)
	{
		return (data[getOffset(indices,n)]);
	}
	
    	// Get value of index based on "indices" vector
	int getOffset(int* indices, int n)//n дименсионс
	{
		if(n!= dimension)
			throw "dimensions out of bounds";
		int offset=0;
		for(int i=0;i<dimension;i++)
		{
			if((indices[i]<0) || (indices[i]>=dim[i]))
				throw "Index out of bounds";
			offset+=fac[i]*indices[i];
		}
		return offset;
	}
	
    	// Method for printing
	void print()
	{
		int product=1;
		for(int i=dimension-1;i>=0;i--)
		{
			fac[i]=product;
			product=product*dim[i];
		}
		for( i=0;i<product;i++)
			cout<<data[i]<<" ";
	}
};
