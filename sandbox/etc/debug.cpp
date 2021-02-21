#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <iomanip>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A,B> &p) {return os << '(' << p.first << ", " << p.second << ')'; }
// template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_Type>::type> ostream& operator<<()

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr < ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cer << "(" << #__VA__ARGS__ << "): ", dbg_out(__VA_ARGS__)
#else


#define dbg(...)
#endif