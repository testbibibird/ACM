#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<iomanip>

using namespace std;

vector<string> v;
vector<vector<int> > v2;

void DFS(int x,int y,char c,int count)
{
	if(x>=0 &&  x <v.size()  )
	{
		if(y>=0 && y < v[x].size() )
		if(v[x][y]==c)
		{
			v[x][y]=0;
			v2[x][y]=count;
			DFS(x,y+1,c,count);
			DFS(x+1,y+1,c,count);
			DFS(x+1,y,c,count);
			DFS(x+1,y-1,c,count);
			DFS(x,y-1,c,count);
			DFS(x-1,y-1,c,count);
			DFS(x-1,y,c,count);
			DFS(x-1,y+1,c,count);
		}
	}
}

int main()
{
		string in;
		char x;
		int count,w1,count1;

		while(getline(cin,in))
		{
			v.push_back("");
			//v2.push_back("");
			count=1;
			count1=0;

			istringstream input(in);

			while(input>>x)
			{
				v.back().push_back(x);
			}
			

			while(getline(cin,in))
			{
				if(in=="%")	break;

				v.push_back("");
	
				istringstream input(in);

				while(input>>x)
				{
					v.back().push_back(x);
				}	
			}

			v2.resize(v.size());
			for(int i = 0 ; i < v.size() ; ++i )
			{
				v2[i].resize(v[i].size(),0);
			}
		/*	for(int i = 0 ; i < v.size() ; ++i )
			{
				for(int j = 0 ; j < v[i].size() ; ++j )
				{
					cout<<v2[i][j]<<' ';
					//if( isalpha(v[i][j]) )	
					{
					//	DFS(i,j,v[i][j],count++);
					}
				}cout<<endl;
			}*/

			for(int i = 0 ; i < v.size() ; ++i )
			{
				for(int j = 0 ; j < v[i].size() ; ++j )
				{
					if( isalpha(v[i][j]) )	
					{
						DFS(i,j,v[i][j],count++);
					}
				}
			}

			vector<int> w;
			
			for(int j = 0 ; j < v[0].size() ; ++j )
			{
				count1=0;
				for(int i = 0 ; i < v.size() ; ++i )
				{
					if(v2[i][j]>count1)	count1 = v2[i][j];
				}
				
				for( w1 = 0 ; count1>0 ; ++w1,count1/=10){}
				//cout<<w1<<' ';
				w.push_back(w1);
			}


			//for( w = 0 ; count>0 ; ++w , count/=10){}
			
			
			//cout.setf(ios::fixed);
			//cout.width(w);

			for(int i = 0 ; i < v.size() ; ++i )
			{
				cout<<setiosflags(ios::right)<<setw(w[0])<<static_cast<int>(v2[i][0]);
				//cout<<static_cast<int>(v2[i][0]);

				for(int j = 1 ; j < v[i].size() ; ++j )
				{
				//	cout.width(w+1);
				//	cout.fill('0');
					cout<<setiosflags(ios::right)<<setw(w[j]+1)<<static_cast<int>(v2[i][j]);
				}
				cout<<endl;
			}
			cout<<'%'<<endl;
			v.clear();
			v2.clear();
		}
}