#include "main_head.h"

using namespace std;

Stroka::Stroka(int val)
{
	len = val;
	pCh = new char[len + 1];
	if (val == 0) pCh[0] = '\0';
	cout << "Stroka::Stroka(int val):len=" << len << endl;
}

Stroka::Stroka(char ch)
{
	len = 1;
	pCh = new char[len + 1];
	pCh[0] = ch;
	pCh[1] = '\0';
	cout << "Stroka::Stroka(char ch)" << endl;
}

Stroka::Stroka(const char* S)
{
	len = strlen(S);
	pCh = new char[len + 1];
	strcpy_s(pCh, len + 1, S);
	cout << "Stroka::Stroka(const char* S)" << endl;
}

Stroka::Stroka(const Stroka& from)
{
	len = strlen(from.pCh);
	pCh = new char[len + 1];
	strcpy_s(pCh, len + 1, from.pCh);
	cout << "Stroka::Stroka(const Stroka& from)" << endl;
}

Stroka::~Stroka()
{
	if (pCh) delete[] pCh;
	cout << "Stroka::~Stroka()" << endl;
}

void Stroka::Show(void)
{
	cout << "pCh = " << pCh << endl;
	cout << "len = " << len << endl;
	cout << "void Stroka::Show(void)" << endl;
}

void Stroka::Clear(void)
{
	len = 0;
	if (pCh) delete[] pCh;
	pCh = new char[1];
	pCh[0] = '\0';
	cout << "void Stroka::Clear(void)" << endl;
}

char Stroka::operator[] (const int index)
{
	if (!(index >= 0 && index < len)) return '0';
	return pCh[index];
}
