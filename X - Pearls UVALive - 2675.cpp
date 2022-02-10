#include<bits/stdc++.h>
using namespace std;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, dp[100][(int)1e5 + 5];
vector<pair<int, int>>ve;
int sol(int i, int sum)
{
	if (i == N)
		return 0;
	int& ret = dp[i][sum];
	if (~ret)
		return ret;
	ret = INT_MAX;
	if (i != N - 1)
		ret = sol(i + 1, sum + ve[i].first);
	ret = min(ret, (ve[i].first + sum + 10) * ve[i].second + sol(i + 1, 0));
	return ret;
}
void solve()
{
	cin >> N;
	ve = vector<pair<int, int>>(N);
	clr(dp, -1);
	for (auto& it : ve) cin >> it.first >> it.second;
	cout << sol(0, 0) << "\n";
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
