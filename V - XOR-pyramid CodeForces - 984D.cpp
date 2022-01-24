#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, Q, L, R;
ll dp1[(int)5e3 + 1][(int)5e3 + 1], dp2[(int)5e3 + 1][(int)5e3 + 1];
vl ve;
ll sol(int i, int j)
{
	if (i > j)
		return 0;
	if (i == j)
		return ve[i];
	ll& ret = dp1[i][j];
	if (~ret)
		return ret;
	ret = sol(i + 1, j) ^ sol(i, j - 1);
	return ret;
}
ll getanswer(int i, int j)
{
	if (i == j)
		return ve[i];
	ll& ret = dp2[i][j];
	if (~ret)
		return ret;
	ret = max({ dp1[i][j] ,getanswer(i, j - 1), getanswer(i + 1, j) });
	return ret;
}
void solve()
{
	cin >> N;
	ve = vl(N);
	clr(dp1, -1);
	clr(dp2, -1);
	for (auto& it : ve) cin >> it;
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			sol(i, j);
	cin >> Q;
	while (Q--)
	{
		cin >> L >> R;
		L--, R--;
		cout << getanswer(L, R) << "\n";
	}
}
int main()
{
	solve();
}
