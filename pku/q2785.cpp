#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long rs;
long long **arr,n;
long long tmp[5];


class node
{
public:
	int* a;//x1,x2,x3,x4;
	
	node()
	{
		a = new int [4];
	}
	~node()
	{
		delete [] a;
	}
	void sort()
	{
		int pivot;

		for(int i = 1 ; i < 4 ; ++i )
		{
			pivot = a[i];
			for(int j = i-1 ; j >= 0 ; --j )
			{
				if( pivot > a[j] ) 
				{
					a[j+1] = pivot;
					break;
				}
				a[j+1] = a[j] ;
			}
		}
	};
};

vector<node> v;

void DFS(int count)
{
	if( count == 4 )
	{
		long long sum1=0,sum2=0;
		node a;

		for(int i = 0 ; i < 3 ; ++i )
		{
			sum1 += tmp[i];//arr[i][tmp[i]];
		}

		//cout<<sum+tmp[3]<<" "<<sum+tmp[4]<<endl;;
		sum2+=tmp[4]+sum1;
		sum1+=tmp[3];
		

		if( sum1==0 )
		{
			a.a[0] = tmp[0];
			a.a[1] = tmp[1];
			a.a[2] = tmp[2];
			a.a[3] = tmp[3];

			a.sort();

			

			for(int i = 0 ; i < v.size() ; ++i )
			{
				
			}
			
			v.push_back(a);
			
			++rs;
		}
		else if(sum2==0)
		{
			a.a[0] = tmp[0];
			a.a[1] = tmp[1];
			a.a[2] = tmp[2];
			a.a[3] = tmp[4];

			a.sort();

			v.push_back(a);

			++rs;
		}
		return;
	}
	//if(count<3)
	//{
		for(int i = 0 ; i < n ; ++i )
		{
			tmp[count] = arr[count][i];
			DFS(count+1);
		}
	/*}
	else if(count == 3)
	{
		int tt = tmp[0] + tmp[1] + tmp[2] ;

		//tmp[3] = *
		int low = lower_bound( arr[3] , arr[3]+n , -tt ) - arr[3];
		if( low == 0 )	
		{
			tmp[3] = arr[3][0];
			tmp[4] = arr[3][1];
		}
		else	if(low < n)	
		{
			tmp[3] = arr[3][low];
			tmp[4] = arr[3][low-1];
		}
		else	if(low == n )
		{
			tmp[3] = arr[3][n-1];
			tmp[4] = arr[3][n-2];
		}

		DFS(4);

		//cout<<tmp[3]<<endl;
	}*/
}

int main()
{

	arr = new long long * [4];
	
	while(cin>>n)
	{
		rs=0;

		for( int i = 0 ; i < n ; ++i )	arr[i] = new long long [n];

		for( int i = 0 ; i < n ; ++i )
			for( int j = 0 ; j < 4 ; ++j )
				cin>>arr[j][i];
		
		sort(arr[3],arr[3]+n);

		DFS(0);

		cout<<rs<<endl;

/*		for( int i = 0 ; i < 4 ; ++i )
		{	
			for( int j = 0 ; j < n ; ++j )
				cout<<arr[i][j]<<" ";
			cout<<endl;
		}*/
		

		for( int i = 0 ; i < n ; ++i )	delete [] arr[i];
	}
}