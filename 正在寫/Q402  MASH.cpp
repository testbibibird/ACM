#include<iostream>
#include<list>

using namespace std;

int main()
{
	int n,arr[20],people,count;

	while(cin>>n)
	{
		//cin>>people;

		list<int> l1;

		//for(int i = 0 ; i < 20 ; ++i )	cin>>arr[i];

		for(int i = 1 ; i <= n ; ++i )	l1.push_back(i);

	//	for(int i = 0 ; i < 20 ; ++i )
		{
			copy( l1.begin() , l1.end() , ostream_iterator<int> (cout) );cout<<endl;

			count=1;

			//for(list<int>::iterator it = l1.begin() ; it != l1.end() ;  ++count)
			//{cout<<*it;
			//if(count%2==0)	
			l1.erase( advance( l1.begin(),2), advance( l1.begin() ,2) );

				copy( l1.begin() , l1.end() , ostream_iterator<int> (cout) );cout<<endl;
			//}
		}
		

		
	}
}