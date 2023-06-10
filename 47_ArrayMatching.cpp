// For this challenge you will add elements from two arrays in a particular order.
// have the function ArrayMatching(strArr) read the array of strings stored in strArr which will contain only two elements, both of which will represent an array of positive integers. For example: if strArr is ["[1, 2, 5, 6]", "[5, 2, 8, 11]"], then both elements in the input represent two integer arrays, and your goal for this challenge is to add the elements in corresponding locations from both arrays. For the example input, your program should do the following additions: [(1 + 5), (2 + 2), (5 + 8), (6 + 11)] which then equals [6, 4, 13, 17]. Your program should finally return this resulting array in a string format with each element separated by a hyphen: 6-4-13-17. If the two arrays do not have the same amount of elements, then simply append the remaining elements onto the new array(example shown below).Both arrays will be in the format : [e1, e2, e3, ...] where at least one element will exist in each array.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string ArrayMatching_GPT(string strArr[], int size){
	vector<int> arr1, arr2, result;
    stringstream ss1(strArr[0]), ss2(strArr[1]);
    char c;
    int num;

    // parse the first array
    ss1 >> c; // skip opening bracket
    while (ss1 >> num) {
        arr1.push_back(num);
        ss1 >> c; // skip comma or closing bracket
    }

    // parse the second array
    ss2 >> c; // skip opening bracket
    while (ss2 >> num) {
        arr2.push_back(num);
        ss2 >> c; // skip comma or closing bracket
    }

    // add the arrays element-wise
    int n = max(arr1.size(), arr2.size());
    for (int i = 0; i < n; i++) {
        int sum = (i < arr1.size() ? arr1[i] : 0) + (i < arr2.size() ? arr2[i] : 0);
        result.push_back(sum);
    }

    // convert the result to a string
    stringstream ss;
    for (int i = 0; i < result.size(); i++) {
        ss << result[i];
        if (i < result.size() - 1) ss << "-";
    }
    return ss.str();
}
string ArrayMatching(string strArr[], int size){
	stringstream ss1(strArr[0]), ss2(strArr[1]);
	vector<int> arr1, arr2, res;
	int num;
	char c;

	ss1 >> c;
	while (ss1 >> num){
		arr1.push_back(num);
		ss1 >> c;
	}
	ss2 >> c;
	while (ss2 >> num){
		arr2.push_back(num);
		ss2 >> c;
	}

	int n = max(arr1.size(), arr2.size());
	for (int i = 0; i < n; i++){
		int s = ((i < arr1.size()) ? arr1[i] : 0) + ((i < arr2.size()) ? arr2[i] : 0);
		res.push_back(s);
	}
	stringstream ss;
	for (int i = 0; i < res.size(); i++){
		ss << res[i];
		if (i != res.size()-1)
			ss << '-';
	}

	return ss.str();
}

int main() 
{
	string A[] = { "[1, 2, 5, 6]", "[5, 2, 8, 11]" };
	string B[] = { "[5, 2, 3]", "[2, 2, 3, 10, 6]" };
	cout << ArrayMatching(A, sizeof(A) / sizeof(A[0])) << endl; // 6-4-13-17
	cout << ArrayMatching(B, sizeof(B) / sizeof(B[0])) << endl; // 7-4-6-10-6
	return 0;

}