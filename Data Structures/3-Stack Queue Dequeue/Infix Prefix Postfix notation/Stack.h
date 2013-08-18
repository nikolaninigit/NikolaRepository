template<class t>

class Stack
{

   public:

   virtual void push( t elem )
   {
     throw "IZUZETAK-POZIV VIRTUELNE";
   }

   virtual t pop()
   {
      throw "VIRTUAL POP POZIV FUNKCIJE";
   }

   virtual t getTop()
   {
      throw "VIRTUAL getTop() FUNCTION CALLED";
   }
};