#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        long long *p = new long long[n];
        for(int i=0;i<n;i++)
            cin >> p[i];
        
        long long max = p[n-1];
        long long prof = 0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(max <= p[i])
            {
                max = p[i];    
            }
            prof = prof+max-p[i];
            
        }
        cout << prof << "\n";
        delete [] p;
    
    }
    return 0;
}
