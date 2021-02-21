#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))
#define deb(X) cout << #X << " = " << X << endl;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<string, int> books;
    vector< pair<string, string> > shelf;
    string line;
    while (getline(cin, line) && line[0] != 'E')
	{
		string title;
		string author;

		istringstream in(line);

		in.ignore(1, '"');
		getline(in, title, '"');
		
		// Ignore first space.
		in.ignore(1, ' ');
		// Ignore 'by' with second space.
		in.ignore(2, ' ');

		getline(in, author, '"');
		shelf.push_back(make_pair(author, title));
	}
    
    sort(shelf.begin(), shelf.end());

    for (int i = 0; i < shelf.size(); ++i)
		books[shelf[i].second] = i;
    // Created book status.
	vector<bool> borrowed(shelf.size());
	vector<bool> returned(shelf.size());
	
	// Read actions.
	while (getline(cin, line) and line[0] != 'E')
	{
		string title;
		int previousBook = -1;
		
		istringstream in(line);

		if (line[0] != 'S')
		{
			in.ignore(8, '\"');
			getline(in, title, '\"');
		}
		
		switch (line[0])
		{
			case 'B':
				borrowed[books[title]] = true;
				returned[books[title]] = false;
			break;

			case 'R':
				returned[books[title]] = true;
			break;
			
			default:
				for (int i = 0; i < shelf.size(); ++i)
				{
					if (returned[i])
					{
						if (previousBook != -1)
							cout << "Put \"" << shelf[i].second << "\" after \"" << shelf[previousBook].second << "\"\n";
						else
							cout << "Put \"" << shelf[i].second << "\" first\n";
						
						returned[i] = false;
						borrowed[i] = false;
						
						previousBook = i;
					}
					else if (not borrowed[i])					
						previousBook = i;
				}

				cout << "END\n";
		}
	}

	return 0;
}