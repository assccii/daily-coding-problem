/*
Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; // # elements in the array
	cin >> n;
	vector<int> v(n); // array of size n;
	
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	vector<int> prefix(n, 1), suffix(n, 1);
	
	int temp = 1;
	
	for(int i = 1; i < n; i++) {
		temp *= v[i-1];
		prefix[i] = temp;
	}
	temp = 1;
	for(int i = n-2; i >= 0; i--) {
		temp *= v[i+1];
		suffix[i] = temp;
	}	
	vector<int> ans(n);
	for(int i = 0; i < n; i++) {
		ans[i] = prefix[i] * suffix[i];
	}
	for(auto i : ans) {
		cout << i << " ";
	}
	
	return 0;
}
