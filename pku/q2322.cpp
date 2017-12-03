#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

char c[12][12]={},seq[11]={};
int n,arr[20]={},dir[11]={},num[11]={};
bool used[20]={},rs[12][12]={},key;
vector<int> v;

void DFS(int x,int y,int count,int d)
{
	
	if(x>0 && y>0 && x<11 && y<11 && c[x][y] == '*' && !key )
	{
		dir[count] = d;

		if(x==10&&y==10)	
		{	
			//for(int i = 0 ; i < v.size() ; ++i )	cout<<dir[i]<<' ';
			key = true;
		}

		if(  count==n || key  )	return;
		
		for(int i = 0 ; i < n && !key ; ++i )
		{
			
			if( !used[i] )
			{
	
				used[i] = true;
				seq[count] = arr[i];
				num[count]=i+1;

	
				if(d!=3)	DFS( x+arr[i] , y , count+1 , 1 );
				if(d!=4)	DFS( x , y+arr[i] , count+1 , 2 );
				if(d!=1)	DFS( x-arr[i] , y , count+1 , 3 );
				if(d!=2)	DFS( x , y-arr[i] , count+1 , 4 );

				used[i] = false;
			}
			
		}
	}
}
int main()
{
	int x,y,count=0;

	for(int i = 1 ; i <= 10 ; ++i )
	{
		for(int j = 1 ; j<= 10 ; ++j )
		cin>>c[i][j];
	//	cout<<c[i]<<endl;
	}

	while(cin>>n)
	{	
		//if(count!=0)	cout<<endl;
		//++count;

		memset(rs,0,12*12);
		memset(seq,0,11*4);
		x=y=1;

		for(int i = 0 ; i < n ; ++i )	cin>>arr[i];
	
		key = false;
		v.push_back(0);
		
		//for(int i = 0 ; i < n ; ++i	)	cout<<arr[i];
		
		DFS(1,1,0,0);

		

		if(key)
		{	

			for(int i = 0 ;  !(x==10&&y==10); ++i )
			{
				//cout<<dir[i]<<' ';
				//cout<<v[i]<<' ';
				if(dir[i+1]==1)
				{
					x+=seq[i];
				}
				if(dir[i+1]==2)
				{
					y+=seq[i];
				}
				if(dir[i+1]==3)
				{
					x-=seq[i];
				}
				if(dir[i+1]==4)
				{
					y-=seq[i];
				}
				cout<<"place plank "<<num[i]<<" to stump ("<<x<<","<<y<<")"<<endl;
				
			}
			
		}
		else	cout<<"no solution possible"<<endl;

		cout<<endl;
		v.clear();
	}
}