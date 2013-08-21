//Class User - example for Hash Object
#include<iostream.h>
class User
{
  public:
	  char *phoneNumber;
	  char *userName;
	  char *userSurname;
	  
	  User() // constructor
	  {
		  phoneNumber ='\0';
		  userName ='\0';
		  userSurname ='\0';
	  }
	  
	  User( char *br , char *im , char *pr ) // constructor with arguments
	  {
		  phoneNumber = br;
		  userName = im;
		  userSurname = pr;
	  }

	  ~User() // destructor
	  {
	  }
 
	  void printUserData()
	  {
		  cout<<phoneNumber<<"   "<<userName<<"   "<<userSurname<<endl;
	  }

	  char * getNumber()
	  {    
		  return phoneNumber;
	  }

	  friend ostream& operator<<(ostream& izlaz, User *k) // friendly function for printing User data
	  {
			izlaz<<k->phoneNumber<<" "<<k->userName<<" "<<k->userSurname;
			return izlaz;
       
	  }
};

