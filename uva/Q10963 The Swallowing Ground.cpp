#include<iostream>

using namespace std;


int main()
{
	int c,num,y1,y2,sub,count;

	cin>>c;

	for(int i=0;i<c;++i)
	{

		if(i)	cout<<endl;

		cin>>num;

		count=0;

		cin>>y1>>y2;

		sub=y1-y2;

		for(int j=1;j<num;++j)
		{
			cin>>y1>>y2;

			if(y1-y2!=sub)	
			{
				count++;
			}
		}

		if(count)
		{
			cout<<"no"<<endl;
		}
		else
		{
			cout<<"yes"<<endl;
		}
	}
}
