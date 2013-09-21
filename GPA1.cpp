#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
float find_marks(string s)
{
	float dig=0;
	int j=0,cnt=0;
	//cout<<s.length()<<"\n";
	for(int i=0;i<s.length();i++)
	{
		if(!isdigit(s[i]) && s[i]!='.')
			return 0;
		else
		{
			if(s[i]!='.')
			{
				//cout<<s[i]<<"\n";
				dig=(dig*10)+(s[i]-'0');
				if(j>0)
					cnt++;
			}
			else
			{
				j++;
				continue;
			}

		}

	}
	float num_to_divide = pow(10,cnt);
	float ret_val = dig/num_to_divide;
	return ret_val;
}
float calc_ass_marks(float m1,float m2,float m3)
{
	float ass_sum;
	if(m1>m2)
	{
		ass_sum=m1;
		ass_sum=ass_sum+max(m2,m3);
	}
	else
	{
		ass_sum=m2;
		ass_sum=ass_sum+max(m1,m3);
	}

	float cum_marks = ass_sum*1.125;
	return cum_marks;
}
float calc_att_marks(float m5)
{
	if(m5<51)
		return 5;
	else if(m5<61)
		return 4;
	else if(m5<71)
		return 3;
	else if(m5<81)
		return 2;
	else if(m5<91)
		return 1;
	else
		return 0;
}
int calc_points(vector<double>::iterator marks)
{
	if(*marks>=91)
		return 10;
	else if(*marks>=81)
		return 9;
	else if(*marks>=71)
		return 8;
	else if(*marks>=61)
		return 7;
	else if(*marks>50)
		return 6;
	else if(*marks==50)
		return 5;
	else
		return 0;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int c1,c2,c3,c4,c5,c6;
		bool fail=false;
		//cout<<fail<<"\n";
		float gpa;
		vector<double> myvector;
		vector<double>::iterator it;
		int points[6];
		cin>>c1>>c2>>c3>>c4>>c5>>c6;
		int t=6;
		int i=0;
		while(t--)
		{
			float m1,m2,m3,m4,m5;
			string s1,s2,s3,s4,s5;
			cin>>s1>>s2>>s3>>s4>>s5;
		//	cout<<s1<<"\n"<<s2<<"\n"<<s3<<"\n"<<s4<<"\n"<<s5<<"\n";
			m1=find_marks(s1);
			m2=find_marks(s2);
			m3=find_marks(s3);
			m4=find_marks(s4);
			m5=find_marks(s5);
			//cout<<m1<<"\n"<<m2<<"\n"<<m3<<"\n"<<m4<<"\n"<<m5<<"\n";
			float ass_marks = calc_ass_marks(m1,m2,m3);
			float exam_marks = (m4/2);
			float att_marks = calc_att_marks(m5);
			float sub_marks = ass_marks + exam_marks + att_marks;
			//cout<<m5<<":"<<sub_marks<<"\n";
			myvector.push_back(sub_marks);
		}
		int k=0;
		for(it=myvector.begin();it!=myvector.end();it++)
		{
			points[k]=calc_points(it);
			k++;
		}
		float num_to_divide=c1+c2+c3+c4+c5+c6;
		float pt1=points[0]*c1/num_to_divide;
		float pt2=points[1]*c2/num_to_divide;
		float pt3=points[2]*c3/num_to_divide;
		float pt4=points[3]*c4/num_to_divide;
		float pt5=points[4]*c5/num_to_divide;
		float pt6=points[5]*c6/num_to_divide;
		if(pt1 == 0.0 or pt2 == 0.0 or pt3 == 0.0 or pt4 == 0.0 or pt5 == 0.0 or pt6 == 0.0)
			fail=true;
		//float total_points=(points[0]*c1) + (points[1]*c2) + (points[2]*c3) + (points[3]*c4) + (points[4]*c5) + (points[5]*c6);
		//gpa=(total_points/num_to_divide);
		gpa=pt1+pt2+pt3+pt4+pt5+pt6;
		if(!fail)
		{
			cout<<"PASSED"<<", ";
			printf("%0.2f\n",gpa);
		}
		else
		{
			cout<<"FAILED"<<", ";
			printf("%0.2f\n",gpa);
		}
		
		

		

	}
	return 0;
}
