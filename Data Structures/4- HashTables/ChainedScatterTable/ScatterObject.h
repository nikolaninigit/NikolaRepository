// Class for modeling Scatter Object
#include<iostream.h>
template<class t , class r>
class ScatterObject : public HashObject<t , r>
{
	public:
		bool free;

    public :
		// constructors
		ScatterObject() : HashObject<t , r>() {}
		ScatterObject( t key ) : HashObject<t , r>(key) { free = true; }
        ScatterObject( t key , r * rec ) : HashObject<t , r>(key , rec) { free= true; }
};