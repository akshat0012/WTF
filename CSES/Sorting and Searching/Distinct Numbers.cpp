#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// DUCK YOU ! WHAT YOU LOOKING AT DIATCH.
/* inline void fast_io(){ */
/*     ios_base::sync_with_stdio(0); */
/*     cin.tie(0); */
/*     cout.tie(0); */
/* } */
int main() {
    /* fast_io(); */
    int n; cin >> n;
    int x;
    set<int> st;
    for (int i=0; i<n; i++) {
        cin >> x;
        st.insert(x);
    }
    cout << st.size();
    return 0;
}
