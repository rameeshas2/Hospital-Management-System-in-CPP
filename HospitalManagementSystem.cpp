#include <iostream> //for input and output 
#include <fstream> //filehandling
#include <iomanip> //setw
#include <string>  //for string
#include <stdlib.h> //used for exit

using namespace std;

 //function declarations 
 
int chooseMain();
void getDoctorDatabase();
void getPatientDatabase();		
void getBedDatabase();
void getPatientReport();

//the password class
class password{
	
	public:
	string pass;
	void getPassword(){
    cout<<"\nChoose a password for your system:"<<endl;
    cin>>pass;
    }
    
	int verifyPassword()
	{
	string x;
	cout<<"\nEnter the password:"<<endl;
	cin>>x;
	if (x==pass)
	return 1;
	else 
	return 0;	 	
   }
    
    void passwordProtect(){
    	int veri=verifyPassword();
	
		 if(veri==1){
		 	cout<<"\nAccess Granted!"<<endl;
		 }
		 else 
		 {
		cout<<right<<setw(40)<<setfill(' ')<<"\nAccess Denied!\n\nSystem will shut down\n\nPlease come back again."<<endl;
		 exit(0);
		 }
	}
};

//the doctor class
class doctor{
	public:
	string d_fname,d_lname;
	int d_ID, d_age,experience,d_totalno;
	long double d_phone;
	string qual,d_city;
	string getSpec();
   	friend void addDoc();
   	friend void dispDatabase();
   	friend void numberofDocs();
   	friend void getDoctorDatabase();
};

string doctor::getSpec(){  //scope resolution
 	string sp;
	cout<<"1.GENERAL_MEDICINE"<<endl;
	cout<<"2.NEUROLOGY"<<endl;
	cout<<"3.ONCOLOGY"<<endl;
	cout<<"4.HAEMATOLOGY"<<endl;
	cout<<"5.GASTROENTEROLOGY"<<endl;
	cout<<"6.GYNAECOLOGY "<<endl;
	int s;
	cin>>s;
	switch(s){
		
		case 1:{
			sp= "GENERAL_MEDICINE";
			break;
		}
		case 2:{
			sp="NEUROLOGY";
			break;
		}
		case 3:{
		    sp="ONCOLOGY";
			break;
		}
		case 4:{
			sp= "HAEMATOLOGY";
			break;
		}
		case 5:{
			sp= "GASTROENTEROLOGY";
			break;
		}
		case 6:{
			sp= "GYNAECOLOGY ";
			break;
		}
		default:{
			cout<<"\nEnter a valid option!"<<endl;			
		}	
	}
		return sp;	
}

//the addDoc function
void addDoc(){
	    doctor d;
	    cout<<"Fill up the following details"<<endl;
	    cout<<"ID:"<<endl;
	    cin>>d.d_ID;
   		cout<<"First Name:"<<endl;
   		cin>>d.d_fname;
   		cout<<"Last Name:"<<endl;
   		cin>>d.d_lname;
   		cout<<"Age:"<<endl;
   		cin>>d.d_age;
   		cout<<"Phone number: "<<endl;
   		cin>>d.d_phone;
   		cout<<"Choose Qualification among the following:\n1.MBBS\n2.MD"<<endl;
   		int q;
   		cin>>q;
   		if(q==1){
   			d.qual="MBBS";
		   }
		else d.qual="MD";
		cout<<"Choose Specialization among the following:"<<endl;
		string spec=d.getSpec();
		cout<<"Experience (in Years):"<<endl;
		cin>>d.experience;
		cout<<"City:"<<endl;
		cin>>d.d_city;
		system("cls");
		
		
		fstream fileObj;   
		fileObj.open("doctor.txt",ios::app );
      //ID,firstname,lastname,age,qualification,specialization,experience,city

        fileObj.seekp (0, ios::end); // Seek to the end of the file
		fileObj<<d.d_ID<<endl<<d.d_fname<<endl<<d.d_lname<<endl<<d.d_age<<endl<<d.qual<<endl<<spec<<endl<<d.experience<<endl<<d.d_city<<endl;
		// Write doctor information to the file
		fileObj.close();
	
	//after completion
	cout<<"\n\t\tNew Doctor profile created successfully!"<<endl<<endl<<endl;
	cout<<"\n\n\n\nEnter 1 to return to Doctor Profile\nEnter 2 to Exit the program."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  getDoctorDatabase();
	}	  
	else
	  exit(0);
 //backtoDoctorMenu		 
}

//the dispDatabase function
void dispDatabase(){
	fstream fileObj("doctor.txt");
	fileObj.seekg(0); //input
	cout<<right<<setw(70)<<setfill(' ')<<"DOCTOR'S PROFILE "<<endl<<endl;
	int age,exp,count=0;
	string ID,fname,lname,ci,qua,spe;
	while(fileObj>>ID>>fname>>lname>>age>>qua>>spe>>exp>>ci)
	{	count++;
		cout<<right<<setw(50)<<setfill(' ')<<"Doctor's' Profile:"<<count<<endl;
		cout<<"\n\n1.ID:"<<ID<<endl<<"2.First Name:"<<fname<<endl<<"3.Last Name:"<<lname<<endl<<"4.Age:"<<age<<endl<<"5.Qualification:"<<qua<<endl<<"6.Specialization:"<<spe<<endl<<"7.Experience:"<<exp<<endl<<"8.City:"<<ci<<endl<<endl;
	}
	
	if(count==0)
	{cout<<"\nNo matching records found!"<<endl;
 	    exit(0);
	}
	
	cout<<"\n\nEnter 1 to return to Doctor Profile\nEnter 2 to Exit the program."<<endl;
	int c;
	cin>>c;
	if(c==1)
	{
	  system("cls");
	  getDoctorDatabase();
	} 
	else
	  exit(0);
}

//the numberofDocs function
void numberofDocs(){
	fstream fileObj("doctor.txt");
	fileObj.seekg(0);
	int age,exp,count_d=0;
	string ID,fname,lname,ci,qua,spe;
	while(fileObj>>ID>>fname>>lname>>age>>qua>>spe>>exp>>ci)
	{	count_d++;
	}
	cout<<"\n\n\tThe no. of doctors in the hospital="<<count_d<<endl<<endl;
	
	cout<<"\n\nEnter 1 to return to Doctor Profile\nEnter 2 to Exit the program."<<endl;
	int c;
	cin>>c;
	if(c==1)
	{
	  system("cls");
	  getDoctorDatabase();
	} 
	else
	  exit(0);
} 

//the patient class
class patient{
	public:
	string fname,lname,occupation,pcity,dis,addDate,relDate;
	int p_age,p_ID;
	long double phnumber,bill;
	string getDept();
	friend void getDoctor();
	friend void addPat();
	friend void dispPatDatabase();
	friend void numberofPats();
   	friend void getPatientDatabase();
					
};
string patient::getDept(){
	string sp;
	cout<<"1.GENERAL_MEDICINE"<<endl;
	cout<<"2.NEUROLOGY"<<endl;
	cout<<"3.ONCOLOGY"<<endl;
	cout<<"4.HAEMATOLOGY"<<endl;
	cout<<"5.GASTROENTEROLOGY"<<endl;
	cout<<"6.GYNAECOLOGY "<<endl<<endl;
	int s;
	cin>>s;
	switch(s){
		
		case 1:{
			sp= "GENERAL_MEDICINE";
			break;
		}
		case 2:{
			sp="NEUROLOGY";
			break;
		}
		case 3:{
		    sp="ONCOLOGY";
			break;
		}
		case 4:{
			sp= "HAEMATOLOGY";
			break;
		}
		case 5:{
			sp= "GASTROENTEROLOGY";
			break;
		}
		case 6:{
			sp= "GYNAECOLOGY ";
			break;
		}
		default:{
			cout<<"\nEnter a valid option!"<<endl;
			
		}	
	}
		return sp;
}

void getDoctor(){
	patient p;
	string dept;
	cout<<"\nEnter the kind of specialization you are looking for:"<<endl<<endl;
	dept=p.getDept();
	fstream fileObj("doctor.txt");
	fileObj.seekg(0);
	cout<<"The doctors available with  "<<dept<<" specialization are:"<<endl<<endl;
	int age,exp,count=0;
	string ID,fname,lname,ci,qua,spe;
	while(fileObj>>ID>>fname>>lname>>age>>qua>>spe>>exp>>ci)
	{
		if(spe==dept){
		cout<<"\n\n1.ID:"<<ID<<endl<<"2.First Name:"<<fname<<endl<<"3.Last Name:"<<lname<<endl<<"4.Age:"<<age<<endl<<"5.Qualification:"<<qua<<endl<<"6.Specialization:"<<spe<<endl<<"7.Experience:"<<exp<<endl<<"8.City:"<<ci<<endl<<endl;
		count++;
		}
	}
	
	fileObj.close();
	if(count==0){
		cout<<"\nNo doctors with this specialization found!"<<endl;
		exit(0);
	}
	else
		cout<<"No of doctors with "<<dept<<" specialization:"<<count<<endl;
		
	cout<<"\n\n\n\nEnter 1 to return to Patient Profile\nEnter 2 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  getPatientDatabase();	 //backtoPatientMenu
	}	  
	else
	  exit(0); 
}

//the addPat function
void addPat(){
	patient p;										//ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill,spec
	    cout<<"Fill up the following details"<<endl;
	    cout<<"ID:"<<endl;
	    cin>>p.p_ID;
   		cout<<"First Name:"<<endl;
   		cin>>p.fname;
   		cout<<"Last Name:"<<endl;
   		cin>>p.lname;
   		cout<<"Age:"<<endl;
   		cin>>p.p_age;
		cout<<"Phone No.:"<<endl;
   		cin>>p.phnumber;
   		cout<<"Occupation:"<<endl;
		cin>>p.occupation;
		cout<<"City:"<<endl;
		cin>>p.pcity;
   		cout<<"Disease/Symptoms:"<<endl;
   		cin>>p.dis;
   		cout<<"Admission date  (DD/MM/YYYY):"<<endl;
   		cin>>p.addDate;
   		cout<<"Release date  (DD/MM/YYYY):"<<endl;
   		cin>>p.relDate;	
   		cout<<"Total Bill generated:"<<endl;
   		cin>>p.bill;
		if (p.occupation == "laborer" || p.occupation == "labor" ||p.occupation == "labourer" ||p.occupation == "labour" ||p.occupation == "Labourer" ||p.occupation == "Labour" ||p.occupation == "Labor" ||p.occupation == "Laborer") {
        // 10% discount for laborers
        const double discountPercentage = 10.0;
        p.bill -= (p.bill * discountPercentage / 100.0);
        cout << "Discount applied! " << discountPercentage << "% discount for laborers." << endl;
        cout<<"Your bill will be: "<<p.bill<<endl;;
		}
		cout<<"Kind of Specialization required:"<<endl;
		string dept=p.getDept();
		system("cls");
				
		fstream patObj;   
		patObj.open("patient.txt",ios::app );
      //ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill,dept

        patObj.seekp (0, ios::end);
		patObj<<p.p_ID<<endl<<p.fname<<endl<<p.lname<<endl<<p.p_age<<endl<<p.phnumber<<endl<<p.occupation<<endl<<p.pcity<<endl<<p.dis<<endl<<p.addDate<<endl<<p.relDate<<endl<<p.bill<<endl<<dept<<endl;
		patObj.close();
	
	cout<<"\n\t\tNew Patient profile created successfully!"<<endl<<endl<<endl;
	cout<<"\n\n\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  getPatientDatabase();	 //backtoPatientMenu
	}
	  
	else
	  exit(0); 
}

//the dispPatDatabase function
void dispPatDatabase(){
	fstream Obj("patient.txt");
	Obj.seekg(0);
	cout<<right<<setw(70)<<setfill(' ')<<"PATIENT'S PROFILE"<<endl<<endl;
	string fname,lname,occupation,p_city,dis,addDate,relDate,dept;
	int p_age,p_ID,count=0;
	long double phnumber,bill;
	while(Obj>>p_ID>>fname>>lname>>p_age>>phnumber>>occupation>>p_city>>dis>>addDate>>relDate>>bill>>dept)
	{   count++;
		cout<<right<<setw(50)<<setfill(' ')<<"Patient Profile:"<<count<<endl;
		cout<<"1.ID:"<<p_ID<<endl<<"2.First Name:"<<fname<<endl<<"3.Last Name:"<<lname<<endl<<"4.Age"<<p_age<<endl<<"5.Phone No.:"<<phnumber<<endl<<"6.Occupation:"<<occupation<<endl<<"7.City:"<<p_city<<endl<<"8.Disease/Symptoms:"<<dis<<endl<<"9.Admission date(DD/MM/YYYY):"<<addDate<<endl<<"10.Release date(DD/MM/YYYY):"<<relDate<<endl<<"11.Total Bill generated:"<<bill<<endl<<"12.Kind of Specialization required:"<<dept<<endl<<endl;
		
		}		
	Obj.close();
	
	if(count==0){
		cout<<"\nNo matching records found!"<<endl;
		exit(0);
	}
	
cout<<"\n\nEnter 1 to return to Patient Profile\nEnter 2 to Exit the program."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  getPatientDatabase();
	}
	  
	else
	  exit(0);	
	
}

//the numberofPats function
void numberofPats(){
	fstream Obj("patient.txt");
	Obj.seekg(0);
	string fname,lname,occupation,p_city,dis,addDate,relDate,dept;
	int p_age,p_ID,count=0;
	long double phnumber,bill;
	while(Obj>>p_ID>>fname>>lname>>p_age>>phnumber>>occupation>>p_city>>dis>>addDate>>relDate>>bill>>dept)
	{  
	 count++;		
	}
		
	Obj.close();
	cout<<"\n\n\tThe number of patients in the hospital="<<count<<endl;
	
cout<<"\n\nEnter 1 to return to Patient Profile\nEnter 2 to Exit the program."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  getPatientDatabase();
	}	  
	else
	  exit(0);		
}

class bed{
	public:
	int total = 1000;
	friend void getStatus();
};

//the getStatus function
 void getStatus(){	
    bed b;
    cout<<"\n\tTotal Number of Beds in the hospital:"<<b.total<<endl;
    fstream file("patient.txt");
  	file.seekg(0); //used to set the read position in a file to the beginning (offset 0). 
	string fname,lname,occupation,p_city,dis,addDate,relDate,dept;
	int p_age,p_ID,count_b=0;
	long double phnumber,bill;
	while(file>>p_ID>>fname>>lname>>p_age>>phnumber>>occupation>>p_city>>dis>>addDate>>relDate>>bill>>dept)
	{  
	 count_b++;		
	}
		
	file.close();
	cout<<"\n\tThe number of Occupied Beds = "<<count_b<<endl;
	cout<<"\n\tThe number of Empty Beds = "<<b.total-count_b<<endl;
		
	cout<<"\n\nEnter 1 to return to Bed Profile\nEnter 2 to Exit the program."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  getBedDatabase();
	}	  
	else
	  exit(0);		
 }
 
//the main function
int main(){
	password A;
	A.getPassword();
		
    system("cls");
		
	cout<<endl;
	cout<<right<<setw(60)<<setfill(' ')<<"WELCOME TO RMS'S HOSPITAL MANAGEMENT SYSTEM "<<endl;
	cout<<endl<<endl;
	cout<<right<<setw(60)<<setfill(' ')<<"------------------------------------------------"<<endl;
	
	cout<<right<<setw(40)<<setfill(' ')<<"1.Main Menu"<<endl;
	cout<<right<<setw(35)<<setfill(' ')<<"2.Exit"<<endl;
	cout<<right<<setw(60)<<setfill(' ')<<"------------------------------------------------"<<endl<<endl;
	cout<<"Enter your choice:"<<endl<<endl;
	int choice1;
	cin>>choice1;
	
	if (choice1==1){
		 system("cls");
		 int var=chooseMain();
		 system("cls");

		 	switch(var){
			case 1:{
				A.passwordProtect();
				system("cls");
				getDoctorDatabase();
				break;
			}
			
			case 2:{
			    A.passwordProtect();
				system("cls");
				getPatientDatabase();
				break;
				
			}
				
			case 3:{
			    A.passwordProtect();
				system("cls");
				getBedDatabase();
				break;
			}
					 
			case 4:
				{
				return 0;
				break;
				}
			default:
				cout<<"\nEnter a valid option!"<<endl;
		}
		
	}
	else if(choice1==2){
		return 0;
	}
	else
	 cout<<"\nEnter a valid option!"<<endl;
}

//the chooseMain function
int chooseMain(){
	
	int choice2;
	cout<<right<<setw(40)<<setfill(' ')<<"\n\t\t\t MAIN MENU"<<endl<<endl<<endl;
	cout<<right<<setw(80)<<setfill('-')<<"----------"<<endl;
	cout<<"			"<<"1.Enter Into Doctors' Profile"<<endl;
	cout<<"			"<<"2.Enter Into Patients' Profile"<<endl;
	cout<<"			"<<"3.Check for Hospital Bed Availability"<<endl;
	cout<<"			"<<"4.Exit the program"<<endl<<endl;
	cout<<right<<setw(80)<<setfill('-')<<"----------"<<endl;
	
	cout<<"\nEnter the number corresponding to your choice:"<<endl;
	cin>>choice2;
	return choice2;
	
}

//the getDoctorDatabase function
void getDoctorDatabase(){
	int choice_doc;
	cout<<"\n                         " <<"WELCOME TO DOCTOR'S PROFILE"<<endl<<endl;
	cout<<"			"<<"1.Add New Doctor's Information"<<endl;
	cout<<"			"<<"2.Display Entire Doctor List"<<endl;
	cout<<"			"<<"3.Total Number of Doctors"<<endl;
	cout<<"			"<<"4.Exit the program"<<endl;
	cout<<right<<setw(80)<<setfill('-')<<"----------"<<endl;
	
	cout<<right<<setw(60)<<setfill(' ')<<"\nEnter the number corresponding to your choice:"<<endl<<endl;
	cin>>choice_doc;
	system("cls");
	switch(choice_doc){
//addDoc()
		case 1:{
		    addDoc();
			break;
		}
//dispDatabase()
		case 2:{
			dispDatabase();
			break;
		}
//numberOfDocs()
		case 3:{
			numberofDocs();
			break;
		}

//exit	
		case 4:{
			exit(0);
			break;
		}			
	}
}

//the getPatientDatabase function
void getPatientDatabase(){
	int choice_pat;
	cout<<"\n                         "<<"WELCOME TO PATIENT'S PROFILE"<<endl<<endl;
	cout<<"			"<<"1.Add New Patient's Information"<<endl;
	cout<<"			"<<"2.Display Entire Patient List"<<endl;
	cout<<"			"<<"3.Total Number of Patients"<<endl;
	cout<<"			"<<"4.Check for doctor availability"<<endl;
	cout<<"			"<<"5.Exit the program"<<endl;
	cout<<right<<setw(80)<<setfill('-')<<"----------"<<endl;
	
	cout<<right<<setw(60)<<setfill(' ')<<"\nEnter the number corresponding to your choice:"<<endl<<endl;
	cin>>choice_pat;
	system("cls");
	switch(choice_pat){
//addPat()
		case 1:{
		    addPat();
			break;
		}
//dispPatDatabase()
		case 2:{
			dispPatDatabase();
			break;
		}
//numberOfPats()
		case 3:{
			numberofPats();
			break;
		}
//getDoctor	  
		case 4:{
			getDoctor();
			break;
		}
//exit	
		case 5:{
			exit(0);
			break;
		}			
	}
}

//the getBedDatabase function
void getBedDatabase(){
int choice_bed;
	cout<<"\n                         "<<"WELCOME TO BED PROFILE"<<endl<<endl;
	cout<<"			"<<"1.Check Bed Status"<<endl;	
	cout<<"			"<<"2.Exit the program"<<endl<<endl;	
		cout<<right<<setw(80)<<setfill('-')<<"----------"<<endl;
	
	cout<<right<<setw(60)<<setfill(' ')<<"\nEnter the number corresponding to your choice:"<<endl<<endl;
	cin>>choice_bed;
	system("cls");
	switch(choice_bed)
	{
		case 1:{
//getStatus()
		    getStatus();
			break;
		}
		case 2:{
//exit	
			exit(0);
			break;
		}
	}
}
