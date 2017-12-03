/*
 * Q10360.cpp
 *
 *  Created on: 2016¦~10¤ë18¤é
 *      Author: bobo
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include<memory.h>


using namespace std;


struct site{
	int x,y,population;
};

struct myclass {
  bool operator() (site l,site r) {
	  if (l.x == r.x ) {
		  return l.y < r.y;
	  }
	  return ( l.x < r.x );
  }
} myobject;
	int dp[1026][1026] ={};
int main() {


	int case_num = 0, n;
	int d, max_x, max_y, ans, final_x, final_y;

	cin>>case_num;

	while(case_num--) {
		max_x = 0;
		max_y = 0;
		final_x = 0;
		final_y = 0;
		ans = 0;
		site input_site;
		std::vector<site> v;
		memset(dp, 0, sizeof(dp));


		cin>>d;
		cin>>n;


		for(int i = 0 ; i < n ; ++i ){
			cin>>input_site.x>>input_site.y>>input_site.population;
			dp[input_site.x][input_site.y] = input_site.population;
			v.push_back ( input_site );
			max_x = max(max_x,input_site.x);
			max_y = max(max_y,input_site.y);
		}


		for(int i = 1 ; i <= max_x ; ++i ) {
			for(int j = 1 ; j <= max_y ; ++j ){
					dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			}
		}

		for(int i = 1  ; i <= max_x ; ++i ) {
			for(int j = 1  ; j <= max_y ; ++j ){

				int up = max(i-2*d-1,0);
				int left = max(j-2*d-1,0);

				int local_sum = dp[i][j] - dp[up][j] - dp[i][left]+ dp[up][left];

				if(local_sum > ans ) {
					ans = local_sum;
					final_x = max(i-d,1);
					final_y = max(j-d,1);
				}

			}
		}
		cout<<final_x<<' '<<final_y<<' '<<ans<<endl;

	}
}
