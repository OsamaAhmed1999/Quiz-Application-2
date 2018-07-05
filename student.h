#include <iostream>
#include "teacher.h"

using namespace std;

class student : public people
{
  public:
  student()
  {
    this->id = 123;
  }

  student (string name , int no) : people(name)
  {
    this->id = no; 
    file();
  }

  group getgrp()
  {
    return *this->grp[choice];
  }
  int getid()
  {
    return this->id;
  }

  void file()
  {
    ofstream file("result.txt");
    file << "Name: " << name << "\n";
    file << "ID: " << id << "\n";
    file.close();
  }

  void Quiz()
  {
    cout << "\n\nGroup\nScience - 1\nGeneral - 2\n\n>> ";
    cin >> choice;
    system("cls");

    switch(choice)
    {
      case 1:
      grp[1] = new science();
      grp[1]->Subject();
      break;

      case 2:
      grp[2] = new general();
      grp[2]->Subject();
      break;
       
    }
  }

  void display()
  {
    cout << this->name << endl;
    cout << this->id << endl;
  }

  private:
  int id;
  int choice;
  group *grp[2];

};

ostream& operator << (ostream& output , student& object)
{
  return output << object.getname() << "\n" << object.getid() << endl;
}