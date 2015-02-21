#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std ;

int h , w ;

int solve(int x , int y , vector < vector <int> >& chamber , vector < vector <int> >& ans) {
	//cout << x << " , " << y << endl ;
	if(x < 0 || x >= h || y < 0 || y >= w)
		return 0 ;
	if(ans[x][y] == -1) {
		ans[x][y] = chamber[x][y] + max(max(solve(x + 1 , y - 1 , chamber , ans) , solve(x + 1 , y , chamber , ans)) , solve(x + 1 , y + 1 , chamber , ans)) ;
	}
	return ans[x][y] ;
}

int main() {
	int T ;
	scanf("%d" , &T) ;
	while(T--) {
		scanf("%d %d" , &h , &w) ;
		vector < vector <int> > chamber(h , vector <int>(w)) ;
		vector < vector <int> > ans(h , vector <int>(w , -1)) ;
		for(int i = 0 ; i < h ; i++)
			for(int j = 0 ; j < w ; j++)
				scanf("%d" , &chamber[i][j]) ;
		int count = -1 ;
		for(int j = 0 ; j < w ; j++)
			count = max(count , solve(0 , j , chamber , ans)) ;
		printf("%d\n" , count) ;
	}
}