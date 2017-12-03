#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	string n;
	int result=0;
	//int odd=0,even=0;


	while(cin>>n)
	{
		result=0;

		if(n[0]=='0' && n.size()==1)	break;

		for(int i=0;i<n.size();++i)
		{

			if(i%2==0)
			{
				result+=(n[i]-'0');
			}
			else
			{
				result-=(n[i]-'0');
			}

		}

		if(result%11==0)
		{
			cout<<n<<" is a multiple of 11."<<endl;
		}
		else
		{
			cout<<n<<" is not a multiple of 11."<<endl;
		}

	}

	/*char n;
	int odd=0,even=0;
	int count=1;
	

	while(scanf("%c",&n))
	{

		if(n=='0'&&count==1){break;}

		if(n=='\n')
		{
			if(abs(odd-even)%11==0)
			{ 
				cout<<" is a multiple of 11."<<endl;
				count=1; odd=0; even=0;
			}
			else
			{
				cout<<" is not a multiple of 11."<<endl;
				count=1; odd=0; even=0;
			}

		}

		else
		{
		
			cout<<n;
			
			if(count%2==1)
			{
				odd+=n-'0';
				++count;
			}
			else
			{
				even+=n-'0';
				++count;
			}
		}

	}*/
	
}