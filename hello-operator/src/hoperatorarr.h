#ifndef HOPERATORARR_H_INCLUDED
#define HOPERATORARR_H_INCLUDED

class HeyArrOper
{
private:
	char arr[128];
public:
	HeyArrOper(char* arr);
	~HeyArrOper();
	void printinfo();
	char& operator[](int count);
};


#endif

