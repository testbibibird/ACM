/*
 * Q10019.cpp
 *
 *  Created on: 2016¦~10¤ë21¤é
 *      Author: bobo
 */

#include<iostream>
using namespace std;

int get_num_of_1(int n ){
	int cnt = 0;
	while (n != 0 ){
		cnt += n &1 ;
		n >>= 1;
	}
	return cnt;
}

int main(){
	int case_num;
	int n;

	cin>>case_num;
	while(case_num--){
		cin>>n;


		int hex = n, hex_1_num = 0;
		while(hex) {
			hex_1_num += get_num_of_1(hex % 10) ;
			hex /= 10;
		}

		cout<<get_num_of_1(n)<<' '<<hex_1_num<<endl;
	}
}



