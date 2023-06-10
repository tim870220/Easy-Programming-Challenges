//  For this challenge you will be sorting characters in a string.
// take the str string parameter being passed and return the string with the letters in alphabetical order (ie. hello becomes ehllo). Assume numbers and punctuation symbols will not be included in the string. 

#include <iostream>
#include <string>
#include <hash_map> 
using namespace std;
using namespace __gnu_cxx;

string AlphabetSoup(string str) {
	/*
	bool swap;
	char temp;

	// Doing a bubble sort to implementation to compare all the characters
	do
	{
		swap = false;

		for (int x = 0; x < str.length() - 1; x++)
		{
			if (str[x] > str[x + 1])
			{
				temp = str[x];
				str[x] = str[x + 1];
				str[x + 1] = temp;
				swap = true;
			}
		}
	} while (swap);

	// Removing spaces
	string temp2;
	for (int y = 0; y < str.length(); y++)
	{
		if (str[y] != ' ')
		{
			temp2.push_back(str[y]);
		}
	}

	return temp2;
	*/

	// // bubble sort
	// string temp;
	// int i = 0, j = 0;
	// while (i < str.length()){
	// 	if (isalpha(str[i])){
	// 		temp += str[i];
	// 	}
	// 	i++;
	// }

	// 	while (j < temp.length()-1){
	// 		if (temp[j] > temp[j+1]){
	// 			swap(temp[j], temp[j + 1]);
	// 			j = max(j-1,0);
	// 		}
	// 		else{
	// 			j++;
	// 		}
	// }
	// return temp;

	// hash map
	hash_map<char, int> mp;
	string ans;

	for(int i = 0;i< str.length(); i++){
            mp[str[i]]++;
	}
	for (int i = 97; i < 123; i++)
	{
		if (mp[char(i)] > 0)
			ans += string(mp[char(i)], char(i));
	}
	return ans;
}

int main() {

	// keep this function call here
	cout << AlphabetSoup("test") << endl;
	cout << AlphabetSoup("hello") << endl;
	cout << AlphabetSoup("wow this is radical the a should be first") << endl;
	return 0;

}