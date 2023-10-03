#include <iostream>

using namespace std;


int FibonacciVar_0(int n)
{
    if(n<=0)
        return 0;
    if(n==1 || n==2)
        return 1;
    else
    {
      //int a = (FibonacciVar_0(n-1)+FibonacciVar_0(n-2));
      return (FibonacciVar_0(n-1)+FibonacciVar_0(n-2));
    }
}

int main()
{

    int N;
    cin >> N;
	++N;
    //int a = FibonacciVar_0(N);
    cout << FibonacciVar_0(N) << '\n';
    
    return 0;
}