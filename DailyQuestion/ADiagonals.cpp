#include<bits/stdc++.h>
 
#define fast() ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define endl '\n'
using namespace std;
 
typedef long long ll;
 
const int N = 1e6+10, M = 30010, mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

 void solve(){
 	int n, k, sum = 0, count = 0;
 	cin >> n >> k;
 	if(k == 0){
 		cout << 0 << "\n";
 		return;
 	}
 	for(int i = n; i >= 1; i--){
 		if(i == n){
 			if(k <= n){
 				cout << 1 << "\n";
 				return;
 			}
 			sum = n;
 			count++;
 		}
 		else{
 			if(k <= sum + i){
 				count++;
 				cout << count << "\n";
 				return;
 			}
 			else if(k <= sum + 2*i){
 				count += 2;
 				cout << count << "\n";
 				return;
 			}
 			sum += 2*i;
 			count += 2;
 		}
 	}
 }

 int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); 
	freopen("output.txt","w",stdout); 
	#endif

	fast();
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
// https://codeforces.com/contest/1995/problem/A
