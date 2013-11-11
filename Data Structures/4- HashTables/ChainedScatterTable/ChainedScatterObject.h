// Class for modeling ChainedScatterObject
#include<iostream.h>
#include "ScatterObject.h"
template<class t , class r>
class ChainedScatterObject : public ScatterObject<t , r>
{
    public:
		int next; // pointer to next position in 'chain'
	public:

		// constructors
		ChainedScatterObject() : ScatterObject<t , r>()
		{
			next = -1;
		}
		ChainedScatterObject(t key) : ScatterObject<t , r>(key) { next = -1; }
		ChainedScatterObject(t key , r * rec) : ScatterObject<t , r>( key , rec ) { next = -1; }
        	ChainedScatterObject( t key , r * rec , int n ) : ScatterObject<t , r>( key , rec ) { next = n; }
};
