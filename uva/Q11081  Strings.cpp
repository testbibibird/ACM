#include<iostream>
#include<string>

using namespace std;

int arr[3][61][61][61]={};
bool used[3][61][61][61]={};
string a,b,c;

/*int f(int i,int j,int k);
int f1(int i,int j,int k);
int f2(int i,int j,int k);

int f(int i,int j,int k)
{
	if( k==-1 )	return 1;

	//cout<<"f "<<i<<' '<<j<<' '<<k<<endl;

	return f1( i , j , k ) + f2( i , j , k );
}

int f1(int i,int j,int k)
{
	if( i < 0  )	return 0;

	//cout<<"f1 "<<i<<' '<<j<<' '<<k<<endl;

	if( a[i] == c[k] )	return f1( i-1 , j , k ) + f( i-1 , j , k-1 ) ;

	else return f1( i-1 , j , k );
}

int f2(int i,int j,int k)
{
	if( j < 0  )	return 0;

	//cout<<"f2 "<<i<<' '<<j<<' '<<k<<endl;
	 
	if( b[j] == c[k] )	return f2( i , j-1 , k ) + f( i , j-1 ,k-1 );

	else return f2( i , j-1 , k );
}*/

int main()
{
	
	int case_num;
	cin>>case_num;

	while(case_num--)
	{
		memset(arr,0,3*61*61*61*4);
		memset(used,0,3*61*61*61);

		cin>>a>>b>>c;

		for(int i = 0 ; i <= a.size() ; ++i )
		{
			for(int j = 0 ; j <= b.size() ;++j )
			{
				if(	j==0 && i ==0 )
				{
					arr[1][0][i][j] = 0 ;
					arr[2][0][i][j] = 0 ;
					arr[0][0][i][j] = 0 ;
					continue;
				}

				if( j==0 )
				{
					if( a[i-1] == c[0] )
					{
						arr[1][0][i][j] = arr[1][0][i-1][j] + 1;
					}
					else
					{
						arr[1][0][i][j] = arr[1][0][i-1][j];
					}

					arr[0][0][i][j] = ( arr[1][0][i][j] + arr[2][0][i][j] ) % 10007;
					continue;
				}

				if( i==0 )
				{
					if( b[j-1] == c[0] )
					{
						arr[2][0][i][j] = arr[2][0][i][j-1] + 1 ;
					}
					else
					{
						arr[2][0][i][j] = arr[2][0][i][j-1] ;
					}
					arr[0][0][i][j] = ( arr[1][0][i][j] + arr[2][0][i][j] ) % 10007 ;
					continue;
				}


				if( a[i-1] == c[0] )
				{
					arr[1][0][i][j] = arr[1][0][i-1][j] + 1;
				}
				else
				{
					arr[1][0][i][j] = arr[1][0][i-1][j];
				}
				if( b[j-1] == c[0] )
				{
					arr[2][0][i][j] = arr[2][0][i][j-1] + 1 ;
				}
				else
				{
					arr[2][0][i][j] = arr[2][0][i][j-1] ;
				}

				arr[0][0][i][j] = ( arr[1][0][i][j] + arr[2][0][i][j] ) % 10007 ;

			//	cout<<a[i-1]<<' '<<c[0]<<endl;
			}
		}

	/*	for(int i = 1 ; i <= a.size() ; ++i )
		{
			for(int j = 1 ; j <= b.size() ; ++j )
			{
				cout<<arr[0][0][i][j]<<' ';
			}cout<<endl;
		}*/

		for( int k = 1 ; k < c.size() ; ++k )
		{
			for(int i = 0 ; i <= a.size() ; ++i )
			{
				for(int j = 0 ; j <= b.size() ; ++j )
				{
					if(	j==0 && i ==0 )
					{
						arr[1][k][i][j] = 0 ;
						arr[2][k][i][j] = 0 ;
						arr[0][k][i][j] = 0 ;
						continue;
					}

					if( j==0 )
					{
						if( a[i-1] == c[k] )
						{
							arr[1][k][i][j] = ( arr[1][k][i-1][j] + arr[0][k-1][i-1][j] ) % 10007 ;
						}
						else
						{
							arr[1][k][i][j] = arr[1][k][i-1][j];
						}

						arr[0][k][i][j] = ( arr[1][k][i][j] + arr[2][k][i][j] ) %10007 ;
						continue;
					}

					if( i==0 )
					{
						if( b[j-1] == c[k] )
						{
							arr[2][k][i][j] = ( arr[2][k][i][j-1] +  arr[0][k-1][i][j-1] ) % 10007 ;
						}
						else
						{
							arr[2][k][i][j] = arr[2][k][i][j-1] ;
						}
						arr[0][k][i][j] = ( arr[1][k][i][j] + arr[2][k][i][j] ) % 10007 ;
						continue;
					}

					if( a[i-1] == c[k] )
					{
						arr[1][k][i][j] = ( arr[1][k][i-1][j] + arr[0][k-1][i-1][j] ) % 10007 ;
					}
					else
					{
						arr[1][k][i][j] = arr[1][k][i-1][j];
					}
					if( b[j-1] == c[k] )
					{
						arr[2][k][i][j] = ( arr[2][k][i][j-1] + arr[0][k-1][i][j-1] ) % 10007;
					}
					else
					{
						arr[2][k][i][j] = arr[2][k][i][j-1];
					}

					arr[0][k][i][j] = ( arr[1][k][i][j] + arr[2][k][i][j] ) % 10007 ;
				}
			}
		}

		//cout<<f( a.size()-1  , b.size()-1 , c.size()-1 )<<endl;
		cout<<arr[0][c.size()-1][a.size()][b.size()]<<endl;

		/*for( int k = 0 ; k < c.size() ; ++k )
		{
			for(int i = 1 ; i <= a.size() ; ++i )
			{
				for(int j = 1 ; j <= b.size() ; ++j )
				{
					cout<<arr[0][k][i][j]<<' ';
				}cout<<endl;
			}

			cout<<endl;
		}
		cout<<arr[0][5][3][3]<<' '<<arr[0][4][3][2]<<' '<<arr[0][3][3][1]<<' '<<arr[0][2][3][0]<<' '<<arr[0][1][2][0]<<' '<<arr[0][0][1][0]<<' '<<endl;
		*/
	}
	
}