#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int sizeOfStudent=14, sizeOfCourse=5;

//Inheritence, parent of class Student
class University{
	protected:
		string universityName;
	public:
		University();
		University(string universityname);
		void setUniversityName(string universtyname);
};
University::University(){
}
University::University(string universityname){
	setUniversityName(universityname);
}
void University::setUniversityName(string universityname){
	universityName=universityname;
}


class Desasiswa{
	private:
		string hostelName;
		double desasiswaFee;
	public:
		Desasiswa();
		Desasiswa(string hostel);
		void set(string hostel);
		void print();
		friend class StudentFee;
};
Desasiswa::Desasiswa(){
	desasiswaFee=0.0;
	set("");
}
Desasiswa::Desasiswa(string hostel){
	set(hostel);
}
void Desasiswa::set(string hostel){
	hostelName=hostel;
}
void Desasiswa::print(){
	cout<<"\n       Desasiswa : "<<hostelName<<endl<<endl;
}


//COMPOSITION CLASS STUDENT HAS A CLASS STUDENTFEE
class StudentFee{
	private:
		double tuitionFee;
		double facilityFee;
		double setDesasiswaFee;
	public:
		StudentFee();
		StudentFee(double tuition, double facility, double desafee);
		void set(double tuition, double facility, double desafee);
		void print();

};

StudentFee::StudentFee(){
}
StudentFee::StudentFee(double tuition, double facility, double desafee){
	set(tuition,facility,desafee);
}
void StudentFee::set(double tuition, double facility, double desafee){
	tuitionFee=tuition;
	facilityFee=facility;
	setDesasiswaFee=desafee;
}
void StudentFee::print(){
	cout<<"     Tuition Fee : RM"<<tuitionFee<<endl;
	cout<<"    Facility Fee : RM"<<facilityFee<<endl;
	cout<<"   Desasiswa Fee : RM"<<setDesasiswaFee<<endl;
	cout<<"       Total Fee : RM"<<tuitionFee+facilityFee+setDesasiswaFee<<endl;
}

//COMPOSITION CLASS STUDENT HAS A CLASS SUBJECT
class Subject{
	private:
		string subjectName1;
		string subjectName2;
		string subjectName3;
	public:
		Subject();
		Subject(string subjectname1, string subjectname2, string subjectname3);
		void set(string subjectname1, string subjectname2, string subjectname3);
		void print();
};
Subject::Subject(){
}
Subject::Subject(string subjectname1, string subjectname2, string subjectname3){
	set(subjectname1, subjectname2, subjectname3);
}
void Subject::set(string subjectname1, string subjectname2, string subjectname3){
	subjectName1=subjectname1;
	subjectName2=subjectname2;
	subjectName3=subjectname3;
}
void Subject::print(){
	cout<<"   Subject Taken : 1."<<subjectName1<<endl;
	cout<<"                   2."<<subjectName2<<endl;
	cout<<"                   3."<<subjectName3<<endl<<endl;
	cout<<"________________\n";
}

//DERIVED CLASS (CHILD OF COURSE CLASS)
class Student:public University{
	private:
		string studentName;
		int studentID;
		StudentFee studentfee;
		Desasiswa desasiswa;
		Subject subject;
	public:
		Student();
		Student(string name,int id, double tuition, double facility, double desafee, string hostel, string subjectname1, string subjectname2, string subjectname3);
		void print();
		void uniName();
};
Student::Student(){
	Student("", 0, 0.0, 0.0, 0.0, "", "", "", "");
}
Student::Student(string name,int id,double tuition, double facility, double desafee, string hostel, string subjectname1, string subjectname2, string subjectname3){
	studentName=name;
	studentID=id;
	studentfee.set(tuition,facility, desafee);
	desasiswa.set(hostel);
	subject.set(subjectname1,subjectname2,subjectname3);
}
void Student::print(){
	cout<<"    Student Name : "<<studentName<<endl;
	cout<<"              ID : "<<studentID<<endl<<endl;
	cout<<" Fee information : \n";
	studentfee.print();
	desasiswa.print();
	subject.print();
	cout<<endl;
}
void Student::uniName(){
	cout<<"\t\t   "<<universityName<<endl;
}



void showCourse(){
	cout<<"   COURSE LIST  \n";	
	cout<<"CODE     COURSE\n";
	cout<<"  1      Computer Sciences\n";
	cout<<"  2      Mathematics\n";
	cout<<"  3      Management\n";
	cout<<"  4      Islamic Studies\n";
	cout<<"  5      Communication Studies\n";	
	}

void showListTittle(string cn, int c){
	if(c==1){
		cout<<"\t\t"<<cn<<"'S Student List\n";
		cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n";
	}
}


int main(){
	int c=1;//to make sure header only out 1 time
	
	
	//variable to read in file and store in class
	string nameInFile, courseInFile, desasiswaInFile, subject1InFile, subject2InFile, subject3InFile;
	double tuitionInFile, facilityInFile, hostelFeeInFile;
	int idInFile;


	
	Student COURSE_ARRAY[sizeOfCourse];//"Computer Science", "Mathematics", "Management", "Islamic Studies", "Communication Studies"

	
	showCourse();
	int courseChoice; 
	cout<<"View student list from course(Enter CODE) : ";
	cin>>courseChoice;
	system("CLS");

	COURSE_ARRAY[0].setUniversityName("UNIVERSITY SAINS MALAYSIA");
	COURSE_ARRAY[0].uniName();

	ifstream inFile;
	inFile.open("StudentInfo.txt");	
	if(inFile.is_open()){
        for(int count=0; count<sizeOfStudent; count++){
        		//getting data in file
				getline(inFile, courseInFile, '\t');
				getline(inFile, nameInFile, '\t');
				inFile>>idInFile;
            	inFile>>tuitionInFile;
            	inFile>>facilityInFile;
            	inFile>>hostelFeeInFile;
            	getline(inFile, desasiswaInFile, '\t');
            	getline(inFile, subject1InFile, '\t');
            	getline(inFile, subject2InFile, '\t');
            	getline(inFile, subject3InFile);
//            	inFile.ignore();
				//only print for Computer Science Course Student
				if(courseChoice==1){
					if(courseInFile=="Computer Sciences"){
						showListTittle(courseInFile, c);
						c++;
						COURSE_ARRAY[0]=Student(nameInFile,idInFile,tuitionInFile,facilityInFile,hostelFeeInFile,desasiswaInFile,
												subject1InFile,subject2InFile,subject3InFile);			
						COURSE_ARRAY[0].print(); 

					}
				}
				//only print for Mathematics Course Student
				else if(courseChoice==2){
					if(courseInFile=="Mathematics"){
						showListTittle(courseInFile, c);
						c++;
						COURSE_ARRAY[1]=Student(nameInFile,idInFile,tuitionInFile,facilityInFile,hostelFeeInFile,desasiswaInFile,
												subject1InFile,subject2InFile,subject3InFile);			
						COURSE_ARRAY[1].print();	
					}
				}			
				//only print for Management Course Student
				else if(courseChoice==3){
					if(courseInFile=="Management"){
						showListTittle(courseInFile, c);
						c++;
						COURSE_ARRAY[2]=Student(nameInFile,idInFile,tuitionInFile,facilityInFile,hostelFeeInFile,desasiswaInFile,
												subject1InFile,subject2InFile,subject3InFile);			
						COURSE_ARRAY[2].print();
					}
				}
				//only print for Islamic Studies Course Student
				else if(courseChoice==4){
						if(courseInFile=="Islamic Studies"){
							showListTittle(courseInFile, c);
							c++;
							COURSE_ARRAY[3]=Student(nameInFile,idInFile,tuitionInFile,facilityInFile,hostelFeeInFile,desasiswaInFile,
													subject1InFile,subject2InFile,subject3InFile);			
							COURSE_ARRAY[3].print();
					}
				}				
				//only print for Communication Studies Course Student
				else if(courseChoice==5){
						if(courseInFile=="Communication Studies"){
							showListTittle(courseInFile, c);
							c++;
							COURSE_ARRAY[4]=Student(nameInFile,idInFile,tuitionInFile,facilityInFile,hostelFeeInFile,desasiswaInFile,
													subject1InFile,subject2InFile,subject3InFile);			
							COURSE_ARRAY[4].print();	
					}
				}

				
		}

	}

	return 0;
}
