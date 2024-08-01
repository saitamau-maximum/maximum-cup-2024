#include <bits/stdc++.h>
using namespace std;

const int bit_size = 3000;

struct weighted_dsu {
public:
    weighted_dsu(): _n(0) {}
    explicit weighted_dsu(int n): _n(n), parent_or_size(n, -1), diff_weight(n, vector<bool>(bit_size, false)) {}

    int merge(int a, int b, const vector<bool>& w) {
        vector<bool> wa = weight(a);
        vector<bool> wb = weight(b);
        vector<bool> w_new(bit_size);

        for (int i = 0; i < bit_size; ++i) {
            w_new[i] = wa[i] ^ wb[i] ^ w[i];
        }

        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) swap(x, y);

        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        diff_weight[y] = w_new;

        return x;
    }

    bool same(int a, int b) {
        return leader(a) == leader(b);
    }

    int leader(int a) {
        if (parent_or_size[a] < 0) return a;
        int r = leader(parent_or_size[a]);
        for (int i = 0; i < bit_size; ++i) {
            diff_weight[a][i] = diff_weight[a][i] ^ diff_weight[parent_or_size[a]][i];
        }
        return parent_or_size[a] = r;
    }

    vector<bool> weight(int x) {
        leader(x); // 経路圧縮
        return diff_weight[x];
    }

    vector<bool> diff(int x, int y) {
        vector<bool> wx = weight(x);
        vector<bool> wy = weight(y);
        vector<bool> result(bit_size);

        for (int i = 0; i < bit_size; ++i) {
            result[i] = wx[i] ^ wy[i];
        }

        return result;
    }

private:
    int _n;
    vector<int> parent_or_size;
    vector<vector<bool>> diff_weight;
};

vector<bool> generate_mask(int l, int r) {
    vector<bool> mask(bit_size, false);
    for (int i = l; i <= r; ++i) {
        mask[i] = true;
    }
    return mask;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> comp;
    vector<tuple<int, int, int, int, int>> query;
    for (int i = 0; i < q; i++) {
        int t, L, R, l = -1, r = -1;
        cin >> t >> L >> R;
        comp.emplace_back(L);
        comp.emplace_back(R);
        if (t == 1) {
            cin >> l >> r;
            l--, r--;
        }
        query.emplace_back(tuple(t, L, R, l, r));
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (auto& [t, L, R, l, r]: query) {
        L = lower_bound(comp.begin(), comp.end(), L) - comp.begin();
        R = lower_bound(comp.begin(), comp.end(), R) - comp.begin();
    }

    vector<bool> mask, diff;
    weighted_dsu uf(comp.size());
    for (auto& [t, L, R, l, r]: query) {
        if (t == 1) uf.merge(L, R, generate_mask(l, r));
        else {
            if (!uf.same(L, R)) cout << "Ambiguous\n";
            else {
                diff = uf.diff(L, R);
                cout << count(diff.begin(), diff.end(), true) << "\n";
            }
        }
    }

    return 0;
}
