#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


bool isCh(char ch)
{
	if (((ch >= 65) && (ch <= 90)) || ((ch >= 97) && (ch <= 122)) || (ch == ' ') || (ch == '.') || (ch == ',') || (ch == '\'') || (ch == '?') || (ch == '!'))
		return 1;
	else
		return 0;
}

int main()
{
	fstream file("in.txt", ios::in);
	string temp;
	file >> temp;
	int key[4], index = 0;
	vector <int> hexStr, arr, arr2;
	for (int i(0), j(0); i < temp.length(); i += 2, j++)
	{
		unsigned int x = strtoul(temp.substr(i, 2).c_str(), NULL, 16);
		hexStr.push_back(x);

	}
	int k(0);
	for (index = 0; index < 4; index++)
	{
		for (int i(index); i < hexStr.size(); i+=4)
		{
			k = 0;
			if (!arr.size()) { //ѕри первой итерации заполн€ем массив байтами, подозреваемые на байт ключа
				for (int j(0); j < 255; j++)
				{
					int x = (hexStr[i] ^ j);

					if (isCh(x) || (x == ' ') || (x == '.') || (x == ',') || (x == '\'') || (x == '?') || (x == '!'))
					{
						arr.resize(arr.size() + 1);
						arr[k] = j;
						k++;
					}
				}
			}
			else
			{
				for (int j(0); j<arr.size(); j++) {
					int x = hexStr[i] ^ arr[j];
					if (!(isCh(x)))
					{
						arr.erase(arr.begin() + j);
					}
				}
			}
			if (arr.size() == 1)
			{
				key[index] = arr[0];
				arr.resize(0);
				break;
			}

		}


	}
	k = 0;
	for (int i(0); i < hexStr.size(); i++)
	{
		cout << char(hexStr[i] ^ key[k]);
		k++;
		if (k == 4)
			k = 0;
	}


	_getch();
	return 0;
}



