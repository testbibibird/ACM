#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool cmp(string a,string b)
{
	string tmp1(a);
	tmp1.append(b);
	string tmp2(b);
	tmp2.append(a);

	for(int i = 0 ; i < tmp1.size() ; ++i)
	{
		if(tmp1[i]>tmp2[i])	return true;
		else	if(tmp1[i]<tmp2[i])	return false;
	}

	return false;
}

int main()
{
	int n;
	string arr[50];

	while(cin>>n&&n!=0)
	{
		for(int i = 0 ; i < n ; ++i )	cin>>arr[i];

		sort(arr,arr+n,cmp);

		for(int i = 0 ; i < n ; ++i )	cout<<arr[i];
		cout<<endl;
	}
}