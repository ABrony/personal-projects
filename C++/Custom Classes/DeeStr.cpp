#include "itoa.h"
#include "main_head.h"

using namespace std;

extern "C" char* numtostr(int);

DeeStr::DeeStr(char ch) :Stroka(ch)
{
	if (!(pCh[0] >= '0' && pCh[0] <= '9'))
	{
		cout << "Bad simvol, pCh[0] = " << pCh[0] << endl;
		if (pCh) delete[]pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return;
	}
	cout << "DeeStr::DeeStr(char ch)" << endl;
}

DeeStr::DeeStr(int val) : Stroka(val)
{
	cout << "DeeStr::DeeStr(int val)" << endl;
}

DeeStr::DeeStr(const char* Str) : Stroka(Str)
{
	if (!(pCh[0] == '+' || pCh[0] == '-' || pCh[0] >= '0' && pCh[0] <= '9'))
	{
		cout << "Bad simvol, pCh[0] = " << pCh[0] << endl;
		if (pCh) delete[]pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return;
	}
	for (int i = 1; i < int(strlen(Str)); i++)
	{
		if (!(pCh[i] >= '0' && pCh[i] <= '9'))
		{
			cout << "Bad stroka, pCh = " << pCh << endl;
			if (pCh) delete[]pCh;
			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return;
		}
	}
	cout << "DeeStr::DeeStr(const char* Str)" << endl;
}

DeeStr::DeeStr(const DeeStr & from) :Stroka(from)
{
	cout << "DeeStr::DeeStr(const DeeStr & from)" << endl;
}

DeeStr::~DeeStr()
{
	cout << "DeeStr::~DeeStr()" << endl;
}

DeeStr& DeeStr::operator = (const DeeStr& S)
{
	if (&S != this)
	{
		delete[]pCh;
		len = strlen(S.pCh);
		pCh = new char[len + 1];
		strcpy_s(pCh, len + 1, S.pCh);
		cout << "DeeStr & DeeStr::operator = (const DeeStr & S)" << endl;
	}
	return *this;
}

DeeStr operator - (const DeeStr &pobj1, const DeeStr &pobj2)
{
	int num1, num2;
	char  * pChtmp;
	DeeStr tmp(pobj1);
	num1 = atoi(tmp.GetStr());
	num2 = atoi(pobj2.GetStr());
	pChtmp = new char[strlen(itoa(num1 - num2))];
	num1 = num1 - num2;
	pChtmp = itoa(num1);
	tmp.pCh = pChtmp;
	tmp.len = strlen(pChtmp);
	cout << "DeeStr operator - (const DeeStr &pobj1, const DeeStr &pobj2)" << endl;
	return tmp;
}

DeeStr operator - (const DeeStr &pobj1, const int a)
{
	int num1;
	char *pChtmp, *ex;
	DeeStr tmp(pobj1);
	num1 = atoi(tmp.GetStr());
	cout << num1 << endl;
	ex = numtostr(a);
	pChtmp = new char[strlen(itoa(num1 - a))];
	pChtmp = itoa(num1 - a);
	tmp.pCh = pChtmp;
	tmp.len = strlen(pChtmp);
	cout << "DeeStr operator - (const DeeStr &pobj1, const int* a)" << endl;
	return tmp;
}

DeeStr operator - (const int a, const DeeStr& pobj2)
{
	int num1;
	char *pChtmp, *ex;
	DeeStr tmp(pobj2);
	num1 = atoi(tmp.GetStr());
	ex = numtostr(a);
	pChtmp = new char[strlen(itoa(a - num1))];
	pChtmp = itoa(a - num1);
	tmp.pCh = pChtmp;
	tmp.len = strlen(pChtmp);
	cout << "DeeStr operator - (const DeeStr &pobj1, const int* a)" << endl;
	return tmp;
}

DeeStr operator > (const DeeStr & pobj1, const DeeStr & pobj2)
{
	int num1, num2;
	DeeStr tmp(pobj1);
	num1 = atoi(tmp.GetStr());
	num2 = atoi(pobj2.GetStr());
	cout << "DeeStr operator > (const DeeStr & pobj1, const DeeStr & pobj2)" << endl;
	if (num1 > num2)
		return pobj1;
	else
		return pobj2;
}

DeeStr operator > (const DeeStr & pobj1, const int a)
{
	int num1, num2;
	char *Pa;
	DeeStr tmp(pobj1);
	num1 = atoi(tmp.GetStr());
	num2 = a;
	Pa = numtostr(a);
	cout << "DeeStr operator > (const DeeStr & pobj1, const DeeStr & pobj2)" << endl;
	if (num1 > num2)
		return pobj1;
	else
		return Pa;
}

DeeStr operator > (const int a, const DeeStr & pobj2)
{
	int num1, num2;
	char *Pa;
	DeeStr tmp(pobj2);
	num2 = atoi(tmp.GetStr());
	num1 = a;
	Pa = numtostr(a);
	cout << "DeeStr operator > (const DeeStr & pobj1, const DeeStr & pobj2)" << endl;
	if (num1 > num2)
		return Pa;
	else
		return pobj2;
}

