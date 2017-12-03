#include<iostream>

using namespace std;

int main()
{
	int arr[101][101]={},c,s,q,c1,c2,d,count=1;

	while(cin>>c>>s>>q)
	{
		if(c==0 && s==0 && q==0)	break;

		if(count!=1)	cout<<endl;

		memset(arr,1,101*101*4);
		for(int i = 0 ; i < s ; ++i )
		{
			cin>>c1>>c2>>d;
			arr[c1][c2] = d;
			arr[c2][c1] = d;
		//	arr[i+1][i+1] = 0;
		}
		for(int i = 1 ; i <= c ; ++i )	arr[i][i] = 0 ;

		for(int k = 1 ; k <= c ; ++k )
		{
			for(int i = 1 ; i <= c ; ++i )
			{
				for(int j = 1 ; j <= c ; ++j )
				{
						arr[i][j] = min(arr[i][j], max(arr[i][k],arr[k][j]));
				}
			}
		}

		cout<<"Case #"<<count++<<endl;

		for(int i = 0 ; i < q ; ++i )
		{
			cin>>c1>>c2;
			if(arr[c1][c2]==16843009)
				cout<<"no path"<<endl;
			else
				cout<<arr[c1][c2]<<endl;
		}
	}
}