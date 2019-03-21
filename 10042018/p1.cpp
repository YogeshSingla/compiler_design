#include <bits/stdc++.h>
using namespace std;

const clock_t c_time = clock();
void swap(char &a, char &b)
{
	char c = a;
	a = b;
	b = c;
}
void convert_to_binary(int n)
{
	int bin = 0;
	int r = 0;
	int place = 1;
	while(n)
	{
		r = n%2;
		bin = r*place + bin;
		n >>= 1;
		place *= 10;
	}
	cout<<"Equivalent binary string is "<<bin<<"\n";
	cout<<"Output derived in "<<float( clock () - c_time ) /  CLOCKS_PER_SEC<<"ms\n";
}
int main()
{
	int n;
	cout<<"Enter the number in decimal: \n";
	cin>>n;
	cout<<"\nYou entered "<<n;
	convert_to_binary(n);
	return 0;
}