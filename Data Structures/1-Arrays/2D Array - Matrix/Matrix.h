// TEMPLATE CLASS FOR MANIPULATION WITH 2D MATRIX
#include<iostream.h>
template<class t>
class Matr
{
	private:
		int vr; // number of rows
		int kol; // number of columns
		t **m; // 2d pointer
    	public: // constructors and methods
		Matr();
		Matr(int v , int k); 
		~Matr(); // destructor
		void print(); // for matrix printing
		void clear(); // this methods sets everything to 0 in matrix

		Matr<t> & operator=(Matr<t> &rhs); // operator =
		void setAt(int i , int j , t val);// method for setting element to a certain position
        	void setRow( t *val , int n ); // method for adding vector with values into matrix, adding through rows
		void setCol(t * val , int n); // method for adding vector with values into matrix, adding through columns

};

	// default constructor
	template<class t>
	Matr<t>::Matr()
	{
	   vr = 0;
	   kol = 0;
	   m = 0;
	}
	
	// constructor with params - num. of rows and columns and initialize pointer
	template<class t>
	Matr<t>::Matr(int v , int k)
	{
		vr = v;
		kol = k;
	
		m = new t *[v];
	
		for( int i=0; i<vr; i++ )
			m[i] = new t[kol];
	
	}
	
	//destructor
	template<class t>
	Matr<t>::~Matr()
	{
		for (int i=0; i<vr; i++)
			delete [] m[i];
		delete[] m;
	}
	
	// method for printing
	template<class t>
	void Matr<t>::print()
	{
		for(int i=0; i<vr; i++ )
		{	
			for( int j=0; j<kol; j++ )
			   cout<<m[i][j]<<" ";
		   
			cout<<endl;
		}	
		cout<<endl;
	}
	
	// method for setting all elements to 0
	template<class t>
	void Matr<t>::clear()
	{
		for( int i=0; i<vr; i++ )
			for( int j=0; j<kol; j++ )
				m[i][j] = 0;
	}
	
	// operator =
	template<class t>
	Matr<t> & Matr<t>::operator =(Matr<t> &rhs)
	{
		for( int i=0; i<vr; i++ )
			delete [] m[i];
	
		delete [] m;
	
		m = new  t *[rhs.vr];
	
		for( i=0; i<rhs.vr; i++ )
			m[i] = new t[rhs.kol];
	
		vr = rhs.vr;
		kol = rhs.kol;
	
		for( i=0; i<rhs.vr; i++ )
			for( int j=0; j<rhs.kol; j++ )
				m[i][j] = rhs.m[i][j];
	
			return *this;
	}
	
	// method to set element to position [i,j]
	template<class t>
	void Matr<t>::setAt(int i , int j , t val)
	{
		m[i][j] = val;
	}
	
	//method for adding vector with values into matrix, adding through rows
	template<class t> 
	void Matr<t>::setRow(t *val , int n)
	{
		int tmpInd = 0;
		int pomBr = 0 ; // help counter
	
		if( n > vr*kol ) // if "val" array has more elements than matrix
		{
			for( int i=0; i<vr; i++ )
				for( int j=0; j<kol; j++ )
					m[i][j] = val[i*kol+j];
		}
		else
		{
			while( pomBr < n )
			{
				if( pomBr % kol == 0 && (pomBr !=0) )
					tmpInd++;
	
				m[tmpInd][pomBr%kol] = val[pomBr];
	
	           pomBr++;
			}
		}
	}
