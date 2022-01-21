#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, dp[(int)2e3 + 5][(int)2e3 + 5];
vi ve;
int sol(int i, int j)
{
	if (i > j)
		return 0;
	int& ret = dp[i][j];
	if (~ret)
		return ret;
	int day = i + (N - j);
	ret = max((day * ve[i]) + sol(i + 1, j), (day * ve[j]) + sol(i, j - 1));
	return ret;
}
void solve()
{
	cin >> N;
	ve = vi(N);
	clr(dp, -1);
	for (auto& it : ve)cin >> it;
	cout << sol(0, N - 1);
}
int main()
{
		solve();
}
