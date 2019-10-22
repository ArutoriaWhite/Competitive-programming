#include<iostream>
#include<algorithm>
using namespace std;
#define maxN 100000

int id[maxN];
int arr[maxN][2];

inline bool cmp( int a, int b)
{
    return (arr[a][0]==arr[b][0])? arr[a][1]>arr[b][1] : arr[a][0]<arr[b][0];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, rear=0;
    cin >> n;
    for( int i=0; i<n; i++)
    {
        int s, e;
        cin >> s >> e;

        arr[rear][0]=s;
        arr[rear][1]=1;
        id[rear]=rear++;

        arr[rear][0]=e;
        arr[rear][1]=-1;
        id[rear]=rear++;
    }

    for( int i=0; i<rear; i++)
    {
        cout << id[i] << ' ';
    }
    cout << "\n\n";    
    sort(id,id+rear,cmp);
    for( int i=0; i<rear; i++)
    {
        cout << id[i] << ' ';
    }
    cout << '\n';
}
/*
input:
5
160 180
150 200
280 300
300 330
190 210

id[rear]=rear;
rear++;
out:
0 1 2 3 4 5 6 7 8 9

2 0 1 8 3 9 4 6 5 7

///////////////
id[rear]=rear++;
out:
0 0 1 2 3 4 5 6 7 8

2 0 0 1 8 3 4 6 5 7
*/