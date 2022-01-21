#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, dp[(int)1e5 + 5][3][2];
vi ve;
int sol(int i, int rem, int ok)
{
	if (i == N)
		return (!(!rem && ok)) * -1e6;
	int& ret = dp[i][rem][ok];
	if (~ret)
		return ret;
	ret = sol(i + 1, rem, ok);
	if (ok || ve[i])
		ret = max(ret, 1 + sol(i + 1, ((rem * 10) + ve[i]) % 3, 1));
	return ret;
}
void Build(int i, int rem, int ok)
{
	if (i == N)
		return;
	int ret = dp[i][rem][ok];
	if ((ok || ve[i]) && ret == 1 + sol(i + 1, ((rem * 10) + ve[i]) % 3, 1))
	{
		cout << ve[i];
		Build(i + 1, ((rem * 10) + ve[i]) % 3, 1);
	}
	else
		Build(i + 1, rem, ok);
}
void solve()
{
	string S; cin >> S;
	N = S.size();
	ve = vi(N);
	clr(dp, -1);
	for (int i = 0; i < N; i++)
		ve[i] = int(S[i] - '0');
	if (sol(0, 0, 0) <= 0)
	{
		for (int i = 0; i < N; i++)
		{
			if (!ve[i])
			{
				cout << 0;
				return;
			}
		}
		cout << -1;
	}
	else
		Build(0, 0, 0);
}
int main()
{
	solve();
}
