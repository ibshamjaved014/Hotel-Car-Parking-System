#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<windows.h>
#include<ctime>
using namespace std;

void welcome()
{
	system("Color E4");
	
		
cout<<"\n\n\t\t\t\t\tWELCOME TO SELF PARKING SYSTEM \n\n";
}

void main_menu(){

	cout<<"\n\n\nPress 0: for Exit\nPress 1: for Park Vehicle\nPress 2: for Departure Vehicle\nPress 3: for Edit Information\nPress 4: for check Information\nPress 5: If you are employe\n\n ";

}
int add(string DriverName[],string VehicleNumber[],string CNIC[],string password[],string Date[],string type[],int index)
{	
	cout<<"ENTER THE DETAILS : \n";
		cout<<"DRIVER NAME :\n";
	string name;
	cin>>name;
	cout<<"ENTER VEHICLE NUMBER (e.g LEX1234) :\n";
	string num;
	cin>>num;
	cout<<"ENTER YOUR CNIC :\n";
	string cnicn;
	cin>>cnicn;
	/*cout<<"ENTER DATE in this format:Day/Month/Year :\t";
	string daten;
	cin>>daten;*/
	cout<<"SET PASSWORD :\n";
	string pass;
	cin>>pass;
	cout<<"ENTER type of VEHICLE (LTV|HTV|BIKE) :\n";
	string typ;
	cin>>typ;
	time_t now = time(0);
	char* dt = ctime(&now);
    DriverName[index]=name;
	VehicleNumber[index]=num;
	Date[index]=dt;
	CNIC[index]=cnicn;
	password[index]=pass;
	type[index]=typ;
		return index;
}
void currenttime()
{
   // current date/time based on current system
   time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);

   cout << "The date and time of departure : " << dt << endl;
}

int bill(string type[], int loc)
{
	
	if (type[loc]=="HTV")
	{
		return 100;
	}
	if (type[loc]=="LTV")
	{
		return 50;
	}
	if (type[loc]=="BIKE")
	{
		return 30;
	}

}
int depar(string DriverName[],string VehicleNumber[],string CNIC[],string password[],string Date[],string type[])
{
	
	cout<<"ENTER THE DETAILS : \n";
		cout<<"DRIVER NAME :\n";
	string c_name;
	cin>>c_name;
	cout<<"ENTER VEHICLE NUMBER (e.g LEX1234) :\n";
	string c_num;
	cin>>c_num;
	cout<<"ENTER PASSWORD :\n";
	string c_pass;
	cin>>c_pass;
	int i=0;
	int location=0;
	int check=-1;
	while(i<50)
	{
		if(DriverName[i]==c_name)
		{
		if(VehicleNumber[i]==c_num)
		{
			if(password[i]==c_pass)
			{
				location=i;
				check=0;
			}
		}
		}
		i++;
	}

	if(check==0)
	{int tBILL=0;
	  int totalBill;
	  totalBill=bill(type,location);
	  while(location<49)
	  {
		DriverName[location]=DriverName[location+1];
		VehicleNumber[location]=VehicleNumber[location+1];
		CNIC[location]=CNIC[location+1];
		password[location]=password[location+1];
		Date[location]=Date[location+1];
		type[location]=type[location+1];
		location++;
	    }
	    cout<<"\n\n";
		cout<<"Please Pay\t"<< tBILL<<" RS\n\n";
    }
    else
    cout<<"\n\n";
    cout<<"your information is Invalid"<<endl;
    cout<<"TRY AGAIN"<<endl;
    currenttime();

	}
void edit(string DriverName[],string VehicleNumber[],string CNIC[],string password[],string Date[],string type[])
{
	
	cout<<"ENTER THE DETAILS : \n";

	cout<<"ENTER CNIC :\t";
	string cnicn;
	cin>>cnicn;
	
	cout<<"ENTER PASSWORD :\t";
	string c_pass;
	cin>>c_pass;
	
	int i=0;
	int location=0;
	int check=-1;
	while(i<50)
	{
		if(CNIC[i]==cnicn)
		{
		
			if(password[i]==c_pass)
			{
				check=0;
				location=i;
			}
		
		}
		i++;
	}
	
	if (check==0)
	{
		cout<<"Enter NEW information:\n\n";
	cout<<"DRIVER NAME :\t";
	string name;
	cin>>name;
	cout<<"ENTER VEHICLE NUMBER (e.g LEX1234) :\t";
	string num;
	cin>>num;
	/*cout<<"ENTER DATE in this format:Day/Month/Year :\t";
	string daten;
	cin>>daten;*/
	cout<<"ENTER type of VEHICLE (LTV|HTV|BIKE) :\t";
	string typ;
	cin>>typ;
	time_t now = time(0);
	char* dt = ctime(&now);
	DriverName[location]=name;
		VehicleNumber[location]=num;
		Date[location]=dt;
		type[location]=typ;
	}
	else
	{
		cout<<"\n INVALID INFORMATION\n";
	}
	}

void view(string DriverName[],string VehicleNumber[],string CNIC[],string password[],string Date[],string type[])
{
	
	cout<<"ENTER THE DETAILS : \n";

	cout<<"ENTER CNIC :\t";
	string cnicn;
	cin>>cnicn;
	
	cout<<"ENTER PASSWORD :\t";
	string c_pass;
	cin>>c_pass;
	
	int i=0;
	int location=0;
	int check=-1;
	while(i<50)
	{
		if(CNIC[i]==cnicn)
		{
		
			if(password[i]==c_pass)
			{
				check=0;
				location=i;
			}
		
		}
		i++;
	}
	
	if (check==0)
	{
		cout<<"your information:\n\n";
		cout<<"DRIVER NAME :\t"<<DriverName[location]<<"\n";
		cout<<"VEHICLE NUMBER :\t"<<VehicleNumber[location]<<"\n";
		cout<<"CNIC NUMBER :\t"<<CNIC[location]<<"\n";
		cout<<"TYPE OF VEHICLE :\t"<<type[location]<<"\n";
		cout<<"DATE and TIME :\t"<<Date[location]<<"\n";	
	}
	else
	{
		cout<<"\n INVALID INFORMATION\n";
	}
	}
void employe(string DriverName[],string VehicleNumber[],string CNIC[],string password[],string Date[],string type[],int index)
{
	for (int i = 0; i < index; i++)
	{
		cout<<"Driver_Name\tVehicle_Number\tCNIC\tPassword\tType\tDate\n";
		cout<<DriverName[i]<<"\t"<<VehicleNumber[i]<<"\t"<<CNIC[i]<<"\t"<<password[i]<<"\t"<<type[i]<<"\t"<<Date[i]<<"\n";
	}

}
void SaveRecord(ofstream &out,string DriverName[],string VehicleNumber[],string CNIC[],string password[],string Date[],string type[],int index)
{
	time_t now = time(0);
	char* dt = ctime(&now);
	out<<"\n\n"<<dt<<"\n";
	out<<"Driver_Name\tVehicle_Number\tCNIC\tPassword\tType\tDate\n";
	for (int i = 0; i < index; i++)
	{
		out<<DriverName[i]<<"\t"<<VehicleNumber[i]<<"\t"<<CNIC[i]<<"\t"<<password[i]<<"\t"<<type[i]<<"\t"<<Date[i]<<"\n";
	}	

}

int main()
{
	welcome();
	string DriverName[50];
	string VehicleNumber[50];
	string Date[50];
	string CNIC[50];
	string password[50];
	string type[50];
	string empolyeID="18L1301";
	int employepass=1122;
	ofstream out;
	out.open("record.txt",ios::app);
	int i=0;
	int choice;
	bool loop=true;
	while(loop)
	{
		main_menu();
	cout<<"enter the choice :\t";
	cin>>choice;
		if(choice==0)
		{
			cout<<"you exited"<<endl;
			SaveRecord(out,DriverName,VehicleNumber,CNIC,password,Date,type,i);
			break;
		}
		else if(choice==1)
		{cout<<"\n\n";
			i=add(DriverName,VehicleNumber,CNIC,password,Date,type,i);
			i++;
			cout<<"\n\n";
		}
		else if(choice==2)
		{cout<<"\n\n";
		int tBILL;
		tBILL=depar(DriverName,VehicleNumber,CNIC,password,Date,type);
			currenttime();
		}
		else if(choice==3)
		{cout<<"\n\n";
			edit(DriverName,VehicleNumber,CNIC,password,Date,type);
			cout<<"\n\n";
		}
		else if(choice==4)
		{cout<<"\n\n";
			view(DriverName,VehicleNumber,CNIC,password,Date,type);
			cout<<"\n\n";
		}
		else if(choice==5)
		{cout<<"\n\n";
		cout<<"ENTER Employe ID :\t";
		string eID;
		cin>>eID;
		cout<<"ENTER Employe PASSWORD :\t";
		int ePASS;
		cin>>ePASS;
		if (eID==empolyeID)
		{
			if (ePASS==employepass)
			{
				employe(DriverName,VehicleNumber,CNIC,password,Date,type,i);

			}

		}
		
			cout<<"\n\n";
		}
		else if(choice!=0 &&choice!=1 &&choice!=2 &&choice!=3 &&choice!=4 &&choice!=5 )
		{
			cout<<"INVALID CHOICE"<<endl;
		}

	}	
	system("pause");
	return 0;
}
