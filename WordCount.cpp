#include<iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int cNum=0,wNum=0; 
	int ch=0;
	int judge=0;
	FILE *fpr;
	char name[100]={0};   //存储路径名 
	char type[2];
	cin>>type;
	cin>>name;
	if((fpr = fopen(name,"r")) == NULL)
	{
		cout<<"Can't open "<<name<<endl;
		exit(1);
	}
	
	if(type[1]=='c')
	{
		while((ch = fgetc(fpr)) != EOF)
		{
			if((ch>=48&&ch<=57) || (ch>=65&&ch<=90) || (ch>=97&&ch<=122) || ch==10 || ch==9 || ch==32)
			{
				cNum++;
			}
		}
		cout<<"字符数："<<cNum<<endl; 		
	}
	else if(type[1]=='w')
	{
		while((ch = fgetc(fpr)) != EOF)
		{
			if((ch>=48&&ch<=57) || (ch>=65&&ch<=90) || (ch>=97&&ch<=122) || ch==10 || ch==9)
			{
				if(judge==0)
				{
					wNum++;
					judge++;
				}
			}
			else if(ch==32 || ch==44)
			{
				judge=0;
			}
		}
		cout<<"单词数："<<wNum<<endl;
	}
	return 0;
}
