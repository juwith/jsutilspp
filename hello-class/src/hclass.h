#ifndef HELLO_H_INCLUDED
#define HELLO_H_INCLUDED

class Hello
{
private:
	int val;
	char* str;
public:
	Hello(int val,const char* str);
	~Hello();
	void printinfo();
};

#endif

