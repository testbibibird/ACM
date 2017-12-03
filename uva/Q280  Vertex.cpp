#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int n ;
bool* used;
bool** arr;

void DFS(int s)
{
	

	for(int i = 1 ; i <= n ; ++i )
	{
		if( !used[i] && arr[s][i] )	
		{
			used[i] = true;
			//cout<<s<<'y'<<i<<endl;
			DFS(i);
			
		}
	}
}

int main()
{
	string in;
	int s,t,vnum,v,count;

	while(cin>>n)
	{
		if(n==0)	break;
	
		getline(cin,in);

		arr = new bool* [n+1];
		used = new bool [n+1];

		for(int i = 0 ; i < n+1 ; i++ )
		{
			arr[i] = new bool[n+1];
			memset(arr[i],0,n+1);
		}
		
		//memset(arr,0,(n+1)*(n+1));

		while(getline(cin,in))
		{
			if(in=="0")	break;
			//cout<<in<<endl;
			istringstream in2(in);
			in2>>s;

			if(s==0)	break;

			while(in2>>t)
			{	
				if(t==0)	break;
				//cout<<s<<'x'<<t<<endl;
				arr[s][t]=true;
			}
		}

		cin>>vnum;

		for(int i = 0 ; i < vnum ; ++i)
		{
			cin>>v;

			memset(used,0,n+1);

			DFS(v);
			
			count=0;
			//cout<<v;
			for(int i = 1 ; i <= n ; ++i )
			{
				if(!used[i])	++count;
				//cout<<' '<<i;
			}
			cout<<count;

			for(int i = 1 ; i <= n ; ++i )
			{
				if(!used[i])	
				cout<<' '<<i;
			}
			cout<<endl;
		}
	}

}