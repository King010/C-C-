#include<iostream>
using namespace std;
#include<stdio.h>


enum
{
	typeA,
	typeB,
};

class product
{
public:
	virtual void show()=0;
};

class productA:public product
{
public:
	virtual void show()
	{
		printf("product A\n");
	}
};

class productB:public product
{
public:
	virtual void show()
	{
		printf("product B\n");
	}
};

class Factor
{
public:
static product* CreateProduct(int type)
	{
		switch(type){
		case typeA:
		return new productA();break;
		case typeB:
		return new productB();break;
		}
	}
};

int main()
{
	Factor *f;
	product *a=f->CreateProduct(typeA);	
	product *b=f->CreateProduct(typeB);
	a->show();
	b->show();	
	return 0;
}
