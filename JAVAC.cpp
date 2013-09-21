#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctype.h>
#include<cstdio>
#include<locale>
using namespace std;
int main()
{
	string s1;
	char output_string[101];
	size_t found;

	while(cin>>s1)
	{
		bool flg1,flg2;
		flg1=flg2=true;
		found=s1.find_first_of('_');
		if(found!=string::npos)
		{
			if(s1[found+1]=='_')
				flg2=false;
			for(int p=0;p<s1.length();p++)
			{
				if(s1[p]!='_')
				{
					//cout<<s1[p]<<"\n";
					if(!islower(s1[p])|| !isalpha(s1[p]))
						flg1=false;
				}
				else if(p==0 && s1[p]=='_')
					flg1=false;
				else if(p==s1.length()-1 && s1[p]=='_')
					flg1=false;
				//cout<<flg1<<"\n";
			}
			if(!flg1 || !flg2)
			{
				cout<<"Error!"<<endl;
				continue;
			}


					
			
			else
			{
				locale loc;
				s1[found+1]=toupper(s1[found+1],loc);
				int i=0;
				do
				{
					s1[found]='*';
					found=s1.find_first_of('_',found+1);
					if(isupper(s1[found+1]))
					{
						cout<<"Error!\n";
						i++;
						break;
					}
					else
					{
						locale loc1;
						s1[found+1]=toupper(s1[found+1],loc1);
					}
				}while(found!=string::npos);
				if(i==0)
				{
					int k=0;
					for(int j=0;j<s1.length();j++)
					{
						if(s1[j]!='*')
						{
							output_string[k]=s1[j];
							k++;
						}
					}
					output_string[k]='\0';
					if(isupper(output_string[0]))
						output_string[0]=tolower(output_string[0]);

					cout<<output_string<<endl;
				}
				continue;
			}

		}
		else
		{
			bool flg2=true;
			bool flg3=true;
			for(int it=0;it<s1.length();it++)
				if(!isalpha(s1[it]))
					flg3=false;
			if(isupper(s1[0]))
				flg2=false;
			if(!flg2 || !flg3)
			{
				cout<<"Error!\n";
				continue;
			}
			cout<<s1[0];
			for(int t=1;t<s1.length();t++)
				if(s1[t]>='A' && s1[t]<='Z')
					cout<<"_"<<char(s1[t]-'A'+'a');
				else 
					cout<<s1[t]; 
		}
		cout<<endl;
		continue;
	}

	return 0;
}
