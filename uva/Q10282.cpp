/*
 * Q10282.cpp
 *
 *  Created on: 2016¦~10¤ë21¤é
 *      Author: bobo
 */

#include<iostream>
#include<map>
#include<string>
#include<sstream>
using namespace std;

int main(){

	string s,key,value;
	map<string,string> dict;
	map<string,string>::iterator it;
	while(getline(cin,s)){
		if(s==""){
			break;
		}
		stringstream ss(s);
		ss>>value>>key;
		dict[key] = value;
	}

	while(cin>>s){
		it = dict.find(s);
		if( it == dict.end() ){
			cout<<"eh"<<endl;
		}else{
			cout<<dict[s]<<endl;
		}

	}

}

