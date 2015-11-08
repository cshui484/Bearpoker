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
#include <math.h>
//#include <gmpxx.h>

//include "Bearpoker.h

using namespace std;
using BNUM = unsigned long long;
	
// -------------
// gcd
// -------------
template <typename T>
T gcd(T a, T b) {
	T t;
	while (b != 0) {
	cout << a << " " << b << " " << t << " " << endl;
		t = b;
		b = a % b;
		a = t; }
	cout << "*" << a << " " << b << " " << t << " " << endl;
	return a; }

// -------------
// lcm
// -------------
template <typename T>
T lcm(T a, T b) {
//	return a * b / gcd(a, b); }
	return a / gcd(a,b) * b; }
	
	
// -------------
// bearpoker_solve
// -------------

void bearpoker_solve (istream& r, ostream& w) {
    int  n;						// n = number of players
    BNUM a, b;					// a is the lcm of processed bets, b is the next bet
    BNUM b1, t;					// tmp var to do lcm
    BNUM q, g, x;				// g = latest gcd, q = quotient, x = tmp variable	
	
	r >> n;
	r >> a;									// get first bet
	for (int i=1; i<n; i++) {		// iterate for the rest of input bets
		r >> b;
//		p = lcm (a, b);
		g = a;
		b1 = b;
		while (b1 != 0) {
			t = b1;
			b1 = g % b1;
			g = t; }

		for (int i=0; i<2; i++) {
			x = (i == 0) ? a : b;
			q = x / g;
/*
			while (q % 65536 == 0) {
				q = q >> 16; }
			while (q % 16 == 0) {
				q = q >> 4; }
*/
			while (q % 2 == 0) {
				q = q >> 1; }
/*			
			while (q % 6561 == 0) {
				q = q / 6561; }
			while (q % 81 == 0) {
				q = q / 81; }
*/
			while (q % 3 == 0) {
				q = q / 3; }
			if (q != 1) {
				w << "No" << endl; 
				return; }}
		a = a / g * b; }
	w << "Yes" << endl; 
/*
p = ULLONG_MAX;
w << p << endl;			
*/

/*
a = 13374150672384;
b = 4782969;
p = a * b;
w << "mul " << p << endl;
p = lcm(a,b);
w << p << endl;
p = a * b;
w << "mul " << p << endl;
p = a / gcd(a,b) * b;
w << "lcm " << p << endl;
*/

}
	
// ----
// main
// ----

int main () {
    using namespace std;
//    cout << "main" << endl;
    bearpoker_solve(cin, cout);
    return 0;}


