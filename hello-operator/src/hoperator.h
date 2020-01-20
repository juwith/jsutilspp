#ifndef HELLO_H_INCLUDED
#define HELLO_H_INCLUDED

class HeyOper
{
private:
	int val;
public:
	HeyOper(int val);
	~HeyOper();
	void printinfo();
	HeyOper plus(const HeyOper& obj);
	HeyOper operator+(const HeyOper& obj);
};

#endif

