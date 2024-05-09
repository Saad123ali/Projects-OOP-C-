#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

class Person {
protected:
    string name;
    int age;
    char gender;

public:
    Person() : name(""), age(0), gender(' ') {}
    Person(string _name, int _age, char _gender) : name(_name), age(_age), gender(_gender) {}
    
    void personInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }

    virtual void getGrade() = 0;
};

class Student : public Person {
protected:
    int semester;
    char grade;

public:
    Student() : semester(0), grade(' ') {}
    Student(string _name, int _age, char _gender, int _semester, char _grade) : Person(_name, _age, _gender), semester(_semester), grade(_grade) {}

    void personInfo() {
        Person::personInfo();
        cout << "Semester: " << semester << endl;
    }

    void getGrade() {
        cout << "Student Grade: " << grade << endl;
    }
};

class Course {
protected:
    string courseId;

public:
    Course() : courseId("") {}
    Course(string _courseId) : courseId(_courseId) {}

    void courseInfo()  {
        cout << "Course ID: " << courseId << endl;
    }
};

class Teacher : public Person {
protected:
    string subject;
    char grade;

public:
    Teacher() : subject(""), grade(' ') {}
    Teacher(string _name, int _age, char _gender, string _subject, char _grade) : Person(_name, _age, _gender), subject(_subject), grade(_grade) {}

    void personInfo() {
        cout << "Teacher ";
        Person::personInfo();
        cout << "Subject Name: " << subject << endl;
    }

    void getGrade() {
        cout << "Teacher Grade: " << grade << endl;
    }
};

class Department {
protected:
    string departmentName;

public:
    Department() : departmentName("") {}
    Department( string _departmentName) : departmentName(_departmentName) {}

    void personInfo() {
        cout << "Department Name: " << departmentName << endl;
    }
};
class Subject : public Teacher, public Course , public Department {
protected:
    int semester;

public:
    Subject() : semester(0) {}
    Subject(string _name, int _age, char _gender, string _subject, char _grade, string _courseId, int _semester , string _departmentname) 
    : Teacher(_name, _age, _gender, _subject, _grade), Course(_courseId), semester(_semester) , Department(_departmentname){}

    void subjectInfo() {
        Teacher::personInfo();
        Course::courseInfo();
        Department::personInfo();
        cout << "Semester: " << semester << endl;
    }

    void getGrade() {
        Teacher::getGrade(); // Call the parent class's function
    }
};

class FullTimeTeacher : public Teacher {
protected:
    int salary;

public:
    FullTimeTeacher() : salary(0) {}
    FullTimeTeacher(string _name, int _age, char _gender, string _subject, char _grade, int _salary) 
    : Teacher(_name, _age, _gender, _subject, _grade), salary(_salary) {}

    void personInfo() {
        Teacher::personInfo();
        cout << "Salary: " << salary << endl;
    }
};

class PartTimeTeacher : public Teacher {
protected:
    int hoursWeekly;

public:
    PartTimeTeacher() : hoursWeekly(0) {}
    PartTimeTeacher(string _name, int _age, char _gender, string _subject, char _grade, int _hoursWeekly) 
    : Teacher(_name, _age, _gender, _subject, _grade), hoursWeekly(_hoursWeekly) {}

    void personInfo() {
        Teacher::personInfo();
        cout << "Hours Weekly: " << hoursWeekly << endl;
    }
};

class University {
public:
    int capacity;
    Student* students;
    FullTimeTeacher* fullTimeTeachers;
    PartTimeTeacher* partTimeTeachers;
    Subject* courses;
    int studentDataCount; 
    int fullTimeTeacherDataCount; 
    int partTimeTeacherDataCount; 
    int courseDataCount; 

public:
    University() : studentDataCount(0), fullTimeTeacherDataCount(0), partTimeTeacherDataCount(0), courseDataCount(0) {
        while(true)
        {
            cout<<"\n\n\tEnter the capacity of the Entries do you want to Save? ";
            cin>>capacity;
            if(capacity <=0)
            {
                cout<<"\n\tPlease enter valid number. Please try again."<<endl;
            }
            else
            {
                break;
            }
        }
        students = new Student[capacity];
        fullTimeTeachers = new FullTimeTeacher[capacity];
        partTimeTeachers = new PartTimeTeacher[capacity];
        courses = new Subject[capacity];
    }

    ~University() {
        delete[] students;
        delete[] fullTimeTeachers;
        delete[] partTimeTeachers;
        delete[] courses;
    }

    // Function to add a student
    void addStudent(Student student) {
        if (studentDataCount < capacity) {
            students[studentDataCount++] = student;
            cout << "\n\t\tStudent Data Saved successfully!" << endl;
        } else {
            cout << "\n\t\tError: The capacity is full. Cannot add more students." << endl;
        }
    }

    // Function to add a full-time teacher
    void addFullTimeTeacher(FullTimeTeacher teacher) {
        if (fullTimeTeacherDataCount < capacity) {
            fullTimeTeachers[fullTimeTeacherDataCount++] = teacher;
            cout << "\n\t\tFull-Time Teacher Data Saved successfully!" << endl;
        } else {
            cout << "\n\t\tError: The capacity is full. Cannot add more full-time teachers." << endl;
        }
    }

    // Function to add a part-time teacher
    void addPartTimeTeacher(PartTimeTeacher teacher) {
        if (partTimeTeacherDataCount < capacity) {
            partTimeTeachers[partTimeTeacherDataCount++] = teacher;
            cout << "\n\t\tPart-Time Teacher Data Saved successfully!" << endl;
        } else {
            cout << "\n\t\tError: The capacity is full. Cannot add more part-time teachers." << endl;
        }
    }

    // Function to add a subject
    void addSubject(Subject subject) {
        if (courseDataCount < capacity) {
            courses[courseDataCount++] = subject;
            cout << "\n\t\tSubject Data Saved successfully!" << endl;
        } else {
            cout << "\n\t\tError: The capacity is full. Cannot add more subjects." << endl;
        }
    }

    // Function to display student data
    void displayStudents() {
        if (studentDataCount == 0) {
            cout << "\n\t\tNo Student Data Available" << endl;
        } else {
            cout << "\n\t\tStudent Information" << endl;
            for (int i = 0; i < studentDataCount; ++i) {
                cout << "\nStudent Data: " << i + 1 << "\n" << endl;
                students[i].personInfo();
                students[i].getGrade();
            }
        }
    }

    // Function to display full-time teacher data
    void displayFullTimeTeachers() {
        if (fullTimeTeacherDataCount == 0) {
            cout << "\n\t\tNo Full-Time Teacher Data Available" << endl;
        } else {
            cout << "\n\t\tFull-Time Teacher Information" << endl;
            for (int i = 0; i < fullTimeTeacherDataCount; ++i) {
                cout << "\nTeacher Data: " << i + 1 << "\n" << endl;
                fullTimeTeachers[i].personInfo();
                fullTimeTeachers[i].getGrade();
            }
        }
    }

    // Function to display part-time teacher data
    void displayPartTimeTeachers() {
        if (partTimeTeacherDataCount == 0) {
            cout << "\n\t\tNo Part-Time Teacher Data Available" << endl;
        } else {
            cout << "\n\t\tPart-Time Teacher Information" << endl;
            for (int i = 0; i < partTimeTeacherDataCount; ++i) {
                cout << "\nTeacher Data: " << i + 1 << "\n" << endl;
                partTimeTeachers[i].personInfo();
                partTimeTeachers[i].getGrade();
            }
        }
    }

    // Function to display subject data
    void displaySubjects() {
        if (courseDataCount == 0) {
            cout << "\n\t\tNo Subject Data Available" << endl;
        } else {
            cout << "\n\t\tSubject Information" << endl;
            for (int i = 0; i < courseDataCount; ++i) {
                cout << "\nSubject Detail " << i + 1 << "\n" << endl;
                courses[i].subjectInfo();
                courses[i].getGrade();
            }
        }
    }
};

int main() {
    University university;
    system("cls");
    cout << "\n\n\t\tWelcome to the University Management System!\n" << endl;
    while(true) 
    {
        cout << "\n\t\t ______________________________________________\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t| [1]   |     Add Data" << setw(27) << "|\n";
        cout << "\t\t| [2]   |     Display Data" << setw(23) << "|\n";
        cout << "\t\t| [0]   |     Exit" << setw(31) << "|\n";
        cout << "\t\t|       |" << setw(40) << "|\n";
        cout << "\t\t|_______|______________________________________|\n";
        cout << "\n\t\tEnter your choice: ";
        string choice;
        cin >> choice;
        cin.ignore(); 
        if(choice =="1")
        {
            string name;
            int age;
            char gender;
            while(true)
            {
                cout << "\nEnter your name: ";
                getline(cin, name);
                if(name.empty())
                {
                    cout<<"Please enter the name!"<<endl;
                }
                else
                {
                    break;
                }
            }
            while(true)
            {
                cout << "\nEnter your age: ";
                cin >> age;
                if(age <=0 || age >=99)
                {
                    cout<<"Please enter a valid age!"<<endl;
                }
                else
                {
                    break;
                }
            }
            while(true)
            {
                cout << "\nEnter your gender (M/F): ";
                cin >> gender;
                gender = toupper(gender);
                if(gender =='M' || gender =='F')
                {
                    break;
                }
                else
                {
                    cout<<"Please enter valid gender!"<<endl;
                }
            }
            system("cls");
            cout << "\n\t\tAre you entering information\n"<<endl;
            cout << "\n\t\t ______________________________________________\n";
            cout << "\t\t|       |" << setw(40) << "|\n";
            cout << "\t\t| [1]   |     Student Data" << setw(23) << "|\n";
            cout << "\t\t| [2]   |     Teacher Data" << setw(23) << "|\n";
            cout << "\t\t| [3]   |     Subject Data" << setw(23) << "|\n";
            cout << "\t\t|       |" << setw(40) << "|\n";
            cout << "\t\t|_______|______________________________________|\n";
            cout << "\n\t\tEnter your choice: ";
            string dchoice;
            cin>>dchoice;
            system("cls");
            if(dchoice == "1")
            {
                int semester;
                char grade;
                cout << "\n\t\tEnter student details" << endl;
                while(true)
                {
                    cout << "\nEnter semester: ";
                    cin >> semester;
                    if(semester <=0 || semester >10)
                    {
                        cout<<"Please enter valid semester!"<<endl;
                    }
                    else
                    {
                        break;
                    }
                }
                while(true)
                {
                    cout << "\nEnter grade: ";
                    cin >> grade;
                    grade = toupper(grade);
                    if(grade == 'A' || grade == 'B'||grade == 'C'||grade == 'D'||grade == 'F')
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Please enter valid Grade"<<endl;
                    }
                }    
                university.addStudent(Student(name, age,gender, semester, grade));
            }
            else if (dchoice == "2")
            {
                string subject;
                char grade;
                cout << "\n\t\tEnter teacher details" << endl;
                cin.ignore(); 
                while(true)
                {
                    cout << "\nEnter subject: ";
                    getline(cin, subject);
                    if(subject.empty())
                    {
                        cout<<"Please enter subject name"<<endl;
                    }
                    else
                    {
                        break;
                    }
                }
                while(true)
                {
                    cout << "\nEnter grade: ";
                    cin >> grade;
                    grade = toupper(grade);
                    if(grade == 'A' || grade == 'B'||grade == 'C'||grade == 'D'||grade == 'F')
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Please enter valid Grade"<<endl;
                    }
                }   
                system("cls");
                cout << "\n\t\tAre you entering information\n"<<endl;
                cout << "\n\t\t ______________________________________________\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t| [1]   |      Full Time Teacher" << setw(17) << "|\n";
                cout << "\t\t| [2]   |      Part Time Teacher" << setw(17) << "|\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t|_______|______________________________________|\n";
                cout << "\n\t\tEnter your choice: ";
                string tchoice;
                cin>>tchoice;
                system("cls");
                if(tchoice == "1")
                {
                    cout << "\n\t\tEnter Full-Time teacher details" << endl;
                    int salary;
                    while(true)
                    {
                        cout << "\nEnter salary: ";
                        cin >> salary;
                        if(salary <= 0)
                        {
                            cout<<"Please enter Positive  number"<<endl;
                        }
                        else
                        {
                            break;
                        }
                    }
                    university.addFullTimeTeacher(FullTimeTeacher(name, age,gender, subject, grade, salary));
                }
                else if(tchoice == "2")
                {
                    cout << "\n\t\tEnter Part-Time teacher details" << endl;
                    int hoursWeekly;
                    while(true)
                    {
                        cout << "\nEnter hours weekly: ";
                        cin >> hoursWeekly;
                        if(hoursWeekly <=0 || hoursWeekly >=40)
                        {
                            cout<<"Please enter valid hours"<<endl;
                        }
                        else
                        {
                            break;
                        }
                    }
                    university.addPartTimeTeacher(PartTimeTeacher(name, age,gender, subject, grade, hoursWeekly));
                }
                else
                {
                    cout<<"\n\t\tInvalid choice. Please try again."<<endl;
                }
            }
            else if (dchoice == "3")
            {
                string subject;
                char grade;
                string courseId;
                int semester;
                string department;

                cout << "\n\t\tEnter subject details:" << endl;
                cin.ignore(); 
                while(true)
                {
                    cout << "\nEnter subject: ";
                    getline(cin, subject);
                    if(subject.empty())
                    {
                        cout<<"Please enter the subject"<<endl;
                    }
                    else
                    {
                        break;
                    }
                }
                while(true)
                {
                    cout << "\nEnter grade: ";
                    cin >> grade;
                    grade = toupper(grade);
                    if(grade == 'A' || grade == 'B'||grade == 'C'||grade == 'D'||grade == 'F')
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Please enter valid Grade"<<endl;
                    }
                }   
                cin.ignore(); 
                while(true)
                {
                    cout << "\nEnter course ID: ";
                    getline(cin, courseId);
                    if(courseId.empty())
                    {
                        cout<<"Please enter the course ID"<<endl;
                    }
                    else
                    {
                        break;
                    }
                }
                while(true)
                {
                    cout << "\nEnter semester: ";
                    cin >> semester;
                    if(semester <=0 || semester >10)
                    {
                        cout<<"Please enter valid semester!"<<endl;
                    }
                    else
                    {
                        break;
                    }
                }
                 while(true)
                {
                    cout << "\nEnter the deartment name: ";
                    cin.ignore();
                    getline(cin, department);
                    if(department.empty())
                    {
                        cout<<"Please enter department"<<endl;
                    }
                    else
                    {
                        break;
                    }
                }
                university.addSubject(Subject(name, age,gender, subject,grade, courseId, semester,department));
            }
        }
        else if (choice == "2")
        {
            while(true)
            {
                cout << "\n\t\t ______________________________________________\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t| [1]   |     Student Data" << setw(23) << "|\n";
                cout << "\t\t| [2]   |     Teacher Data" << setw(23) << "|\n";
                cout << "\t\t| [3]   |     Subject Data" << setw(23) << "|\n";
                cout << "\t\t| [0]   |     Back" << setw(31) << "|\n";
                cout << "\t\t|       |" << setw(40) << "|\n";
                cout << "\t\t|_______|______________________________________|\n";
                cout << "\n\t\tEnter your choice: ";
                string dchoice;
                cin>>dchoice;
                system("cls");
                if(dchoice == "1")
                {
                    university.displayStudents(); 
                }
                else if (dchoice == "2")
                {
                    cout << "\n\t\t ______________________________________________\n";
                    cout << "\t\t|       |" << setw(40) << "|\n";
                    cout << "\t\t| [1]   |      Full Time Teacher" << setw(17) << "|\n";
                    cout << "\t\t| [2]   |      Part Time Teacher" << setw(17) << "|\n";
                    cout << "\t\t|       |" << setw(40) << "|\n";
                    cout << "\t\t|_______|______________________________________|\n";
                    cout << "\n\t\tEnter your choice: ";
                    string dtchoice;
                    cin>>dtchoice;
                    system("cls");
                    if(dtchoice == "1")
                    {
                        university.displayFullTimeTeachers();
                    }
                    else if(dtchoice == "2")
                    {
                        university.displayPartTimeTeachers();
                    }
                    else
                    {
                        cout<<"\n\t\tInvalid choice. Please try again."<<endl;
                    }
                }
                else if (dchoice == "3")
                {
                    university.displaySubjects();
                }
                else if (dchoice == "0")
                {
                    break;
                }
                else
                {
                    cout<<"\n\t\tinvalid choice. Please try again."<<endl;
                }
            }
        }
        else if (choice == "0")
        {
            cout<<"\n\n\t\tCode by Saad Ali on Earth."<<endl;
            break;
        }
        else
        {
            cout<<"\n\n\t\tInvalid choice. Please try again!"<<endl;
        }
    }
    return 0;   
}