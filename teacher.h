#include <iostream>
#include "people.h"
using namespace std;

class teacher : public people
{
  public:
  teacher()
  {
    this->Password = "123";
  }

  teacher(string name , string password) : people(name)
  {
    this->Password = password;
  }

  void checkpass(const string pass)
  {
    cout << pass;
    int choice;
    if(f.Fileread("password.txt" , 1) == pass)
    {
      cout<<"\nCorrect pass\n"<<endl;
      cout << "\nDelete Question - 1\nPassword Change - 2\nStart Page - 3\n\n>> ";
      cin >> choice;
      switch(choice)
      {
        case 1:
        //delete_question();
        break;

        case 2:
        change_password();
        break;

        case 3:
        system("cls");
        break;
      }
    }
    else
    {
      cout<<"\nSorry! You Enter Wrong Password\n"<<endl;
    }
  };

  void change_password();

  private:
  string Password;
  file f;
};

void teacher::change_password()
{
  system("cls");
  if(f.Fileread("password.txt" , 1) == Password)
  {
    cout << "\nEnter New Password of at most 8 Characters: ";
    cin >> Password;
    fstream file("password.txt");
    file << Password;
    cout << "\nPassword Change\n";
  }
  else
  {
    cout << "\nSorry! you enter wrong Password";
  }
};