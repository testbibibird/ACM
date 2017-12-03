#include<iostream>
#include<string>

using namespace std;

int main()
{
	string a,b,*arr;
	int h,w,n,x,y,n2,x2,y2,num,count=1;

	cin>>num;

	while(count<=num)
	{
		cin>>h>>w;
	
		arr= new string [h];

		for(int i = 0 ; i < h ; ++i )	cin>>arr[i];

		cin>>n>>x>>y;



		cout<<"Case "<<count++<<": ";
	}
}