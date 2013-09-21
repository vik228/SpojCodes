#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
char input[200001];
using namespace std;
int main()
{
	int l;
	cin>>l;
	string str;
	string str2;
	int p=1;
	set<int> myset;
	set<int>::iterator it;
	size_t found;
	for(int i=0;i<l;i++)
	{
		cin>>input[i];
		str+=input[i];
	}
	for(int i=1;i<=l/2;i++)
	{
		for(int j=0;j<l-i+1;j++)
		{
			string temp = str.substr(j,i);
			found = str.find(temp);
			found = str.find(temp,found+1);
			if(found!=string::npos)
				myset.insert(i);
		}
	}
	/*
	for(it=myset.begin();it!=myset.end();it++)
		cout<<*it<<"\n";
	*/
	cout<<*myset.end()<<"\n";
	return 0;
}

