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
    int N;
    cin >> N;
    vector<int> ar;
    for (int i = 0; i < N; i++) {int j; cin >> j; ar.push_back(j);}

    // 1 1 1 1 1
    // hepsine 1 ver
    // kaldi 2
    // lug ve naak a ver onlari
    // 2 2 1 oluyor
    // fark 1 ve minimized
    // 
    // 4 3 6 7
    // boyle olsaydi
    // hmm
    // sortlayalim
    // 3 4 6 7
    // farki minimize etmek icin l ve ne nin esit sayida olmalari lazim 
    // ve n de onlarla esit olsun
    // tamam bu serinin averagini alalim
    // sum = 20, n = 4, avg = 5
    // en minimize etmek icin hepsinin 5 olmasi lazim
    // ama yapamiyoruz !
    // o zaman napicaz?
    // minimum u l ye verelim:
    // l = 3
    // n = 0
    // ne = 0
    // 
    // sonra?
    // sonra da diger minimumu n ye verelim
    // l = 3
    // n = 4
    // le = 0
    // sonra?
    // maximum u ne ye verelim
    // l = 3
    // n = 4
    // le = 7
    // sonra?
    // 
    
    int l = N/3, n = N/3, ne = N/3;
    int rem = N % 3;


    
}



// lug ≥ naak ≥ nemege
// min lug + nemege

