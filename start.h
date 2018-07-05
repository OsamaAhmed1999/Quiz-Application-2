#include <iostream>
#include "student.h"

using namespace std;

class start
{
  public:
  start()
  { 
    Start();
  }

  void Start()
  {
    cout << "\t\t\tQUIZ APPLICATION" << endl << endl ;
    cout << "Enter Name: ";
    cin >> name;
    p = new people(name);
    int choice = 0;
    while(choice != 3)
    {
      cout << "\nPlease Enter Your Choice " << p->getname();
      cout << "\nStudent - 1\nTeacher - 2\nExit - 3\n\n>> ";
      
      cin >> choice;
      system("cls");

      switch(choice)
      {
        case 1:        
        Student();
        break;

        case 2:
        Teacher();
        break;

        case 3:
        cout << "Thank You" << endl;
        break;
      }
    }
  };

  void Student();
  void Teacher();

  private:
  string name;
  people *p;
  
};

void start::Student()
{
  int seatno;
  cout << "Enter Seat no: ";
  cin >> seatno;
  student s(name , seatno);
  s.Quiz();
  
};

void start::Teacher()
{
  char pass[8];
  string password;
  cout << "Enter Password: ";
  int i = 0;
  while(i < 8)
  {
    pass[i] = _getch();
    cout << "*";
    i++;
  }
  password = pass;
  teacher t(name , password);
  t.checkpass(password);
};