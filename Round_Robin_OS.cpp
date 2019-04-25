#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct process
{
	int p_id;
	int a_t;
	int b_t;
	int mb_t;
	int c_t;
	int tat;
	int w_t;
	int r_t;
	int f_t;
};
int main()
{
	int x,i,t_q,ct=0,flag=0,min,temp;
	cout<<endl<<"--------------------------------------------------ROUND ROBIN SCHEDULER------------------------------------------------"<<endl;
	cout<<endl<<"enter the no of processes for scheduling->";
	cin>>x;
	cout<<endl;
    process p[x];
    for(i=0;i<x;i++)
	{
		cout<<"enter pid for process->";
		cin>>p[i].p_id;
		cout<<"enter arrival time->";
		cin>>p[i].a_t;
		if(i==0)
		{
		min=p[i].a_t;
		}
		if(min>p[i].a_t)
		{
			min=p[i].a_t;
		}
		cout<<"enter burst time->";
		cin>>p[i].b_t;
		p[i].mb_t=p[i].b_t;
		cout<<endl;
		p[i].f_t=0;
	}
	ct=min;
	cout<<"enter the time quantum for scheduler->";
	cin>>t_q;
	while(true)
	{
		if(flag==x)
		{
			break;
		}
		flag=0;
		for(i=0;i<x;i++)
		{
			if(p[i].a_t<=ct && p[i].mb_t>0)
			{
				if(p[i].mb_t==p[i].b_t)
				{
					p[i].r_t=ct;
				}
				if((p[i].mb_t-t_q)>=0)
				{
					p[i].mb_t=p[i].mb_t-t_q;
					ct=ct+t_q;
				}
				else
				{
					ct=ct+p[i].mb_t;
					p[i].mb_t=0;
				}
				if(p[i].mb_t==0)
				{
					p[i].c_t=ct;
				}
			}	
		}
		for(i=0;i<x;i++)
		{
			if(p[i].mb_t==0)
			{
				flag++;
			}
		}
	}
	for(i=0;i<x;i++)
	{
		p[i].c_t;
		p[i].tat=p[i].c_t-p[i].a_t;
		p[i].w_t=p[i].tat-p[i].b_t;
	}
	cout<<endl<<endl<<"----------------------------------------------------GANTT CHART--------------------------------------------------------"<<endl<<endl;
	cout<<"process_id"<<"	"<<"arrival_time"<<"     "<<"burst_time"<<" 	 "<<"completion_time"<<"   "<<"turn_around_time"<<"	 "<<"waiting_time"<<"  	 "<<"response_time"<<endl;
	for(i=0;i<x;i++)
	{
		cout<<p[i].p_id<<"		 "<<p[i].a_t<<"		 "<<p[i].b_t<<"		 "<<p[i].c_t<<"			 "<<p[i].tat<<"		 "<<p[i].w_t<<"	   	 "<<p[i].r_t<<endl;
	}
	return 0;
}
