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
    int choice;
    if(f.Fileread("password.txt" , 1) == pass)
    {
      cout<<"\nCorrect pass\n"<<endl;
      cout << "\nDelete Question - 1\nPassword Change - 2\nStart Page - 3\n\n>> ";
      cin >> choice;
      switch(choice)
      {
        case 1:
        delete_question();
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
  void delete_question();
  int search(string fileName);

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
  
int teacher::search(string fileName)
{
  ifstream file;
  file.open(fileName);
  string search;
  int line = 1 , found = 0;
  cout << "Enter Question Number e.g Q1: ";
  cin >> search;
  string input = "";
  
  while(!file.eof())
  {
    int i = 0;
    getline(file , input);
    if(search[i] == input[i])
    {
      i++;
      if(search[i] == input[i])
      {
        i++;
        if(search[i] == '\0')
        {
          found++;
          break;
        }
        else
        {
          if(search[i] == input[i])
          {
            found++;
            break;
          }
        }
      }
    }
    line++;
  }
  if(found == 0)
  {
    cout << "\nNot Found\n";
    return 0;
  }
  else
  {
    return line;
  }
};

void teacher::delete_question()
{    
  string fileName;
  cout << "Enter file Name: ";
  cin >> fileName;

  ifstream file1;
  file1.open(fileName);
  ofstream file2;
  file2.open("temp.txt");
  string temp;
  int line = 1;
  int del_line;
  del_line = search(fileName);

  while (!file1.eof())
  {
    if (line == del_line)
    {
      for(int i = 1; i <= 6; i++)
      {
        getline(file1 , temp);
        
        if(i < 2)
        {
          //cout << "Question Number: ";
          //input.clear();
          //cin >> input;
          //file2 << "Q" << input << ". ";
          string input;
          getline(cin , input);
          file2 << input << "\n";
          line++;
        }
        else if(i > 1 && i <= 5)
        {
          string input;
          cout << "Options " << i-1 <<" ";
          input.clear();
          getline(cin , input);
          file2 << input << "\n";
          line++;
        }
        else
        {
          string input;
          cout << "Answer: ";
          cin >> input;
          file2 << input << "\n";
          line++;
        }
      }
    }
    else
    {
      getline(file1 , temp);
      file2 << temp << "\n";
      line++;
    }
  }
  file1.close();
  file2.close();
  remove("physics.txt");
  rename("temp.txt" , "physics.txt");
};