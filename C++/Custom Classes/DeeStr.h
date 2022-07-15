#ifndef DEESTR_H
#define DEESTR_H

#include "Stroka.h"

class DeeStr : public Stroka
{
public:
	DeeStr(int = 0);
	DeeStr(char);
	DeeStr(const char*);
	DeeStr(const DeeStr &);
	virtual ~DeeStr();
	DeeStr& operator = (const DeeStr &);
	friend DeeStr operator - (const DeeStr &, const DeeStr &);
	friend DeeStr operator - (const DeeStr &, const int);
	friend DeeStr operator - (const int, const DeeStr &);
	friend DeeStr operator > (const DeeStr &, const DeeStr &);
	friend DeeStr operator > (const DeeStr &, const int);
	friend DeeStr operator > (const int, const DeeStr &);
};

#endif