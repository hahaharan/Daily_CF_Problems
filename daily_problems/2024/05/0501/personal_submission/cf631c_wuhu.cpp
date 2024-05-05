#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }
    int t, r;
    vector<pair<int, int>> st;
    for (int i = 0; i < m; ++i) {
        cin >> t >> r;
        while (!st.empty() && st.back().second < r)st.pop_back();
        st.emplace_back(t - 1, r - 1);
    }
    vector<int> b(a.begin(), a.begin() + st[0].second + 1);
    sort(b.begin(), b.end());
    int p0 = 0, p1 = st[0].second;
    st.emplace_back(0, -1);
    for (int i = 0; i < st.size() - 1; ++i) {
        for (int j = st[i].second; j > st[i + 1].second; --j) {
            if (st[i].first) {
                a[j] = b[p0++];
            } else {
                a[j] = b[p1--];
            }
        }
    }
    for (int x: a)cout << x << " ";
}
