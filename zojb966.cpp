#include<iostream>
#include<algorithm>
using namespace std;
#define maxN 10010

int id[maxN<<1];
int pos[maxN<<1];
int type[maxN<<1];
int rear=0;

inline bool cmp( int a, int b)
{
	return (pos[a]==pos[b])? type[a]>type[b] : pos[a]<pos[b];
}

int main() {
	int n;
	cin >> n;
	for( int i=0; i<n; i++)
	{
		id[rear]=rear;
		cin >> pos[rear];
		type[rear]=1;
		rear++;
		id[rear]=rear;
		cin >> pos[rear];
		type[rear]=-1;
		rear++;
	}
	sort( id, id+rear, cmp);
	
	int cnt=0, l=pos[id[0]], sum=0;
	for( int i=0; i<rear; i++)
	{
		cnt+=type[id[i]];
		if (cnt==0)
		{
			sum += pos[id[i]]-l;
			l=pos[id[i+1]];
		}
	}
	
	cout << sum << '\n';
	
	return 0;
}
