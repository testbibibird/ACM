#include<iostream>
#include<string>

using namespace std;

string add(string a,string b)
{
	string tmp(a);
	int carry=0,i,j;

	for(i = a.size()-1 , j = b.size()-1 ; i>=0 && j>=0 ; --i , --j)
	{
		tmp[i] = (a[i] - '0' + b[j] - '0' + carry)%10+'0';
		carry = (a[i] - '0' + b[j] - '0' + carry )/10; 
	}

	for( ; i>=0 ; --i )
	{
		tmp[i] = (a[i] - '0' + carry)%10+'0';
		carry = (a[i] - '0' + carry)/10+'0';
	}


	if(carry && a.size() == b.size() )	tmp.insert(tmp.begin(),'1');

	return tmp;
}

int main()
{
	int n;
	string arr[251]={"1","1","3","5"};

	for(int i = 4 ; i < 251 ; ++i )
	{
		arr[i] = add(add(arr[i-1],arr[i-2]),arr[i-2]);
	}

	while(cin>>n)
	{
		cout<<arr[n]<<endl;
	}
}
