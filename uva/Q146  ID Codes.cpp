#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	bool key;
	string a;

	while(cin>>a)
	{
		if(a=="#")	break;

		key = next_permutation( a.begin() , a.end() );
	
		if(key)	cout<<a<<endl;
		
		else	cout<<"No Successor"<<endl;
	}
}