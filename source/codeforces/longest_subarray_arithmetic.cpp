#include <iostream>
#include <vector>

using namespace std;

#define ll long long int

ll max(ll ans, int b) {
	ll returned = (ans > b) ? ans : (ll) b;
	return returned;
}

int main(void) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		ll ans = 2;
		vector<int> ar;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			ar.push_back(a);
		}

		int dist = 2;

		int currAdj = (ar[1] - ar[0]);
		int prevA = (ar[1] - ar[0]);


		for (int i = 2; i < N; i++) {
			currAdj = ar[i] - ar[i-1];

			if (currAdj == prevA) {
				dist++;
			} else {
				prevA = currAdj;
				ans = max(ans, dist);
				dist = 2;
			}
		}
		ans = max(ans, dist);
		cout << "Case #" << t << ": " << ans << endl;
	}
}
