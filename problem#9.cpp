#include<bits/stdc++.h>
using namespace std;

int findMaxSum(vector<int> arr, int N) {
	if(N == 1) {
		return arr[0];
	}
	int dp[N][2];
	
	dp[0][0] = 0;
	dp[0][1] = arr[0];
	
	for(int i = 1; i < N; i++) {
		dp[i][1] = dp[i-1][0] + arr[i];
		
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
	}
	return max(dp[N-1][0], dp[N-1][1]);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << findMaxSum(v, n);
	return 0;
}