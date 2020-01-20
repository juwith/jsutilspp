#ifndef HELLO_H_INCLUDED
#define HELLO_H_INCLUDED

class Hello
{
private:
	int val;
public:
	Hello(int val) {
		this->val = val;
	};
	void printinfo();
};

#endif

