// For this challenge you will determine the area of a rectangle.
/*
have the function RectangleArea(strArr) take the array of strings stored in strArr, 
which will only contain 4 elements and be in the form (x y) where x and y are both integers, 
and return the area of the rectangle formed by the 4 points on a Cartesian grid. 
The 4 elements will be in arbitrary order. For example: if strArr is ["(0 0)", "(3 0)", "(0 2)", "(3 2)"] 
then your program should return 6 because the width of the rectangle is 3 and the height is 2 and the area 
of a rectangle is equal to the width * height. 
*/

#include <bits/stdc++.h>

using namespace std;

int RectangleArea(string strArr[]) {
 vector<int> x, y;
 stringstream ss;
 int num;
 char c;

 for (auto i = 0; i < 4; i++){
  ss << strArr[i];
  ss >> c;
  ss >> num;
  x.push_back(num);
  ss >> num;
  y.push_back(num);
  ss >> c;
 }

 int x_min = *min_element(x.begin(),x.end());
 int x_max = *max_element(x.begin(),x.end());
 int y_min = *min_element(y.begin(),y.end());
 int y_max = *max_element(y.begin(),y.end());

 return (x_max - x_min)*(y_max - y_min);
}

int main() {

 // keep this function call here
 /* Note: In C++ you first have to initialize an array and set
 it equal to the stdin to test your code with arrays. */

 string A[] = { "(1 1)", "(1 3)", "(3 1)", "(3 3)" }; 
 string B[] = { "(0 0)", "(1 0)", "(1 1)", "(0 1)" }; 
 string C[] = { "(0 0)", "(3 0)", "(0 2)", "(3 2)" };
 string D[] = { "(-1 -1)", "(0 0)", "(-1 0)", "(0 -1)" };
 string E[] = { "(-2 -2)", "(0 0)", "(-2 0)", "(0 -2)" };
 string F[] = { "(0 0)", "(0 0)", "(0 0)", "(0 0)" };
 cout << RectangleArea(A) << endl; // 4
 cout << RectangleArea(B) << endl; // 1
 cout << RectangleArea(C) << endl; // 6
 cout << RectangleArea(D) << endl; // 1
 cout << RectangleArea(E) << endl; // 4
 cout << RectangleArea(F) << endl; // 0
 return 0;

}