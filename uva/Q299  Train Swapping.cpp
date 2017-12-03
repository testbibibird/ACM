#include<iostream>

using namespace std;

int count1;

void merge(int* ,int,int);

int main()
{
	int n,num,arr[50];

	cin>>n;

	while(n--)
	{
		count1=0;

		cin>>num;

		for( int i = 0 ; i < num ; ++i )	cin>>arr[i];

		merge(arr,0,num);

		//for(int i = 0 ; i < num ; ++i )	cout<<arr[i];

		cout<<"Optimal train swapping takes "<<count1<<" swaps."<<endl;
	}
}

void merge(int* arr,int l,int r)
{
	int m = (r+l)/2,i,j,*tmp,k;

	if(	l+1 >= r)	return;

	merge(arr,l,m);
	merge(arr,m,r);

	tmp = new int [r-l];

	i=l,j=m;

	for( k = 0 ; i < m && j < r ; ++k)
	{
		if( arr[i] <= arr[j] )	tmp[k] = arr[i++];

		else	
		{
			tmp[k] = arr[j++];
			count1 += (m-i);
		}
	}

	for( ; i < m ; ++i ,++k)	tmp[k] = arr[i];
	for( ; j < r ; ++j ,++k)	tmp[k] = arr[j];

	for( k = 0 ; k < r-l ; ++k )	arr[l+k] = tmp[k];

	delete [] tmp;
}
