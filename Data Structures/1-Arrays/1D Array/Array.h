template <class T>
class Array
{
private:
	int length; // array length
	int base; // base
	T* data;// array pointer
public:
	Array() // default constructor
	{
		length=0;
		base=0;
		data=new T[length];
		for(int i=0;i<length;i++)
			data[i]=0; 
	}
	Array(int len) // initaly base is set to 0
	{
		length=len;
		base=0;
		data=new T[length];
		for(int i=0;i<length;i++)
			data[i]=0;
	}
	Array(int len, int b) // whan base is set to value b
	{
		length=len;
		base=b;
		data=new T[length];
		for(int i=0;i<length;i++)
			data[i]=0;
	}
	~Array() // destructor
	{
		delete[] data;
	}
	void insert(T el,int poz); // for inserting elements into array
	void print(); // for printing array
	int getBase() 
	{
		return base;
	}
	void setBase(int b)
	{
		base=b;
	}
	int getLength()
	{
		return length;
	}
	void setLength(int newLen); // method for setting length of the Array
	Array& operator=(Array& a); // operator =
	T operator[](int index); // operator []
	void bubble(); // bubble sort algotirhm
	void nThDerivative(Array<T>& a,int n); // Method for calculating Nth derivative of polynom represented as an array
};

// IMPLEMENTATION OF METHODS
template <class T>
void Array<T>::print()   // printing array
{
	for(int i=0;i<length;i++)
		cout<<data[i]<<" ";
	cout<<endl;
}
 template <class T>
 void Array<T>::insert(T el, int poz) // inserting element to certain position
 {
	 int offset=poz-base;
	 if(length<=offset)
		 throw "index je van granica";
	 else
		data[offset]=el;
 }
template <class T>
void Array<T>::setLength(int newLen) // setting the length of the array
{
	if(length!=newLen)
	{
		T* newData=new T[newLen];
		int min=length;
		if(min>newLen)
			min=newLen;
		for(int i=0;i<min;i++)
			newData[i]=data[i];
		delete[] data;
		data=newData;
		
	}
}
template <class T>
Array<T>& Array<T>::operator =(Array<T>& a)  // operator =
{
	base=a.base;
	if(length!=a.length)
	{
		length=a.length;
		delete[] data;
		data=new T[length];
	}
	for(int i=0;i<length;i++)
		data[i]=a.data[i];
	return *this;
}
template <class T>
T Array<T>::operator [](int index) // operator []
{
	int offset=index-base;
	if  (length<=offset)
		throw "index je van opsega";
	return data[offset];
}
template <class T>
void Array<T>::bubble()  // bubble sort
{
	int tmp;
	for(int i=0;i<length-1;i++)
	{
		for(int j=0;j<length-i-1;j++)
		{
			if(data[j]<data[j+1])
			{
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
			}
		}
	}

}
template <class T>
void Array<T>::nThDerivative(Array<T>& a,int n)  //  first derivative of polynoim where 'a[i]' is coeficiente and 'i' is 'degree'
{
	for(int j=0;j<n;j++)
	{
		int len=length-1;
		for(int i=len;i>0;i--)
		{
			data[i-1]=a.data[i]*i;
			a.data[i]=data[i];
		}
		a.data[0]=0;
	}	
}
