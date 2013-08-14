// TESTING METHODS FROM MultiDimensionalArray.h
#include "MultiDimensionalArray.h"
#include <iostream.h>
void main()
{
	try{
		
		int nizDimenzija[3]={2,2,2};
		MultiDimensionalArray<int> obj((int*)nizDimenzija,3,0);
		int ind[3]={0,1,0};
		obj.setAt(2,(int*)ind,3);
		int ind1[3]={0,1,1};
		obj.setAt(7,(int*)ind1,3);
		int ind2[3]={0,0,0};
		obj.setAt(3,(int*)ind2,3);
		int ind3[3]={0,0,1};
		obj.setAt(5,(int*)ind3,3);
		obj.print();
		cout<<endl;
		cout<<"Element [0][0][1] has value:  "<<obj.getAt((int*)ind1,3)<<endl;
		cout<<"Element [0][1][1] has order value:   "<<obj.getOffset((int*)ind1,3)<<endl;
	}
	catch(char* e)
	{
		cout<<e<<endl;
	}

	
}

