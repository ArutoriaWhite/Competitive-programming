#include<memory.h>
#define maxN (5000+10)

bool in1[maxN], in2[maxN];
int A, stk1[maxN], stk2[maxN], r1, r2, n;

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
			pop();
		else
			return 0;
	}
	return 1;
}

void solve(int N, int order[])
{
	n = N;
	ini();
	for (int i=0; i<N; i++)
	{
		if (!ask2(order[i]))
		{
			no_solution();
			return;
		}
	}
}

