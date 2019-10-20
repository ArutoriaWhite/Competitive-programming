#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for( int i=(a); i<(b); i++)
#define inSet( ele, s) ( s.find( ele) != s.end())

int col[8], amnt= 0;
unordered_set< int> ans_s;

int hash( int *arr){
	int shift = 1, result = 0;
	
	rep( i, 0, 8){
		result += arr[i] * shift;
		shift *= 10;
	}
	return result;
}
bool chk90deg(){
	int newCol_s[8];
	rep( ori_row, 0, 8){
		newCol[ col_s[ ori_row]] = 7-ori_raw;
	}
	return !( inSet( hash( newCol_s));
}
bool chk180deg(){
	int newCol_s[8];
	rep( ori_row, 0, 8){
		newCol[ 7- ori_row] = 7- col_s[ori-row];
	}
	return !( inSet( hash( newCol_s));
	
}
bool chk270deg(){
	int newCol_s[8];
	rep( ori_row, 0, 8){
		newCol[ col_s[ ori_row]] = 7-ori_raw;
	}
	return !( inSet( hash( newCol_s));	
}
bool chkMir(){
	int newCol_s[8];
	rep( ori_row, 0, 8){
		newCol[ col_s[ ori_row]] = 7-ori_raw;
	}
	return !( inSet( hash( newCol_s));	
}

void bt( int cur_row){
	rep( pre_row, 0, cur_row)
		if( col[pre_row] == col[cur_row] || ( cur_row - pre_row) == abs( col[ cur_row] - col[ pre_row]))
			return;
	
	if( cur_row == 7){ amnt++; return; }
	rep( next_col, 0, 8){
		col[ cur_row + 1 ] = next_col;
		bt( cur_row + 1);
	}
}

int main(){
	rep( rt_col, 0, 8){
		col[0] = rt_col;
		bt(0);
	}
	cout << amnt << '\n'; 
}

/*
DFS 是如果可能子節點和當前結點資訊比較有關, 則在當前節點進行篩選,
否則在自結點進入遞迴時 return  
*/ 
