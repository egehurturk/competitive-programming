#include <bits/stdc++.h>
using namespace std;


class Hash
{
    int BUCKET;    // No. of buckets
 
    // Pointer to an array containing buckets
    list<long> *table;
public:
    Hash(long V);  // Constructor
 
    // inserts a key longo hash table
    void insertItem(long x);
 
    // deletes a key from hash table
    void deleteItem(long key);
 
    // hash function to map values to key
    long hashFunction(long x) {
        return (x % BUCKET);
    }

    bool exists(long x);
 
    void displayHash();
};
 
Hash::Hash(long b)
{
    this->BUCKET = b;
    table = new list<long>[BUCKET];
}

bool Hash::exists(long x) {
   long ind = hashFunction(x);
   if (table[ind]) 
}
 
void Hash::insertItem(long key)
{
    long index = hashFunction(key);
    table[index].push_back(key);
}
 
void Hash::deleteItem(long key)
{
  // get the hash index of key
  long index = hashFunction(key);
 
  // find the key in (index)th list
  list <long> :: iterator i;
  for (i = table[index].begin();
           i != table[index].end(); i++) {
    if (*i == key)
      break;
  }
 
  // if key is found in hash table, remove it
  if (i != table[index].end())
    table[index].erase(i);
}
 
// function to display hash table
void Hash::displayHash() {
  for (int i = 0; i < BUCKET; i++) {
    cout << i;
    for (auto x : table[i])
      cout << " --> " << x;
    cout << endl;
  }
}

int main(){
	// Answer : 427
	// Expected Running time : <2secs
	// O(n log n) solution
    std::ifstream infile("integers.txt");
    long long a[1000005]={0};
	long long in;
	int i = 0;
	while (infile >> in)
		a[i++] = in;
	int size = i;

    Hash h(size);

    for (int i = 0; i < size; i++) 
        h.insertItem(a[i]);
	
    for (long t = -10000; t <= 10000; t++) {
        for (long i = 0; i < size; i++) {

        }
    }

}