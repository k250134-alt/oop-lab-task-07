#include <iostream>
using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;

public:
    Person(string n, string i, string a, string p, string e) {
        name = n; id = i; address = a; phoneNumber = p; email = e;
    }

    virtual void displayInfo() {
        cout << "Name: " << name << "\nID: " << id << endl;
    }

    void updateInfo(string n, string a) {
        name = n;
        address = a;
    }
};

class Student : public Person {
private:
    string course;
    float GPA;
    int year;

public:
    Student(string n,string i,string a,string p,string e,string c,float g,int y)
        : Person(n,i,a,p,e) {
        course = c; GPA = g; year = y;
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "Course: " << course << "\nGPA: " << GPA << "\nYear: " << year << endl;
    }
};

class Professor : public Person {
private:
    string department, course;
    double salary;

public:
    Professor(string n,string i,string a,string p,string e,string d,string c,double s)
        : Person(n,i,a,p,e) {
        department = d; course = c; salary = s;
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "Department: " << department << "\nCourse: " << course << "\nSalary: " << salary << endl;
    }
};

class Staff : public Person {
private:
    string department, position;
    double salary;

public:
    Staff(string n,string i,string a,string p,string e,string d,string pos,double s)
        : Person(n,i,a,p,e) {
        department = d; position = pos; salary = s;
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "Department: " << department << "\nPosition: " << position << "\nSalary: " << salary << endl;
    }
};

class Course {
private:
    string courseId, courseName, instructor, schedule;
    int credits;

public:
    Course(string id,string name,int c,string inst,string sch) {
        courseId = id; courseName = name; credits = c;
        instructor = inst; schedule = sch;
    }

    void registerStudent(Student s) {
        cout << "Student registered in " << courseName << endl;
    }

    void calculateGrades() {
        cout << "Grades calculated\n";
    }
};

int main() {

    Student s("Ali","101","Karachi","123","a@mail.com","OOP",3.5,2023);
    Professor p("Dr.Ahmed","201","Lahore","456","p@mail.com","CS","OOP",90000);
    Staff st("Sara","301","Islamabad","789","s@mail.com","Admin","Manager",50000);

    Course c("CS101","OOP",3,"Dr.Ahmed","Mon-Wed");

    s.displayInfo();
    cout << endl;

    p.displayInfo();
    cout << endl;

    st.displayInfo();
    cout << endl;

    c.registerStudent(s);
    c.calculateGrades();

    return 0;
}
