#include<bits/stdc++.h>
using namespace std;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, test = 1, dp[10][10];
vector<pair<int, int>>ve;
int sol(int i, int j)
{
	if (i == j)
		return 0;
	if (j - i == 1)
		return (ve[i].first * ve[j].first * ve[j].second);
	int& ret = dp[i][j];
	if (~ret)
		return ret;
	ret = INT_MAX;
	for (int x = i; x < j; x++)
		ret = min(ret, ((ve[i].first * ve[x + 1].first * ve[j].second) + sol(i, x) + sol(x + 1, j)));
	return ret;
}
void Build(int i, int j)
{
	if (i == j)
	{
		cout << "A" << i + 1;
		return;
	}
	if (j - i == 1)
	{
		cout << "(A" << i + 1 << " x A" << j + 1 << ")";
		return;
	}
	int ret = dp[i][j];
	for (int x = i; x < j; x++)
	{
		if (ret == ((ve[i].first * ve[x + 1].first * ve[j].second) + sol(i, x) + sol(x + 1, j)))
		{
			cout << "(";
			Build(i, x);
			cout << " x ";
			Build(x + 1, j);
			cout << ")";
			break;
		}
	}
}
void solve()
{
	while (cin >> N)
	{
		if (!N)
			break;
		ve = vector<pair<int, int>>(N);
		clr(dp, -1);
		for (auto& it : ve) cin >> it.first >> it.second;
		sol(0, N - 1);
		cout << "Case " << test++ << ": ";
		Build(0, N - 1);
		cout << "\n";
	}
}
int main()
{
	solve();
}
