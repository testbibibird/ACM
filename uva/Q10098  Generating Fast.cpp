#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string a,rs;
bool used[10]={};

void permutation(int k,int n)
{
	char last='\0';

	if(k==n)
	{
		//for(int i = 0 ; i < n ; ++i)
		//	cout<<rs[i];
		cout<<rs<<endl;
		return;
	}
	else
	{
		for(int i = 0 ; i < n ; ++i)
		{
			if(!used[i])
				if(a[i]!=last)
			{
				rs.push_back(a[i]);
				//if(rs.size()<k+1)	
				//else	rs[k]=a[i];
				
				used[i]=true;
				last = a[i];
				permutation(k+1,n);

				used[i]=false;

				rs.erase(rs.size()-1);

				
			}
		}
		
	}

}

int main()
{
	int n ,count=0;

	cin>>n;

	while(n--)
	{
		//if(count!=0)	cout<<endl;
		
		cin>>a;

		sort(a.begin(),a.end());

		permutation(0 , a.size() );

//		++count;
		cout<<endl;
	}
}