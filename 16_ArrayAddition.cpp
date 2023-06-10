// For this challenge you will determine if numbers in an array can add up to a certain number in the array.
// take the array of numbers stored in arr and return the string true if any combination of numbers in the array can be added up to equal the largest number in the array, otherwise return the string false. For example: if arr contains [4, 6, 23, 10, 1, 3] the output should return true because 4 + 6 + 10 + 3 = 23. The array will not be empty, will not contain all the same elements, and may contain negative numbers.


// #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// Linear search function to aid with the ArrayAddition function
bool search(vector <int> arr, int size, int value)
{
	for (int x = 0; x < size; x++)
	{
		if (value == arr[x])
		{
			return true;
		}
	}

	return false;
}

string ArrayAdditionI(int arr[], int size)
{
	vector <int> numberSkip;

	// Find the largest number in the array
	int high = arr[0];
	for (int x = 0; x < size; x++)
	{
		if (arr[x] > high)
		{
			high = arr[x];
		}
	}

	// Check each combination and see if they add up to the largest number
	int value, total, index;
	for (int i = 0; i < size; i++)
	{
		// Start with a single value not including the largest number
		if (arr[i] == high)
		{
			continue;
		}
		else
		{
			value = arr[i];
		}

		// Compare that value in a subset manner
		// example. A, AB, ABC, ABCD, AC, ACD, AD, etc
		do
		{
			total = value;
			index = -1; // Will help keep track of which number we are analyzing
			for (int y = 0; y < size; y++)
			{
				// If the value is the largest value, current value, or already in the list of past value, than ignore
				if (y == i || arr[y] == high || search(numberSkip, numberSkip.size(), arr[y]))
				{
					continue;
				}
				if (index == -1)
				{
					index = y;
				}

				total += arr[y];
				if (total == high)
				{
					return "true";
				}
			}

			numberSkip.push_back(arr[index]); // Insert the number to skip in the next iteration

		} while (numberSkip.size() != size - 2); // This list will include all values not including the largest number and the value to compare, which is why the max size is 2 less than array size.

		numberSkip.clear(); // Clear the list for the next value
	}

	return "false";
}

// ChatGPT
string combination_sum(vector<int> arr) {
  	int largest = *max_element(arr.begin(), arr.end());
  	arr.erase(remove(arr.begin(), arr.end(), largest), arr.end());
  	if (largest == 0) {
    	return "true";
  	}
  	for (int i = 1; i < (1 << arr.size()); i++) {
    	vector<int> combination;
    	for (int j = 0; j < arr.size(); j++) {
      		if (i & (1 << j)) {
        		combination.push_back(arr[j]);
      	}
    	}
    	if (accumulate(combination.begin(), combination.end(), 0) == largest) {
      		return "true";
    	}
  	}
  	return "false";
}

// ChatGPT2
// void generate_combinations(int index, vector<int> arr, vector<int> combination, vector<vector<int>>& combinations){
// 	if (index == arr.size()) {
//       	combinations.push_back(combination);
// 		return;
// 	}
// 	generate_combinations(index + 1, arr, combination, combinations);
// 	combination.push_back(arr[index]);
// 	generate_combinations(index + 1, arr, combination, combinations);
// }
string combination_sum2(vector<int> arr) {
  	int largest_num = *max_element(arr.begin(), arr.end());
  	arr.erase(remove(arr.begin(), arr.end(), largest_num), arr.end());
  	vector<vector<int>> combinations;

	function<void(int, vector<int>)> generate_combinations = [&](int index, vector<int> combination){
    	if (index == arr.size())
		{
      		combinations.push_back(combination);
      		return;
    	}
    	generate_combinations(index + 1, combination);
		combination.push_back(arr[index]);
		generate_combinations(index + 1, combination);
	};

	// generate_combinations(0, arr, {}, combinations);
	generate_combinations(0, {});
  	
  	for (const auto& combination : combinations) {
    	if (accumulate(combination.begin(), combination.end(), 0) == largest_num) {
      		return "true";
    	}
  	}
  return "false";
  
}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	// int A[] = { 5, 7, 16, 1, 2 };
	// int B[] = { 3, 5, -1, 8, 12 };
	// int C[] = { 4, 6, 23, 10, 1, 3 };
	// int D[] = { 10, 12, 500, 1, -5, 1, 0 };
	// cout << ArrayAdditionI(A, sizeof(A) / sizeof(A[0])) << endl; // false
	// cout << ArrayAdditionI(B, sizeof(B) / sizeof(B[0])) << endl; // true
	// cout << ArrayAdditionI(C, sizeof(C) / sizeof(C[0])) << endl; // true
	// cout << ArrayAdditionI(D, sizeof(D) / sizeof(D[0])) << endl; // false
	vector<int> arrA = {5, 7, 16, 1, 2};
	vector<int> arrB = {3, 5, -1, 8, 12};
	vector<int> arrC = {4, 6, 23, 10, 1, 3};
	vector<int> arrD = {10, 12, 500, 1, -5, 1, 0};
	
	cout << combination_sum(arrA) << endl; // false
	cout << combination_sum(arrB) << endl; // true
	cout << combination_sum(arrC) << endl; // true
	cout << combination_sum(arrD) << endl; // false
	
	cout << combination_sum2(arrA) << endl; // false
	cout << combination_sum2(arrB) << endl; // true
	cout << combination_sum2(arrC) << endl; // true
	cout << combination_sum2(arrD) << endl; // false
	return 0;
}

	