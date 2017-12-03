#include<iostream>

using namespace std;

int main()
{
	int start,a,b,c,total;

	while(cin>>start>>a>>b>>c)
	{
		if(a==0&&b==0&&c==0&&start==0)	break;

		total=0;

		if(start<a)
		{
			total+=start+40-a;
		}
		else
		{
			total+=start-a;
		}
		if(a<b)
		{
			total+=b-a;
		}
		else
		{
			total+=b+40-a;	
		}
		if(b<c)
		{
			total+=40-c+b;
		}
		else
		{
			total+=b-c;
		}
		
		cout<<total*9+1080<<endl;
	}
}
