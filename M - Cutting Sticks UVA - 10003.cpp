#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, X, dp[55][55];
vi ve;
int sol(int i, int j)
{
	if (j - i <= 1)
		return 0;
	int& ret = dp[i][j];
	if (~ret)
		return ret;
	ret = INT_MAX;
	for (int x = i + 1; x < j; x++)
		ret = min(ret, (ve[j] - ve[i]) + sol(x, j) + sol(i, x));
	return ret;
}
void solve()
{
	while (cin >> X)
	{
		if (!X)
			break;
		cin >> N;
		ve = vi(N + 2);
		clr(dp, -1);
		for (int i = 1; i <= N; i++)
			cin >> ve[i];
		ve[0] = 0;
		ve[N + 1] = X;
		cout << "The minimum cutting is " << sol(0, N + 1) << ".\n";
	}
}
int main()
{
		solve();
}
