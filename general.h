#include <iostream>
#include "science.h"

using namespace std;

class general : public group
{
  public:
  general()
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
    cout << "Subject\nGeneral Knoledge Quiz - 1\nIslamiat Quiz - 2\n\n>> ";
    cin >> choice;
    system("cls");

    switch(choice)
    {
      case 1:
      cout << "\t\t\t\tGENERAL KNOWLEDGE\n" << endl;
      sub[1] = subject("GK");
      sub[1].play("general knowledge.txt");
      break;

      case 2:
      cout<<"\t\t\t\tISLAMIAT\n" << endl;
      sub[2] = subject("Islamiat");
      sub[2].play("islamiat.txt");
      break;
    }
  }

  private:
  subject sub[2];
  int index;
  
};