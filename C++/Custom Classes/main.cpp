#include "main_head.h"

using namespace std;

int main()
{
	Stroka Str1(0);
	cout << endl;
	Stroka Str2('A');
	cout << endl;
	Stroka Str3("ABC");
	cout << endl;
	Stroka Str4("1TM0");
	cout << endl;
	Stroka Str5(75);
	cout << endl;
	
	IdentStr IStr1(0);
	cout << endl;
	IdentStr IStr2('A');
	cout << endl;
	IdentStr IStr3("ABC");
	cout << endl;
	IdentStr IStr4("ITMO");
	cout << endl;
	IdentStr IStr5("XYZ");
	cout << endl;
	
	DeeStr DStr1('A');
	cout << endl;
	DeeStr DStr2("+10");
	cout << endl;
	DeeStr DStr3("4");
	cout << endl;
	DeeStr DStr4("ABC");
	cout << endl;
	
	cout << endl << "Str1:" << endl;
	Str1.Show();
	cout << endl << "Str2:" << endl;
	Str2.Show();
	cout << endl << "Str3:" << endl;
	Str3.Show();
	cout << endl << "Str4:" << endl;
	Str4.Show();
	cout << endl << "Str5:" << endl;
	Str5.Show();
	
	cout << endl << "IStr1:" << endl;
	IStr1.Show();
	cout << endl << "IStr2:" << endl;
	IStr2.Show();
	cout << endl << "IStr3:" << endl;
	IStr3.Show();
	cout << endl << "IStr4:" << endl;
	IStr4.Show();
	cout << endl << "IStr5:" << endl;
	IStr5.Show();
	
	cout << endl << "DStr1:" << endl;
	DStr1.Show();
	cout << endl << "DStr2:" << endl;
	DStr2.Show();
	cout << endl << "DStr3:" << endl;
	DStr3.Show();
	cout << endl << "DStr4:" << endl;
	DStr4.Show();
	
	DStr2 = DStr2 - 15;
	cout << endl << "DStr2:" << endl;
	DStr2.Show();
	
	DStr2 = DStr2 > 9;
	cout << endl << "DStr2:" << endl;
	DStr2.Show();
	
	DStr2 = 56 > DStr2;
	cout << endl << "DStr2:" << endl;
	DStr2.Show();
	
	IStr3 = ~IStr3;
	cout << endl << "IStr3:" << endl;
	IStr3.Show();
	
	Str5.Clear();
	cout << endl << "Str5:" << endl;
	Str5.Show();
	

	IStr5 = IStr3 + IStr4;
	cout << endl << "IStr3 + IStr4" << endl;
	IStr5.Show();
	cout << endl << "IStr3:" << endl;
	IStr3.Show();
	cout << endl << "IStr4:" << endl;
	IStr4.Show();

	cout << Str3[-1] << endl;
	cout << Str3[1] << endl;
	cout << Str3[3] << endl;
	
	IdentStr obj("1PBKS");
	obj = "1ITMO" + obj;
	obj.Show();
	
	system("pause");
	
	return 0;
}
