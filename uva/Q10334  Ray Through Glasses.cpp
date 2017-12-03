#include<iostream>
#include<string>

using namespace std;

string add(string a,string b)
{
	
	int carry=0,i,j;

	if(a.size()<b.size())	a.swap(b);

	string tmp(a);

	for(i = a.size()-1 , j = b.size()-1 ; i>=0 && j>=0 ; --i , --j)
	{
		tmp[i] = (a[i] - '0' + b[j] - '0' + carry)%10+'0';
		carry = (a[i] - '0' + b[j] - '0' + carry )/10; 
	}

	for( ; i>=0 ; --i )
	{
		tmp[i] = (a[i] - '0' + carry)%10+'0';
		carry = (a[i] - '0' + carry)/10;
	}


	if(carry  )	tmp.insert(tmp.begin(),'1');

	return tmp;
}

int main()
{
	string arr[1001] = {"1","2"};
	int n;

	for(int i = 2 ; i < 1001 ; ++i )
	{
		arr[i] = add(arr[i-1],arr[i-2]);
	}

	while(cin>>n)
	{
		cout<<arr[n]<<endl;
	}
}