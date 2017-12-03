#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int inversion;

void merge(string& arr,int l,int r)
{
	int m = (r+l)/2,i,j,k;
	char *tmp;
	if(	l+1 >= r)	return;

	merge(arr,l,m);
	merge(arr,m,r);

	tmp = new char [r-l];

	i=l,j=m;

	for( k = 0 ; i < m && j < r ; ++k)
	{
		if( arr[i] <= arr[j] )	tmp[k] = arr[i++];

		else	
		{
			tmp[k] = arr[j++];
			inversion += (m-i);
		}
	}

	for( ; i < m ; ++i ,++k)	tmp[k] = arr[i];
	for( ; j < r ; ++j ,++k)	tmp[k] = arr[j];

	for( k = 0 ; k < r-l ; ++k )	arr[l+k] = tmp[k];

	delete [] tmp;
}

int main()
{
	string a,tmp;

	int count,pivot;

	while(cin>>a)
	{

		if(a=="#")	break;

		inversion = count=1;

		tmp = a;

		sort(tmp.begin(),tmp.end());

		cout<<a<<" "<<tmp<<" "<<inversion<<" "<<count<<endl;

		while(next_permutation(tmp.begin(),tmp.end()))
		{
			//if(tmp==a)	break;
			a=tmp;
			inversion=0;

			/*for(int i = 1 ; i < a.size() ; ++i )
			{
				pivot = a[i];

				for( int j = i-1 ; j >= 0 ; --j)
				{
					if( a[j] < pivot )	
					{
						a[j+1] = pivot;
						break;
					}
					a[j+1] = a[j];
					++inversion;
				}
			}*/
			merge(a,0,a.size());
++count;
			cout<<a<<" "<<tmp<<" "<<inversion<<" "<<count<<endl;

			
		}

		

		//cout.width(10);
		//cout<<count<<endl;
	}
}