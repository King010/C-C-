#include<iostream>
using namespace std;

class String
{
	friend ostream& operator<<(ostream& os,String& s);
	friend istream& operator>>(istream& is,String& s);
public:
	String(char *str='\0')
		:_size(strlen(str))
		,_capacity(strlen(str)+1)
		,_str(new char [strlen(str)+1])
	{
		cout<<"String ()"<<endl;
		strcpy(_str,str);
	}
	
	String(const String&s)
		:_size(strlen(s._str))
		,_capacity(strlen(s._str)+1)
		,_str(new char[strlen(s._str)+1])
	{
		cout<<"String(const String&)"<<endl;
		strcpy(_str,s._str);
	}
	String &operator=(const String&s)
	{
		if(_str!=s._str)
		{
			delete[] _str;
			_str=new char [strlen(s._str)+1];
			strcpy(_str,s._str);
		}
		return *this;	
	}

	~String()
	{
		if(*_str!=NULL)
		{
			delete[]_str;
			_str=NULL;
			_size=0;
			_capacity=0;
		}
	}
private:
	char *_str;
	int _size;
	int _capacity;
};
ostream& operator<<(ostream& os,String &s)
{
	os<<s._str;
	return os;
}
istream& operator>>(istream& is,String &s)
{
	is>>s._str;
	return is;
}

int main()
{
	String s("hello world\n");
	String s2(s);
	String s3=s;
	cout<<s;	
	printf("hello");
	return 0;
}

