#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N;
ll dp[205];
vi ve;
ll sol(int i)
{
	if (i == N)
		return 0;
	ll& ret = dp[i];
	if (~ret)
		return ret;
	if (ve[i] == 0)
		ret = sol(i + 1);
	else
	{
		ll tem = 0;
		for (int j = i; j < N; j++)
		{
			tem = (tem * 10ll) + ve[j];
			if (tem > INT_MAX)
				break;
			ret = max(ret, tem + sol(j + 1));
		}
	}
	return ret;
}
void solve()
{
	string S; cin >> S;
	N = S.size();
	clr(dp, -1);
	ve = vi(N);
	for (int i = 0; i < N; i++)
		ve[i] = int(S[i] - '0');
	cout << sol(0) << "\n";
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
