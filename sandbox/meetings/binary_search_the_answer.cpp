
// Cevaba Binary Search

// Discrete             
// Lower bound var          -> onemli
// Upper bound var          -> onemli
// Eger i gecmiyorsa i'den kucuk hicbir deger gecmez ***

#include <iostream>
#include <vector>

typedef long long int ll;

using namespace std;

vector<ll> distances; // Uzakliklar
vector<ll> gases;   // O noktadaki uzaklik

bool canIpassTheDesertWithThisGivenSize(ll size) {
    ll curSize = min(size, gases[0]);
    for (int i = 0 ; i < distances.size(); i++) {
        if (curSize >= distances[i]) {
            curSize -= distances[i];
            if (i < distances.size() -1) 
                curSize += min(gases[i+1], size-curSize);
        } else {
            return false; // :(((((
        }
    }

    return true;

}


ll binary_search(ll left, ll right) {
    if (left == right)
        return left;

    if (left > right) 
        return -1;
    
    int middle = (left+right)/2;
    if (!canIpassTheDesertWithThisGivenSize(middle)) {
        return binary_search(middle+1, right);
    } else {
        return binary_search(left, middle-1);
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        distances.push_back(val);
    }
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        gases.push_back(val);
    }
    cout << binary_search(1, 1e9) << endl;
}

/*
COLDEYIM

Arabam var
ve benzinim
Ama sinirli 
:((

Guney Afrika CMTinden
Misira
Arabamla 
GIDICEM

Bir kismi col degildi....

Sahranin sinira geldim
OK????????


Sahra boyunca N adet vaha var
Her vahada benzinnn var :))))))

Her benzincide depom kadar benzin alabilirim
Cunku o kadar alabilirim
.

Vahalar arasi uzakliklar bir array'de (n-1) uzunlugunda size veriliyor
Alabilecegim benzin miktari ve vahalar arasi mesafeler <= 10^9
!!!
Boku yedik!!!

Arabamin deposu baslarken min kac olmali ki ben colu gebermeden geciyim


NOT: Algoritma degil bu soru

Ornek input: 
7 <= sehir sayisi
4 5 6 1 2 7 <= sehirler arasi mesafeler
10 3 6 7 8 2 <= son sehir haric benzin miktari

2 2 100000
10 100000 2

Ornek Output:




*/

