#include<iostream>
#include<memory.h>
using namespace std;
#define maxN (5000+10)

bool in1[maxN], in2[maxN];
int A, stk1[maxN], stk2[maxN], r1, r2, n;

void print()
{
	cout << "A: " << A << '\n';
	
	cout << "1: r:" << r1 << " ::";
	for (int i=0; i<r1; i++)
		cout << stk1[i] << ' ';
	cout << '\n';
	
	cout << "2: r:" << r2 << " ::";
	for (int i=0; i<r2; i++)
		cout << stk2[i] << ' ';		
	cout << "\n\n";
}
void move_station_1_to_2()
{
	cout << "1 to 2\n";
}
void move_station_2_to_1()
{
	cout << "2 to 1\n";
}
void no_solution ()
{
	cout << "no sol\n";	
}
void push_train()
{
	cout << "A to 1\n";
}
void pop_train()
{
	cout << "2 to B\n";
}

inline void ini ()
{
	memset(in1,0,sizeof(in1));
	memset(in2,0,sizeof(in2));
	A=1;
	r1=0;
	r2=0;
}

inline void mv_1_to_2()
{
	in1[stk1[r1-1]] = 0;
	in2[stk1[r1-1]] = 1;
	stk2[r2++] = stk1[--r1];
	move_station_1_to_2();
}
inline void mv_2_to_1()
{
	in2[stk2[r2-1]] = 0;
	in1[stk2[r2-1]] = 1;
	stk1[r1++] = stk2[--r2];
	move_station_2_to_1();
}
inline void push()
{
	in1[A] = 1;
	stk1[r1++] = A++;
	push_train();
}
inline void pop()
{
	cout << "receive " << stk2[r2-1] << '\n';
	in2[stk2[r2-1]] = 0;
	r2--;
	pop_train();
}

bool ask1 (int tar)
{
	if (in1[tar])
	{
		while (stk1[r1-1]!=tar)
			mv_1_to_2();
		mv_1_to_2();
	}
	else if (A<=tar && tar<=n)
	{
		while (A!=tar)
			push();
		push();
		mv_1_to_2();
	}
	else
	{
		return 0;
	}
	return 1;
}

bool ask2 (int tar)
{
	if (in2[tar])
	{
		while (stk2[r2-1]!=tar)
			mv_2_to_1();
		pop();
	}
	else
	{
		if (ask1(tar))
		{
			pop();
			return 1;
		}
		else
		{
			return 0;
		}
	}a
}

void solve(int N, int order[])
{
	n = N;
	ini();
	cout << ask2(1) << ' ';
	cout << ask2(3) << ' ';
	cout << ask2(20) << '\n';
	print();
}

int main()
{
	int n, akagi[maxN];
	while (cin >> n)
	{
		for (int i=0; i<n; i++);
			//cin >> akagi[i];
		solve(n,akagi);
	}
}


// 2 has rec

// ask 2 (tar)
	// if has
		// clear other, give tar
	// else
		// ask 1
		// give tar
	// if failed return 0
	
// ask 1 (tar)
	// if has (x<A.top) 
		// give above && tar
	// else
		// get from a
	// if failed return 0
	
// solve
	// for x in order
		// ask 2(x)
