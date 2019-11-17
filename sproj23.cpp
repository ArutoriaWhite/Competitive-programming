h:wq
include<iostream>
using namespace std;

void solve(int N,int order[])
{
	for (int i=0; i<N; i++)
	{
		push_train();
		move_station_1_to_2();
	}
	for (int i=0; i<N; i++)
	{
		pop_train();
	}
}

