/*------------------------------------------------------------------------*
|    User: Huynh Viet Tuan Kiet                                           |
|    Degree: Student - Formal University                                  |
|    Study Computer Science at the University of Information Technology   |
|    Country: Viet Nam                                                    |
|    City: Ho Chi Minh                                                    |
|    Organization: VNUHCM - UIT - University of Information Technology    |
*-------------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define _TestCases_ ll tcs; cin >> tcs; while (tcs--)
#define db double
#define ld long double
#define ll long long
#define i64 __int64 // == ll
#define ull unsigned long long
#define ui64 unsigned __int64 // == unsigned ll
#define pq priority_queue
#define sortU(v) sort(v.begin(), v.end())
#define sortD(v) sort(v.rbegin(), v.rend())
#define pll pair<ll, ll>
#define psl pair<string, ll>
#define MOD 1e9 + 7

struct project {
    ll start;
    ll end;
    ll credit;
};

bool sortEnd(const project& a, project& b)
{
    return (a.end < b.end);
}

void SolveProblem()
{
    ll n; cin >> n;
    vector<project>a(n);

    for (auto& pr : a)
        cin >> pr.start >> pr.end >> pr.credit;

    sort(a.begin(), a.end(), sortEnd);

    map<ll, ll>dp;
    dp[0] = 0;
    ll ans = LLONG_MIN;

    for (ll i = 0; i < n; i++)
    {
        auto it = dp.lower_bound(a[i].start);
        it--;

        ans = max(ans, it->second + a[i].credit);
        dp[a[i].end] = ans;
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //_TestCases_
        SolveProblem();

    return 0;
}