#include <iostream>
#include <string>
using namespace std;
string resize(string a)
{
	int count=0;
	for (int i=a.size()-1;i>=0;i--)
	{
		if(a[i]=='#' && a[i-1]=='#')
		{
			count+=1;
			a.erase(i,1);
		}
		else if(a[i]=='#')
		{
			count+=1;
			for (int j=0;j<=count;j++)
			{
				if (i-j<0)
				{
					break;
				}
				else if (a[i-j-1]=='#')
				{
					a.erase(i-j,1);
					count=j;
					break;	
				}
				a.erase(i-j,1);
			}
			i-=count;
			count=0;
		}
		else
		{
			continue;
		}
	}
	return a;
}
string input()
{
	string s;
	cout<<"enter a string with lowercase a,b and #:";
	getline(cin,s);
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='a' || s[i]=='b' ||s[i]=='#')
		{
			continue;
		}
		else
		{
			cout<<"not the desired string"<<endl;
			abort();
		}
	}
	cout<<endl;
	return s;
}
void comp(string s1, string s2)
{
	int s=s1.compare(s2);	
	cout<<s;
}
int main()
{
	string s1=input();
	string s2=input();
	s1=resize(s1);
	s2=resize(s2);
	cout<<"resized string1"<<s1<<endl;
	cout<<"resized string 2"<<s2<<endl;
	comp(s1,s2);
}