#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x)                 x.begin(),x.end()
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, cnt = 1;
vector < vector<pair<int, int>>>save2;
ll dp[(int)2e5 + 5][2];
bool compp(pair<int, int>A, pair<int, int>B)
{
	if (A.first != B.first)
		return A.first > B.first;
	else
		return A.second < B.second;
}
ll dis(pair<int, int>A, pair<int, int>B)
{
	return abs(A.first - B.first) + abs(A.second - B.second);
}
ll sol(int i, int j)
{
	if (i == save2.size() - 1)
		return dis(save2[i][0], save2[i][1]);
	ll& ret = dp[i][j];
	if (~ret)
		return ret;
	ret = dis(save2[i][0], save2[i][1]) + min(dis(save2[i][j], save2[i + 1][0]) + sol(i + 1, 1),
		dis(save2[i][j], save2[i + 1][1]) + sol(i + 1, 0));
	return ret;
}
void solve()
{
	cin >> N;
	vector<pair<int, int>>ve(N);
	set<int>st;
	map<int, int>comp;
	clr(dp, -1);
	for (auto& it : ve) cin >> it.first >> it.second, st.insert(max(it.first, it.second));
	for (auto it : st) comp[it] = cnt++;
	vector < vector<pair<int, int>>>save(cnt + 2);
	for (auto& it : ve)
		save[comp[max(it.first, it.second)]].push_back(it);
	save2.push_back({ {0,0}  ,{0,0} });
	for (int i = 1; i <= cnt; i++)
	{
		sort(all(save[i]), compp);
		if (save[i].size())
			save2.push_back({ save[i][0],save[i].back() });
	}
	cout << sol(0, 0);
}
int main()
{
	solve();
}
