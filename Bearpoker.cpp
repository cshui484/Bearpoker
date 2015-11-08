// ----------------------------
// projects/bearpoker/Bearpoker.c++
// Copyright (C) 2015
// CS Hui
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <deque>
#include <functional>
#include <map>
#include <climits>
#include <set>
#include <vector>
//#include <gmpxx.h>

//include "Bearpoker.h

using namespace std;
//using BNUM = __int128_t;
using BNUM = unsigned long long;
//using BNUM = mpz_t;
	
// -------------
// gcd
// -------------
template <typename T>
T gcd(T a, T b) {
	T t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t; }
	return a; }

// -------------
// lcm
// -------------
template <typename T>
T lcm(T a, T b) {
	return a * b / gcd(a, b); }
	
	
// -------------
// bearpoker_solve
// -------------

void bearpoker_solve (istream& r, ostream& w) {
    int  n;						// n = number of players
    BNUM a, b;					// a is the lcm of processed bets, b is the next bet
    BNUM p, q, x;				// p = latest lcm, q = quotient, x = tmp variable			

/*
mpz_t x, y, result;
mpz_init_set_str(x, "1234567890");
mpz_init_set_str(y, "1234567890");
mpz_init(result);

mpz_mul(result, x, y);
cout << result << endl;
*/

	r >> n;
	r >> a;									// get first bet
	for (int i=1; i<n; i++) {		// iterate for the rest of input bets
		r >> b;
		p = lcm (a, b);
		for (int i=0; i<2; i++) {
			x = (i == 0) ? a : b;
			q = p / x;
			while (q % 2 == 0) {
				q = q >> 1; }
			while (q % 3 == 0) {
				q = q / 3; }
			if (q != 1) {
				w << "No" << endl; 
				return; }}
		a = p; }
	w << "Yes" << endl; 
			
}
	
// ----
// main
// ----

int main () {
    using namespace std;
//    cout << "main" << endl;
    bearpoker_solve(cin, cout);
    return 0;}


