/* Generate Prime no.s within a range */
/* Use Sieve of Atkin */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	//int n;
	int t;
	cin >> t;
	while(t-- > 0) {
		long long m,n;
		cin >> m >> n;
		int *sieve = new int[n-m+1];
		for(long long i=m; i<=n; i++) {
			sieve[i-m] = 0;
		}
		//sieve[2] = sieve[3] 
		long limit = (long)sqrt((double)n);
		for (long long x = 1; x <= limit; x++) {
			for (long long y = 1; y <= limit; y++) {
				// first quadratic using m = 12 and r in R1 = {r : 1, 5}
				long long idx = (4 * x * x) + (y * y);
				if ((idx >=m && idx <= n) && (idx % 12 == 1 || idx % 12 == 5)) {
					sieve[idx-m] = !sieve[idx-m];
				}
				// second quadratic using m = 12 and r in R2 = {r : 7}
				idx = (3 * x * x) + (y * y);
				if ((idx >=m && idx <= n) && (idx % 12 == 7)) {
					sieve[idx-m] = !sieve[idx-m];
				}
				// third quadratic using m = 12 and r in R3 = {r : 11}
				idx = (3 * x * x) - (y * y);
				if (x > y && (idx >=m && idx <= n) && (idx % 12 == 11)) {
					sieve[idx-m] = !sieve[idx-m];
				} // end if
				// note that R1 union R2 union R3 is the set R
				// R = {r : 1, 5, 7, 11}
				// which is all values 0 < r < 12 where r is 
				// a relative prime of 12
				// Thus all primes become candidates
			} // end for
		} // end for
		// remove all perfect squares since the quadratic
		// wheel factorization filter removes only some of them
		for (long long j = m; j <= limit; j++) {
			if (sieve[j-m]) {
				long long x = j * j;
				for (long long i = x-m; i <= n; i += x) {
					sieve[i] = 0;
				} // end for
			} // end if
		}
		if (m<3)
			cout << 2 << endl << 3<<endl;
		if (m==3)
			cout << 3 <<endl;
		for (long long j = m; j <= n; j++) {
			if (sieve[j-m]) {
				cout << j << endl;
			} // end if
		}
		cout << endl;
	}

	return 0;
}
