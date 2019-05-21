#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include "Student.h"

void readData(std::vector<Student> & vec) {
    // File I/O code can also be used in the other readData functions
    std::ifstream file;
    file.open("input.txt");
    std::string fn, ln;
    int id;
    float test1, test2, test3, test4, test5,grade;
    file >> fn;
    while(!file.eof()) {
        file >> ln >> id >> test1 >> test2 >> test3 >> test4 >> test5;
        std::cout << fn << " " << ln << " " << id << " " << test1 << " " << test2 << " " << test3 << " " << test4 << " " << test5 << std::endl;
        // implement logic to store data in STL container
	grade = (test1 + test2 + test3 + test4 + test5)/5;
	vec.emplace_back(fn,ln,id,grade);
        file >> fn;
	grade = 0;
    }
    file.close();
}

void readData(std::stack<Student> & vec) {
  std::string fn, ln,trash;
  int id;
  float test1, test2, test3, test4, test5, grade;
  std::ifstream file;
  file.open("input.txt");
  while(!file.eof()){
    file >> fn >> ln >> id;
    getline(file,trash);
    file >> test1 >> test2 >> test3 >> test4 >> test5;
    grade = (test1+ test2 + test3 + test4 + test5)/5;
    getline(file,trash);
    vec.emplace(fn,ln,id,grade);
    grade = 0;
  }
  file.close();
}

void readData(std::queue<Student> & vec) {
  std::ifstream file;
  file.open("input.txt");
  std::string fn, ln;
  int id;
  float test1, test2, test3, test4, test5,grade;
  file >> fn;
  while(!file.eof()) {
    file >> ln >> id >> test1 >> test2 >> test3 >> test4 >> test5;
    grade =( test1 + test2 + test3 + test4 + test5)/5;
    vec.emplace(fn,ln,id,grade);
    file >> fn;
    grade = 0;
    }
  file.close();
}

void readData(std::list<Student> & vec) {
  std::ifstream file;
  file.open("input.txt");
  std::string fn, ln;
  int id;
  float test1, test2, test3, test4, test5,grade;
  file >> fn;
  while(!file.eof()) {
    file >> ln >> id >> test1 >> test2 >> test3 >> test4 >> test5;
    grade = (test1 + test2 + test3 + test4 + test5)/5;
    vec.emplace_back (fn,ln,id,grade);
    file >> fn;
    grade = 0;
  }
  file.close();
}

void readData(std::map<int, Student> & vec) {
  std::ifstream file;
  file.open("input.txt");
  std::string fn, ln;
  int id;
  float test1, test2, test3, test4, test5,grade;
  file >> fn;
  while(!file.eof()) {
    file >> ln >> id >> test1 >> test2 >> test3 >> test4 >> test5;
    grade = (test1 + test2 + test3 + test4 + test5)/5;
    Student Smap(fn,ln,id,grade);
    vec.insert(std::pair<float,Student>(id,Smap));
    file >> fn;
    grade = 0;
  }
  file.close();
}

void writeData(std::vector<Student> vec){
  std::ofstream Data;
  Data.open("output.txt",std::ofstream::out | std::ofstream::app);
  Data << "Vector Output:\n";
  for(int i = 0; i < vec.size(); i++){
    Data << vec[i].getFirstName() << " " << vec[i].getLastName() << " " << vec[i].getStudentId() << " " << vec[i].getClassGrade() << "\n";
  }
  Data <<"\n";
  Data.close();
}

std::stack<Student> reverse(std::stack<Student> vec){
  std::stack<Student> newvec;
  while(!vec.empty()){
      newvec.push(vec.top());
      vec.pop();
    }
  return newvec;
}

void writeData(std::stack<Student> &vec){
  std::ofstream Data;
  Data.open("output.txt",std::ofstream::out | std::ofstream::app);
  vec  = reverse(vec);
  Data << "Stack Output:\n";
  while(!vec.empty()){
    Data << vec.top().getFirstName() << " " << vec.top().getLastName() << " " << vec.top().getStudentId()
	 << " " << vec.top().getClassGrade() << "\n";
    vec.pop();
  }
  Data << "\n";
  Data.close();
}


void writeData(std::queue<Student> vec){
  std::ofstream Data;
  Data.open("output.txt",std::ofstream::out | std::ofstream::app);
  Data << "Queue Output:\n";
  while(!vec.empty()){
    Data << vec.front().getFirstName() << " " << vec.front().getLastName() << " " << vec.front().getStudentId()
	 << vec.front().getClassGrade() << "\n";
    vec.pop();
  }
  Data << "\n";
  Data.close();
}

void writeData(std::list<Student> vec){
  std::ofstream Data;
  Data.open("output.txt",std::ofstream::out | std::ofstream::app);
  Data << "List Output:\n";
  for (auto& x: vec){
    Data << x.getFirstName() << " " << x.getLastName() << " " << x.getStudentId()<< " "
	 << x.getClassGrade() << "\n";
  }
  Data << "\n";
  Data.close();
}

void writeData(std::map<int, Student> vec){
  std::map<int,Student>::iterator it = vec.begin();
  std::ofstream Data;
  Data.open("output.txt",std::ofstream::out | std::ofstream::app);
  Data << "Map Output:\n";
  for (it= vec.begin(); it!= vec.end(); ++it){
    Data << it->second.getFirstName() << " " << it->second.getLastName() << " " <<
      it->first << " " <<  it->second.getClassGrade() << "\n";
  }
  Data << "\n";
  Data.close();
}

int main() {
    std::vector<Student> studentVec;
    std::stack<Student> studentStack;
    std::queue<Student> studentQueue;
    std::list<Student> studentList;
    std::map<int, Student> studentMap; // use the student ID for the key

    readData(studentVec);
    readData(studentStack);
    readData(studentQueue);
    readData(studentList);
    readData(studentMap);
    writeData(studentVec);
    writeData(studentStack);
    writeData(studentQueue);
    writeData(studentList);
    writeData(studentMap);
    return 0;
}
