#ifndef IDENTSTR_H
#define IDENTSTR_H

#include "Stroka.h"

class IdentStr :public Stroka
{
public:
	IdentStr(int = 0);
	IdentStr(char);
	IdentStr(const char*);
	IdentStr(const IdentStr &);
	virtual ~IdentStr();
	IdentStr& operator = (const IdentStr &);
	IdentStr operator ~ ();
	friend IdentStr operator + (const IdentStr &, const IdentStr &);
	friend IdentStr operator + (const char *, const IdentStr &);
	friend IdentStr operator + (const IdentStr &, const char *);
};

#endif