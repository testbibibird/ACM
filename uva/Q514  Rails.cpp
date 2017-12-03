#include<iostream>
#include<stack>
#include<vector>
#include<deque>

using namespace std;

int main()
{
	int tmp[1000]={},n,* arr,l;
	bool key ;
	//vector<int> arr(100,1);

	for(int i = 0 ; i < 1000 ; ++i )
	{
		tmp[1000-i-1] = i + 1 ;
	}

	while(cin>>n)
	{
		if(n==0)	break;

		deque<int> d(tmp+1000-n,tmp+1000);

		arr = new int [n];

		while(cin>>arr[0])
		{
			if(arr[0]==0)	break;
		
			stack<int> a(d);
			stack<int> b;
			l=0;

			for(int i = 1 ; i < n ; ++i )	cin>>arr[i];

			/*b.push( a.top() );
			a.pop();*/

			while(1)
			{

				if( !b.empty() && !a.empty() )
				{

					if( b.top() == arr[l] )
					{
						++l;
						b.pop();
					}
					else
					{
						b.push( a.top() );
						a.pop();
					}
				}
				else	if( b.empty() && !a.empty())
				{
					b.push( a.top() );
					a.pop();
				}
				else	if( !b.empty() && a.empty() )
				{
					if( b.top() == arr[l] )
					{
						++l;
						b.pop();
					}
					else
					{
						key = false;
						break;
					}
				}

				if(l==n)	
				{
					key = true;
					//cout<<'x'<<l<<endl;
					break;
				}
			}

			if(key)	cout<<"Yes"<<endl;
			else	cout<<"No"<<endl;
		}
		delete [] arr;

		//for( ; !a.empty() ;	a.pop() )	cout<<a.top();
		cout<<endl;
	}
	
}