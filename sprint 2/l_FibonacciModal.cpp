#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int FibonacciVar_1(int N, int k)
{
    if (N == 0 || N == 1)
    {

        return 1;
    }
    else
    {
        int old = 1;
        int res = 1;
        for (int i = 2; i <= N; ++i)
        {
            int cur = res;
            res = (res + old) % static_cast<int>(std::pow(10, k));
            old = cur;
        }
        return res;
    }
}

int main()
{
    int N, k;
    cin >> N >> k;
    //++N;   
    cout <<  FibonacciVar_1(N, k) << '\n';

	return 0;
}