#ifndef STROKA_H
#define STROKA_H

class Stroka
{
protected:
	int len;
	char* pCh;
public:
	Stroka(int = 0);
	Stroka(char);
	Stroka(const char*);
	Stroka(const Stroka&);
	virtual ~Stroka();
	char* GetStr(void) const { return pCh; }
	int GetLen(void) const { return len; }
	void Show(void);
	void Clear(void);
	char operator [] (const int);
};

#endif