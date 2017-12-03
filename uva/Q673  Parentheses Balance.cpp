#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
	
	string a;
	int key=1,n;

	cin>>n;

	getline(cin,a);

	while(n--)
	{
		getline(cin,a);

		key=1;
		stack<char> par;

		if(a.size()==0)	
		{
			cout<<"Yes"<<endl;
			continue;
		}

		for(int i=0; i<a.size() && key==1 ;++i)
		{
			//if(!par.empty())cout<<'x';//par.top();


			if( a[i] == '(' || a[i] == '[' )
			{
				par.push(a[i]);
			}
			else
			{
				if(a[i]==')')
				{
					if( par.empty() || par.top() != '(' )
					{
						//cout<<par.top();

						key=0;
					}
					else par.pop();
				}

				if(a[i]==']')
				{
					if( par.empty() ||  par.top() != '[' )
					{
						//cout<<par.top();	

						key=0;
					}
					else par.pop();
				}
			}
		}

		if(!par.empty())	key=0;


		if(key)	cout<<"Yes"<<endl;
		else	cout<<"No"<<endl;
	}
}
