/*
    link: 
*/

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pri pair<int, int>
#define pr(x) cout<<#x<<"="<<x<<endl
#define pp(x) cout <<x<<endl
#define ps(x) cout <<#x<<endl

int maxCoin(string path, int n, int i, vector<int>& ans){
    //base
    if(i > n) return 0;
    if(path[i] == '*') return 0;

    int step1 = 0, step2 = 0;
    if(path[i] == '@'){
        step1++, step2++;
    }

    if(ans[i] != -1){
        return ans[i];
    }

    return ans[i] = max(step1 + maxCoin(path, n, i+1, ans), step2 + maxCoin(path, n, i+2, ans));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
    #endif

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string path; cin >> path;
        vector<int> ans(n+5, -1);

        int collect = maxCoin(path, n, 0, ans);
        cout << collect << endl;
    }

    return 0;
}