#include<iostream>
#include<string>

using namespace std;

/*string add(string a,string b)
{
	string tmp(a);
	int i,j,carry;
	
	if(a.size()<b.size())	a.swap(b);

	carry=0;

	for( i=a.size()-1 , j = b.size()-1 ; i >= 0 && j >= 0 ; --i , --j )
	{
		tmp[i] = ( a[i] - '0' + b[j] - '0' +carry)%10 + '0' ;
		carry = ( a[i] - '0' + b[j] - '0' +carry)/10;
	//	cout<<static_cast<int> (tmp[i]);
	//	cout<<carry;
	}

	for( ; i >= 0 && carry; --i)
	{
		tmp[i] = (a[i] - '0' + carry)%10 + '0' ;
		carry = ( a[i]-'0' + carry )/10 ;
			
	}

	if(carry)	tmp.insert(tmp.begin(),'1');	
	//cout<<' '<<tmp;
	

	return tmp;
	
}*/
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
	string arr[20000]={"1","1"};

	cout<<1<<endl;

	cout<<1<<' '<<1<<endl;

	for(int i = 2 ; i<205 ; ++i )
	{
		arr[i] = "1";

		for(int j = i-1 ; j > 0 ; --j)
		{
			arr[j] = add(arr[j] , arr[j-1]);
		}

		cout<<arr[0];

		for(int j = 1 ; j <= i ; ++j )	
		{
			cout<<' '<<arr[j];
		//	if(arr[j].size()==61)	{cout<<endl<<'a'<<i<<endl;return 0;		}
		}
		cout<<endl;
	}
}