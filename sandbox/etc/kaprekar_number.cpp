#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long int

#define maxN 1000000000

using namespace std;

vector<int> partition(ll n) {
	vector<int> s;
	while (n != 0) {
		s.push_back(n%10);
		n/=10;
	}
	return s;
}

ll sortnasc(ll n) {
	vector<int> s = partition(n);
	sort(s.begin(), s.end());
	ll j = 0;
	for (int i = 0; i < s.size(); i++) {
		j = j*10 + s[i];
	}
	return j;
}

ll sortndesc(int n) {
	vector<int> s = partition(n);
	sort(s.begin(), s.end(), greater<int>());
	ll j = 0;
	for (int i = 0; i < s.size(); i++) {
		j = j*10 + s[i];
	}
	return j;
}

ll f(ll n) {
	return sortndesc(n) - sortnasc(n);
}

ll solve(ll n, ll k) {
	vector<int> seq;
	seq.push_back(n);
	for (int i = 1; i <= k; i++) {
		seq.push_back(f(seq[i-1]));
	}
	return seq[k];
}


int main(void) {
	ll n, k;
	cin >> n >> k;
	cout << solve(n, k) << endl;
}



	
