template<class t>

class Stack
{

   public:

   virtual void push( t elem )
   {
     throw "EXCEPTION-push call";
   }

   virtual t pop()
   {
      throw "EXCEPTION-pop call";
   }

   virtual t getTop()
   {
      throw "EXCEPTION-VIRTUAL getTop() FUNCTION CALLED";
   }
};
