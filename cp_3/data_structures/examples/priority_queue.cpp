#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void) {
    int money;
    char name[20];
    priority_queue< pair<int, string> > pq; // pair is a pair of 2 variables
    pair<int, string> result;

    // suppose we enter these 7 money-name pairs below
    /*
    100 john
    10 billy
    20 andy
    100 steven
    70 felix
    2000 grace
    70 martin
    */
   pq.push(make_pair(100, "john"));  // inserting a pair O(log n)
   pq.push(make_pair(10, "billy"));
   pq.push(make_pair(20, "andy"));
   pq.push(make_pair(100, "steven"));
   pq.push(make_pair(70, "felix"));
   pq.push(make_pair(2000, "grace"));
   pq.push(make_pair(70, "martin"));


    // priority queue will arange items in 'heap' based
    // on the first key in pair, which is money (int), largest first
    // if first keys tie, use second key which is name, largest first

    // the internal content of pq heap MAY be something like this:
    // re-read (max) heap concept if you do not understand this diagram
  // the primary keys are money (integer), secondary keys are names (string)!
  //                        (2000,grace)
  //           (100,steven)               (70,martin)   
  //     (100,john)   (10,billy)     (20,andy)  (70,felix)

  // print out the top 3 person w/ most money
  result = pq.top(); // which is a pair, O(1) to access top elem
  pq.pop(); // remove from top, O(log n) to delete and repair
  printf("%s has %d\n", ((string) result.second).c_str(), result.first);
  result = pq.top(); pq.pop();
  printf("%s has %d\n", ((string) result.second).c_str(), result.first);
  result = pq.top(); pq.pop();
  printf("%s has %d\n", ((string) result.second).c_str(), result.first);

}