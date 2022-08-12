#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> x;

int check(int R) {
    int good = 1;
    int middle = -1;
    for (int i = 0; i < N - 1; i++) {
        if (x[i + 1] - x[i] >= R) {
            if (middle != -1 || x[i + 1] - x[i] > 2 * R + 1) {
                return false;
            }
            if (x[i + 1] - x[i] == 2 * R + 1) {
                good = 2;
            }
            middle = i;
        }
    }
    if (middle != -1) {
        for (int d = 1; d < N; d++) {
            if (middle - d >= 0 && x[middle - d + 1] - x[middle - d] > R - d) {
                return false;
            }
            if (middle + d + 1 < N && x[middle + d + 1] - x[middle + d] > R - d) {
                return false;
            }
        }
        return good;
    } else {
        int d = INT_MAX;
        bool inc = false;
        for (int i = 0; i < N - 1; i++) {
            if (x[i + 1] - x[i] >= d) {
                inc = true;
            }
            if (inc && x[i + 1] - x[i] < d) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> N;
    x.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    int l = 0, r = 1e9, sol;
    bool half = false;
    while (l <= r) {
        int mid = (l + r) / 2;
        int chk = check(mid);
        if (chk) {
            r = mid - 1, sol = mid;
            half = chk == 2;
        } else {
            l = mid + 1;
        }
    }
    cout << sol << (half ? ".5" : ".0");
}
