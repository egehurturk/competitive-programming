#include <cstdio>
#include <map>
#include <set>
#include <string>
using namespace std;

int main(void) {
    char name[20];
    int value;

    set<int> used_values; // used_values.clear()
    map<string, int> mapper; // mapper.clear()'

    /*
    Data:
    ====
    john 78
    billy 69
    andy 80
    steven 77
    felix 82
    grace 75
    martin 81

    */
   // python dictinonary like syntax for mapper
   // insert to a set with insert method
   mapper["john"] = 78;   used_values.insert(78);
   mapper["billy"] = 69;  used_values.insert(69);
   mapper["andy"] = 80;   used_values.insert(80);
   mapper["steven"] = 77; used_values.insert(77);
   mapper["felix"] = 82;  used_values.insert(82);
   mapper["grace"] = 75;  used_values.insert(75);
   mapper["martin"] = 81; used_values.insert(81); 

   // BST tree for map may look like this:
   //                        (grace,75) 
   //           (billy,69)               (martin,81)   
   //     (andy,80)   (felix,82)    (john,78)  (steven,77)

   // where grades are placed as in the principle of BST
   //   left -> smaller, right -> greater or equal
   
   // special syntax
   for (map<string, int>::iterator it = mapper.begin(); it != mapper.end(); it++) {
       printf("%s %d\n", ((string)it -> first).c_str(), it->second);
   }

   // a map can also be used like this
   printf("steven's socre is %d, grace's score is %d\n",
        mapper["steven"], mapper["grace"]);
   printf("=======================\n");

   // interesting usage of lower_bound and uppper_bound
   // display data between ["f" ... "m") where felix is included but martin is not
   // here, c_str() is used for backwards compatibility w/ c
   for (map<string, int>::iterator it = mapper.lower_bound("f"); it != mapper.upper_bound("m"); it++) {
       printf("%s %d\n", ((string) it->first).c_str(), it->second);
   }

   // the internal content of used_values MAY be something like this
  // the keys are values (integers)!
  //                 (78) 
  //         (75)            (81)   
  //     (69)    (77)    (80)    (82)

  // O(log n) search, found
  printf("%d\n", *used_values.find(77));
  // retunrs [69, 75] (these two are before 77 in the inorder traversal of this BST)
  for (set<int>::iterator it = used_values.begin(); it != used_values.lower_bound(77); it++) {
      printf("%d\n", *it);
  }
  printf("\n");

  // returns [77, 78, 80, 81, 82] (these five are equal or after 77)
  for (set<int>::iterator it = used_values.lower_bound(77); it != used_values.end(); it++) {
      printf("%d\n", *it);
  }
  printf("\n");

  // O(log n) search
  if (used_values.find(79) == used_values.end()) 
    printf("79 not found\n");


}
