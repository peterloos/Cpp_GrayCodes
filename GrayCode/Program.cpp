#include <iostream>
using namespace std;

#include "BitVector.h"
#include "GrayCodeList.h"
#include "GrayCodeCalculator.h"

void main()
{
    GrayCodeCalculator calc;
    calc.SetLength (3); 
    GrayCodeList codes = calc.Calculate ();
    cout << calc.GetLength() << "-Bit-Gray-Code:" << endl;
    cout << codes << endl;

    calc.SetLength (5); 
    codes = calc.Calculate ();
    cout << calc.GetLength() << "-Bit-Gray-Code:" << endl;
    cout << codes << endl;

	calc.SetLength(8);
	codes = calc.Calculate();
	cout << calc.GetLength() << "-Bit-Gray-Code:" << endl;
	cout << codes << endl;

	getchar();
}