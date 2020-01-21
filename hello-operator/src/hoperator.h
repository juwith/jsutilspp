#ifndef HOPERATOR_H_INCLUDED
#define HOPERATOR_H_INCLUDED

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
	HeyOper& operator+=(const HeyOper& obj);
};

#endif
