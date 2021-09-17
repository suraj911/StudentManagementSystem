#include<bits/stdc++.h>
#include<experimental/vector>
#include<string>
//#include<string>
#define ll long long int
using namespace std;
 
ll fees_array[12] = {1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,11000,12000};

map<ll,string> entry_table;  ////////list of the people who did operation 


class Student {
public:
	ll ID;
	string name;
	string standard_section;
	ll phone_number;
	string email_id;
	int current_standard;
	char current_section;
	int addmission_year;
	int addmitted_in_standard;

	Student(string na, ll id, ll phone, string email, int currentst, char currentsc,int addmission,int addmittedinstandard){
		name=na;
		email_id=email;
		this->ID = id;
		this->phone_number = phone;
		this->current_standard = currentst;
		this->current_section = currentsc;
		this->addmission_year = addmission;
		this->addmitted_in_standard = addmittedinstandard;
		this->standard_section = char(current_standard) + " - " + current_section;
	}
};



int main(int argc, char const *argv[])
{
	vector<Student> v;
	vector<Student>::iterator ite;
	char choice1;
	cout<<"\t\t\t\t\t\t\t\t\t STUDENT MANAGEMENT SYSTEM \t\t\t\t\t\t\t\t\t\n";
	cout<<"Only one process in one go please.\n\nIf you agree to give your detail then only we can move to next step\n\n";
	cout<<"To agree and move forward press Y\t\t\tOR\t\t\tTo cancel the process press N\n\n";
	cin>>choice1;
	if(choice1 == 'Y'){
		ll faculty_id;
		string date_time = __DATE__;
		date_time +=" at ";
		date_time += __TIME__;
		entry_table[faculty_id] = date_time;

		cout<<"                                     Operation that you can perform are :\n\n";
		cout<<"                                              Operations                                          Associated Code";
		cout<<"                                                     (1) Add new student.                          -->          1            \n";
		cout<<"                                              (2) Update information about a student.       -->          2            \n";
		cout<<"                                              (3) Retrive information.                      -->          3            \n";
		cout<<"                                              (4) Delete a student.                         -->          4            \n";
		cout<<"                                              (5) Exit the Process.                         -->          5            \n";
		cout<<"Enter a Choice : ";
		int operationChoice;
		cin>>operationChoice;
		

		////
		string name; 
		ll phone_number,id; 
		string email_id;
		char current_section;
		int addmission_year, addmitted_in_standard,current_standard;
		int i = 0;
		//////


				if(operationChoice == 1){
					cout<<"!!!Addition Section!!!\n\n";
					cout<<"Enter the student detail in below format : \n";
				    cout<<"Enter name of the student :";
				    getline(cin,name);
				    cout<<"\nEnter the email ID of student : ";
				    getline(cin,email_id);
				    id = v.size()+1;
					cout<<"\nEnter the phone_number of student : \n";
					cin>>phone_number;
					cout<<"Enter the addmission_year of student : \n";
					cin>>addmission_year;
					cout<<"Enter the standard in which student is addmitted : \n";
					cin>>addmitted_in_standard;
					Student s1(name,id,phone_number,email_id,current_standard,current_section,addmission_year,addmitted_in_standard);
					v[i] = s1;
					id+=10;i++;
				}

				if(operationChoice == 2){
					int i,up_id;;
					cout<<"!!!Update Section!!!\n\n";
					cout<<"Enter the ID of specific student whoes data is to be updated : ";cin>>up_id;
					for(i=0;i<v.size();i++){
						if(v[i].ID == up_id){
							break;
						}
					}
					int ch2;
					cout<<"To update : \n\n";
					cout<<" --> Name            : press 901\n\n";
					cout<<" --> Phone Number    : press 902\n\n";
					cout<<" --> Email ID        : press 903\n\n";
					cout<<" --> Current Section : press 904\n\n";
					cin>>ch2;
					if(ch2 == 901){
						string n;getline(cin,n);
						v[i].name = n;
					}
					else if(ch2 == 902){
						int newno;cin>>newno;
						v[i].phone_number = newno;
					}
					else if(ch2 == 903){
						string tem;getline(cin,tem);
						v[i].email_id = tem;
					}
					else if(ch2 == 904){
						char g;cin>>g;
						v[i].current_section = g;
					}
					else{
						cout<<"Wrong Code Entered\n\n";
					}	
				}
				

				if(operationChoice == 3){
					cout<<"!!!Retrive information!!!\n\n";
					int r_id;cin>>r_id;
					for(i=0;i<v.size();i++){
						if(v[i].ID == r_id){
							break;
						}
					}
					cout<<"Student Information is as follow : ";
					cout<<"     --> Name             	  : "<<v[i].name<<"\n";
					cout<<"     --> Phone Number     	  : "<<v[i].phone_number<<"\n";
					cout<<"     --> Email ID              : "<<v[i].email_id<<"\n";
					cout<<"     --> ID               	  : "<<v[i].ID<<"\n";
					cout<<"     --> Currently in          : "<<v[i].standard_section<<"\n";
					cout<<"     --> Was admitted in       : "<<v[i].addmission_year<<"\n";
					cout<<"     --> Current Fees of child : "<<fees_array[v[i].current_standard]<<"\n";
				}


				if(operationChoice == 4){
					vector<Student>::iterator it;
					cout<<"!!!Delete an existing Student!!!\n\n";
					cout<<"Enter the ID of student you want to delete\n";
					int del_id; cin>>del_id;
					for(it=v.begin();it!=v.end();it++){
						if(it->ID == del_id){
							v.erase(it);
						}
					}
				}
				if(operationChoice == 5){
					cout<<"!!!You requested for Exit\n\n";
				}
		}
	
	else{
		cout<<"\n\nYou requested for cancelation\n\n";
	}
	return 0;
}


