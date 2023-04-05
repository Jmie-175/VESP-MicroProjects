#include<iostream>
#define max 99
using namespace std;
class attend
{
	public:
	int a[max],n,temp;
	void enter();
	void att_sheet();
	void att_absent();
    void att_present();
	void change();
	void add();
	void del();
};
class index : public attend
{
	public:
	int ch;
	int index1();
	void att();
};
void attend::enter()
{
	char ex,zero='0',one='1';
	cout<<"Enter Number of Students: ";
	cin>>n;
	cout<<"Input 1 for present and 0 for absent \n";
	for(int i=0;i<n;i++)
	{
		cout<<"Roll Number "<<i+1<<": ";
		cin>>ex;
		if(ex!='0' && ex!='1')
		{
			cout<<"Invalid Input !!! \n";
			i=i-1;
		}
		if(ex==0)
		a[i]=0;
		else
		a[i]=1;
	}
}
void attend::att_sheet()
{
	cout<<"\n******Attendance Sheet****** \n";
	cout<<"____________________________\n| Roll Number | Attendance |\n____________________________\n";
	for(int i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			if(i<9)
			cout<<"|      "<<i+1<<"      | Present    |\n";
			else
			cout<<"|      "<<i+1<<"     | Present    |\n";
		}
		else
		{
			if(i<9)
			cout<<"|      "<<i+1<<"      | Absent*    |\n";
			else
			cout<<"|      "<<i+1<<"     | Absent*    |\n";
		}
	}
	cout<<"____________________________\n";
}
void attend::att_absent()
{
	int t=0;
	for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        t=t+1;
    }
    cout<<"\nAbsent Roll Numbers: ";
    if(t==0)
	cout<<"NIL";
	else
	{
		for(int i=0;i<n;i++)
	{
		if(a[i]!=1)
		cout<<i+1<<" ";
	}
	}
	cout<<"\nTotal Absentee: "<<t<<endl;
}
void attend::att_present()
{
    int t=0;
    float percent;
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        t=t+1;
    }
    percent=(t*100)/n;
    cout<<"\nTotal Presentee: "<<t<<endl;
    cout<<"Percentage of Presentee :"<<percent<<" % \n";
}
void attend::change()
{
	cout<<"\nEnter Roll Number to Change Attendance: ";
	cin>>temp;
	if(temp>0 && temp<=n)
	{
		if(a[temp-1]==0)
		a[temp-1]=1;
		else
		a[temp-1]=0;
		cout<<"Attendance changed for Roll Number "<<temp<<endl;;
	}
	else
	cout<<"Invalid Roll Number !!! \n(Enter from Numbers 1 to "<<n<<") \n";
}
void attend::add()
{
	int n1;
	cout<<"\nEnter Number of Students to Add: ";
	cin>>temp;
	n1=n+temp;
	cout<<"Input 1 for present and 0 for absent \n";
	for(int i=n;i<n1;i++)
	{
		cout<<"Roll Number "<<i+1<<": ";
		cin>>a[i];
		if(a[i]!=0 && a[i]!=1)
		{
			cout<<"Invalid Input !!! \n";
			i=i-1;
		}
	}
	n=n1;
	cout<<"Added "<<temp<<" Number of Students \n";
}
void attend::del()
{
	cout<<"\nEnter Number of Students to Delete: ";
	cin>>temp;
	n=n-temp;
	cout<<"Deleted "<<temp<<" Number of Students\n";
}
void index::att()
{
	att_sheet();
	att_absent();
	att_present();
}
int index::index1()
{
	cout<<"\n********Make Changes******** \n1.Change Attendance \n2.Add Students \n3.Delete Students \n4.Back \n";
	cout<<"Enter Choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
		change();
		break;
		case 2:
		add();
		break;
		case 3:
		del();
		break;
		case 4:
		return 1;
		break;
	}
}
int main()
{
	int ch;
	index object;
	object.enter();
	while(1)
	{
		cout<<"\n*********Main Menu********** \n1.Show Attendance Data \n2.Make Changes \n3.Exit \n";
		cout<<"Enter Choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			object.att();
			break;
			case 2:
			object.index1();
			break;
			case 3:
			return 0;
			break;
			default:
			cout<<"Invalid Input !!! \n";
		}
	}
	return 0;
}