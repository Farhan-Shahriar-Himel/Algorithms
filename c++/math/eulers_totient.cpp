#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sq(n) (n)*(n)

const int N = 5e6 + 2;
int phi[N];

void calculate()
{
    for (int i = 2; i <= N; i++) phi[i] = i;
    
    for (int i = 2; i <= N; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= N; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int32_t main()
{
    calculate();
    
    for (int i = 2; i <= 20; i++)
    {
        cout << "Total relateive prime number of " << i << " is ---> " << phi[i] << endl;
    }    
    return 0;
}