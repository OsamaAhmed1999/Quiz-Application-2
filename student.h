#include <iostream>
#include "teacher.h"

using namespace std;

class student : public people
{
  public:
  student()
  {
    this->seatno = 123;
    this->grp[1] = NULL;
  }

  student (string name , int no) : people(name)
  {
    this->seatno = no; 
  }

  void Quiz()
  {
    int choice = 0;
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

  private:
  int seatno;
  group *grp[2];

};