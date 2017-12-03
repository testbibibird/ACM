/*
 * Q11636.cpp
 *
 *  Created on: 2016¦~10¤ë21¤é
 *      Author: bobo
 */

#include<iostream>
#include<cmath>

using namespace std;



int main(){

	int n , case_num = 1;

	while(cin>>n){
		if(n < 0) break;

		cout<<"Case "<<case_num++<<": "<<ceil(log2(n))<<endl;

	}
}


