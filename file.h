#include <iostream>
#include <fstream>


using namespace std;
class file
{
  public:
  file()
  {}

  string Fileread(string filename , int lineno)
  {
    string temp;
    int i = 1;
    ifstream obj(filename);
    while(getline(obj , temp))
    {
      if(i == lineno)
      {
        return temp ;
      }
      i++;
    }
  }

  /*int search(string fileName)
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
  }

  void deletee(string fileName)
  {    
    ifstream file1;
    file1.open(fileName);
    ofstream file2;
    file2.open("temp.txt");
    string temp , input;
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
          if(i == 1)
          {
            cout << "Question Number: ";
            cin >> input;
            file2 << "Q" << input << ". ";
            cout << "Write Question: ";
            cin >> input;
            file2 << input << "\n";
            line++;
          }
          else if(i > 1 && i <= 5)
          {
            cout << "Options " << i-1 <<" ";
            cin >> input;
            file2 << input << "\n";
            line++;
          }
          else
          {
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
  }*/

};