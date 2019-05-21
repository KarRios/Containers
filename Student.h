#ifndef _STUDENT
#define _STUDENT

class Student {
    private:
        std::string firstName;
        std::string lastName;
        int    studentId;
        float  classGrade;
    public:
        Student();
        Student(std::string fname, std::string lname, int id, float grade);
        void   setfirstName(std::string fname);
        void   setLastName(std::string lname);
        void   setStudentId(int id);
        void   setClassGrade(int grade);
        std::string getFirstName();
        std::string getLastName();
        int    getStudentId();
        float  getClassGrade();
};

Student::Student() {
  std::string firstName = " ";
  std::string lastName = " ";
  int    studentId = 0;
  float  classGrade = 0;
}

Student::Student(std::string fname, std::string lname, int id, float grade) {
  firstName = fname;
  lastName = lname;
  studentId = id;
  classGrade = grade;

}

void Student::setfirstName(std::string fname) {
  firstName = fname;
}

void Student::setLastName(std::string lname) {
  lastName = lname;
}

void Student::setStudentId(int id) {
  studentId = id;
}

void Student::setClassGrade(int grade){
  classGrade = grade;
}

std::string Student::getFirstName() {
  return firstName;
}

std::string Student::getLastName() {
  return lastName;
}

int Student::getStudentId() {
  return studentId;
}

float Student::getClassGrade() {
  return classGrade;
}
#endif
