#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n,count=0,key,i;
	string a,temp;

	cin>>n;

	while(n--)
	{
		if(count)	cout<<endl;
		
		cin>>a;

//		if(count)	cout<<endl;

		key=1;

		for(i=1;i<=(a.size()/2)&&key==1;++i)
		{
			if(a.size()%i==0)
			{
				//a.copy(temp,i,0);
				temp=a.substr(0,i);

				for(int j=0;j<a.size();j+=i)
				{
					if(temp==a.substr(j,i))
					{
						key=0;	
					}
					else
					{
						key=1;
						break;
					}
				}
			}

		}

		if(key)
		{
			cout<<a.size();
		}
		else
		{
			cout<<i-1;
		}
		cout<<endl;

		count++;
		
	}
}
