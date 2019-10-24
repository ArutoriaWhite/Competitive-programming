#include<iostream>
using namespace std;
#define maxN 1000010

int n, m, k;
int f( int n, int k)
{
	if (k==0) return 0;
	return (f(n-1,k-1)+m%n)%n;

}

int main() {
	cin >> n >> m >> k;
	cout << f( n, k)+1 << '\n';
	return 0;
}
