#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string.h>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	string input,temp;
	set<string>myset;
	set<string>::iterator it;
	int num_games=0,num_words=0,res;
	char tempChar;
	while(!cin.eof())
	{
		cin.get(tempChar);
		input+=tempChar;
	}
	//input+='\0';
	//cout<<input;
	size_t found;
	found = input.find("BULLSHIT");
	//cout<<found<<"\n";
	//cout<<input[found];
	//exit(0);
	int j=0;
	while(found!=string::npos)
	{
		num_games++;

		//cout<<num_games<<"\n";
		//cout<<num_games;
		//exit(0);
		for(int i=j;i<found;i++)
		{
			int p=0;
			//cout<<input[i];
			if(isalpha(input[i]))
			{
				//cout<<input[i];
				temp+=tolower(input[i]);
				p++;
			}
			else
			{
				//cout<<input[i];
				if(temp!="BULLSHIT" && !temp.empty())
				{
					myset.insert(temp);
				}
				temp.clear();
			}
		}
		/*
		for(it=myset.begin();it!=myset.end();it++)
			cout<<*it<<" ";
		cout<<"\n";
		*/
		num_words+=myset.size();
		myset.clear();
		//cout<<myset.size()<<"\n";
		j=found+8;
		found=input.find("BULLSHIT",found+1);
		//cout<<found<<"\n";
	}
	//exit(0);
	//cout<<num_words<<"\n"<<num_games;
	//exit(0);
	res = gcd(num_words,num_games);
	int a = num_words/res;
	int b = num_games/res;
	cout<<a<<" "<<"/"<<" "<<b<<"\n";
	return 0;
}
