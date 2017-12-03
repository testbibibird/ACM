#include<iostream>
#include<vector>

using namespace std;

class node{
public:
	int x;
	int y;
};

void merge(vector<node> &,int,int);

int main()
{
	int r,l,h;
	vector<node> arr;
	node tmp;

	while(cin>>r>>h>>l)
	{
		tmp.x = r;
		tmp.y = h;
		arr.push_back(tmp);
		tmp.x = l;
		tmp.y = 0;
		arr.push_back(tmp);
	}
	merge( arr , 0 , arr.size() );
	
	for(int i = 0 ; i < arr.size() ; ++i )	cout<<arr[i].x<<" "<<arr[i].y<<endl;
}

void merge(vector<node> &arr,int l,int r)
{
	if( l+2 >=r )	return;

	int m = (l+r)/2, i  , j ,k=0;
	int flag = 0 , flag2 = 0 ;
	node* tmp;
	node rem,rem2;

	tmp = new node[r-l];

	merge(arr,l,m);
	merge(arr,m,r);

	i = l , j = m ;

	if( arr[i].x < arr[j].x )
	{
		rem = arr[i];

		tmp[k++] = arr[i++];
	}
	else
	{
		rem = arr[j];

		tmp[k++] = arr[j++];
	}

	if( !(arr[j].x >arr[m-1].x) )
	{
	for(  ; i < m && j < r ; ++k )
	{
		if( arr[i].x < arr[j].x )
		{
			rem2 = arr[i];

			//if( i != l && !( rem.x == arr[i-1].x && rem.y !=0 && arr[i].y ==0 ))//|| rem.y !=0 ) )	
			if( arr[j-1].y != 0 )
			arr[i].y = max ( rem.y , arr[i].y );
		//	else if(i==l) arr[i].y = max ( rem.y , arr[i].y );

			rem = rem2;

			tmp[k] = arr[i++];
		}
		else
		{
			rem2 = arr[j];//	cout<<rem2.y;

		//	if( j != m && !( rem.x == arr[j-1].x && rem.y != 0 && arr[j].y ==0))//|| rem.y != 0 ) )	
			if(arr[i-1].y!=0)
			arr[j].y = max( rem.y , arr[j].y );
		//	else if(j==m)	arr[j].y = max( rem.y , arr[j].y );

			rem = rem2;//	cout<<arr[j].y<<'x'<<endl;

			tmp[k] = arr[j++];
		}
	}
	}
	for( ; i < m ; ++i,++k)	
	{
		//rem2 = arr[i];

	//	arr[i].y = max( rem.y , arr[i].y );

		tmp[k] = arr[i];

		//rem = rem2;
	}
	for( ; j < r ; ++j,++k)
	{
		//rem2 = arr[j];

		//arr[j].y = max( rem.y , arr[j].y );

		tmp[k] = arr[j];

		//rem = rem2;
	}
	for( k = 0 ; k < r-l ; ++k )	arr[l+k] = tmp[k];

	for( k = 0 ; k < r-l ; ++k)	cout<<tmp[k].x<<' '<<tmp[k].y<<"x ";
	cout<<endl;
}