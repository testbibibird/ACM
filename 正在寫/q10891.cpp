#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int arr[101],n,a,b,i,j,l,r,tmpl,tmpr;
	bool key;

	while(cin>>n)
	{
		if(n==0)	break;

		for( i = 0 ; i < n ; ++i )	cin>>arr[i];

		l=0;
		r=n;
		a=b=0;
		key = true;

		while( l < r )
		{
			tmpl = tmpr = 0;

			for( i = l ; i < r && tmpl + arr[i] >= tmpl ; ++i )
			{
				tmpl += arr[i];
			}
			if(i==l)
			{
				tmpl = arr[l];
				++i;
			}
			for( j = r - 1 ; j >= l && tmpr + arr[j] >=tmpr ; --j )
			{
				tmpr += arr[j];
			}
			if(j==r-1)
			{
				tmpr=arr[j];
				--j;
			}
			if(tmpl>tmpr)
			{
				if(key)	a+=tmpl;
				else	b+=tmpl;
				l=i;
			}
			else
			{
				if(key)	a+=tmpr;
				else	b+=tmpr;
				r=j+1;
			}

			key = !key;
			
			cout<<a<<' '<<b<<' '<<tmpl<<' '<<tmpr<<endl;
		}

		cout<<a-b<<endl;
	}
}