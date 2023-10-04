#include <bits/stdc++.h>
using namespace std;
#define long long ll;
inline void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    fast_io();
    //code goes here
    int n; cin>> n;
    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    if (n%2 == 0) {
        for (int i = 2; i <= n; i += 2)
            cout << i << " ";
        for (int j = 1; j < n; j += 2)
            cout << j << " ";
    } else {
        for (int i = 2; i < n; i += 2)
            cout << i << " ";
        for (int j = 1; j <= n; j += 2)
            cout << j << " ";
    }
    return 0;
}