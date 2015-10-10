//#define READ_NUM_TEST_CASES
//#define FASTIO

#include <templates/my.h>

#include <atablash/linalg/2/vector.hpp>
#include <atablash/linalg/2/matrix.hpp> // for orient()
#include <atablash/convex-hull.hpp>
#include <atablash/hash.hpp>

// input
vector<v2i> cheese;
vector<v2i> peppers;

void read_input(){
	int n = ri;
	cheese.resize(n);
	FOR(i,n){
		int x = ri, y = ri;
		cheese[i] = {x,y};
	}
	
	int m = ri;
	peppers.resize(m);
	FOR(i,m){
		int x = ri, y = ri;
		peppers[i] = {x,y};
	}
}


ll solve(){
	vector<v2i> hull = convexHull(peppers.be, peppers.en);
	
	H1X h(hull.siz, 0);
	while(orient(cheese[0], hull[h], hull[h+1]) > 0) ++h;
	
	ll result = 0;
	ll cand = 0;
	H1X c2(cheese.siz, 1);
	FOR(c,cheese.siz){
		while(orient(cheese[c], hull[h], hull[h+1]) < 0) ++h;
		while(orient(cheese[c], hull[h], cheese[c2+1]) < 0){
			cand += orient(cheese[c], cheese[c2], cheese[c2+1]);
			++c2;
		}
		remax(result, cand);
		cand -= orient(cheese[c], cheese[(c+1)%cheese.siz], cheese[c2]);
	}
	
	return result;
}


void tc(){
	read_input();
	O < solve() < NL;
}

