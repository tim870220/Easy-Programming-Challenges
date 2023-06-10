// For this challenge you will be reversing a binary string.
// have the function BinaryReversal(str) take the str parameter being passed, which will be a positive integer, take its binary representation, reverse that string of bits, and then finally return the new reversed string in decimal form. For example: if str is "47" then the binary version of this integer is 00101111. Your program should reverse this binary string which then becomes: 11110100 and then finally return the decimal version of this string, which is 244. 

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

string BinaryReversal1(string str) 
{
	int num = stoi(str);

	// converting to a binary
	str = "";

	while (!(num == 0 && str.length() % 8 == 0))
	{
		int n = num % 2;
		str += to_string(n);
		num /= 2;

	}

	// Converting back to a decimal
	int total = 0;
	for (int x = 0; x < str.length(); x++)
	{
		if (str[x] == '1')
		{
			// total += pow(2, (str.length() - 1) - x);
			total += (1 << (str.length() - 1 - x));
		}
	}

	return to_string(total);
}
string BinaryReversal(string str){
	int num = stoi(str);
	string tmp;
	while (!(num == 0 && tmp.length()%8 == 0)){
		tmp += to_string(num % 2);
		num /= 2;
	}
	int res = 0;
	for (int i = 0; i < tmp.length(); i++){
		if (tmp[i] == '1')
			res += 1 << (tmp.length() - 1 - i);
	}
	return to_string(res);
}

int main()
{
	cout << BinaryReversal("47") << endl; // 244
	cout << BinaryReversal("4567") << endl; // 60296
	cout << BinaryReversal("12345") << endl; // 39948
	cout << BinaryReversal("10156") << endl; // 13796

	return 0;
}