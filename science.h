#include <iostream>
#include "group.h"


using namespace std;

class science : public group
{
  public:
  science()
  {
    this->index = 0;
    sub[1] = subject();
  }

  subject getsub()
  {
    return this->sub[index];
  }

  void setsub(subject& sub)
  {
    this->sub[index] = sub;
  }

  void Subject()
  {
    int choice = 0;
    cout << "Subject\nComputer Quiz - 1\nPhysics Quiz - 2\n\n>> ";
    cin >> choice;
    system("cls");

    switch(choice)
    {
      case 1:
      cout << "\t\t\t\tCOMPUTER\n" << endl;
      sub[1] = subject("Computer");
      sub[1].play("computer.txt");
      break;

      case 2:
      cout<<"\t\t\t\tPHYSICS\n" << endl;
      sub[2] = subject("Physics");
      sub[2].play("physics.txt");
      break;
    }
  }

  private:
  subject sub[2];
  int index;

};