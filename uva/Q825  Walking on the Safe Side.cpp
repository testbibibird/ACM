#include<iostream>
#include<string>
#include<sstream>

using namespace std;

bool used[102][102]={};
int road[102][102]={0,1};


int main()
{
	int w,n,num,s,t,count=0;
	bool key;
	string line;

	cin>>num;

	//getline(cin,line);
	//getline(cin,line);
	
	while(num--)
	{
		if(count)	cout<<endl;	
		else	++count;
		//memset(road,0,w*n*4);
		cin>>w>>n;
		
		memset(used,0,102*102);

		getline(cin,line);

		while(getline(cin,line))
		{
			if(line.empty())	break;

			istringstream in(line);

			key = false;

			while(in>>t)
			{
				if(key)	
				{
				//	cout<<s<<' '<<t<<' '<<'x'<<endl;
					used[s][t] = true;
				}
				else
				{
					s=t;
					key = true ;
				}
			}
		}

		for(int i = 1 ; i <= w ; ++i )
		{
			for(int j = 1 ; j <= n ; ++j )
			{
				if(used[i][j])
				{
					road[i][j] = 0 ;
				}
				else
				{
					road[i][j] = road[i-1][j] + road[i][j-1];
				}

				//cout<<road[i][j]<<' ';
			}//cout<<endl;
		}

		cout<<road[w][n]<<endl;
	}
}