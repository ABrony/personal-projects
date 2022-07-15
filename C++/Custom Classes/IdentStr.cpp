#include "main_head.h"

using namespace std;

IdentStr::IdentStr(int val) :Stroka(val)
{
	cout << "Bad simvol" << endl;
}


IdentStr::IdentStr(char ch) :Stroka(ch)
{
	if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z') || (pCh[0] >= '0' && pCh[0] <= '9') || (pCh[0] == '_')))
	{
		cout << "Bad simvol, pCh[i] = " << pCh[0] << endl;
		if (pCh) delete[]pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return;
	}
	cout << "IdentStr::IdentStr(char ch)" << endl;
}

IdentStr::IdentStr(const char* Str) :Stroka(Str)
{
	const char *keyword[] = { "while", "for", "switch", "case", "asm", "auto", "bool", "break", "case", "catch", "char", "class", "const", "const_cast", "continue", "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto", "if", "inline", "int", "long", "main", "mutable", "namespace", "_asm", "__asm" };
	for (int i = 0; i < 39; i++)
	{
		if (strcmp(pCh, keyword[i]) == 0)
		{
			cout << "Bad stroka, pCh = " << pCh << endl;
			if (pCh) delete[]pCh;
			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return;
		}
	}
	if (pCh[0] >= '0' && pCh[0] <= '9')
	{
		cout << "Bad simvol, pCh[0] = " << pCh[0] << endl;
		if (pCh) delete[]pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return;
	}
	for (int i = 0; i < len; i++)
	{
		if (!((pCh[i] >= 'a' && pCh[i] <= 'z') || (pCh[i] >= 'A' && pCh[i] <= 'Z') || (pCh[i] >= '0' && pCh[i] <= '9') || (pCh[i] == '_')))
		{
			cout << "Bad simvol, pCh[i] = " << pCh[i] << endl;
			if (pCh) delete[]pCh;
			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return;
		}
	}
	cout << "IdentStr::IdentStr(const char* Str)" << endl;
}

IdentStr::IdentStr(const IdentStr & from) :Stroka(from)
{
	cout << "IdentStr::IdentStr(const IdentStr & from)" << endl;
}

IdentStr::~IdentStr()
{
	cout << "IdentStr::~IdentStr()" << endl;
}

IdentStr& IdentStr::operator=(const IdentStr& S)
{
	if (&S != this)
	{
		delete[]pCh;
		len = strlen(S.pCh);
		pCh = new char[len + 1];
		strcpy_s(pCh, len + 1, S.pCh);
		cout << "IdentStr & IdentStr::operator =(const IdentStr & S)" << endl;
	}
	return *this;
}

IdentStr IdentStr::operator~()
{
	int i, j;
	char tmp;
	for (i = 0, j = len - 1; i < len / 2; i++, j--)
	{
		tmp = pCh[i];
		pCh[i] = pCh[j];
		pCh[j] = tmp;
	}
	cout << "IdentStr IdentStr::operator~()" << endl;
	return *this;
}

IdentStr operator + (const IdentStr &pobj1, const IdentStr &pobj2) {
	IdentStr tmp;
	char *pChtmp;
	int newlen = pobj1.len + pobj2.len + 1;
	pChtmp = new char[newlen];
	for (int i = 0; i < pobj1.len; i++)
	{
		pChtmp[i] = pobj1.pCh[i];
	}
	
	for (int i = pobj1.len; i < (newlen); i++)
	{
		pChtmp[i] = pobj2.pCh[i - pobj1.len];
	}
	tmp.len = strlen(pChtmp);
	tmp.pCh = pChtmp;
	cout << "IdentStr operator + (const IdentStr &pobj1, const IdentStr &pobj2)" << endl;
	return tmp;
}

IdentStr operator + (const char *pobj1, const IdentStr &pobj2) {
	IdentStr tmp;
	IdentStr tmp1(pobj1);
	char *pChtmp;
	int newlen = tmp1.len + pobj2.len + 1;
	pChtmp = new char[newlen];
	for (int i = 0; i < tmp1.len; i++)
	{
		pChtmp[i] = tmp1.pCh[i];
	}

	for (int i = tmp1.len; i < (newlen); i++)
	{
		pChtmp[i] = pobj2.pCh[i - tmp1.len];
	}
	tmp.len = strlen(pChtmp);
	tmp.pCh = pChtmp;
	cout << "IdentStr operator + (const char *pobj1, const IdentStr &pobj2)" << endl;
	return tmp;
}

IdentStr operator + (const IdentStr &pobj1, const char *pobj2) {
	IdentStr tmp;
	IdentStr tmp1(pobj2);
	char *pChtmp;
	int newlen = pobj1.len + tmp1.len + 1;
	pChtmp = new char[newlen];
	for (int i = 0; i < pobj1.len; i++)
	{
		pChtmp[i] = pobj1.pCh[i];
	}

	for (int i = pobj1.len; i < (newlen); i++)
	{
		pChtmp[i] = tmp1.pCh[i - pobj1.len];
	}
	tmp.len = strlen(pChtmp);
	tmp.pCh = pChtmp;
	cout << "IdentStr operator + (const IdentStr &pobj1, const char *pobj2)" << endl;
	return tmp;
}
