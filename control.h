#include <iostream>
#include "models.h"
#include "vector"
using namespace std;

void student (person& p){

}

void students (vector<person>& p)
{
    cout << "name" << "\t|" << "id" << "\t|" << "average" << endl;
    
   for (int i = 0; i < p.size(); i++)
   {
       cout << p[i].name << "\t|" << p[i].id << "\t|" << p[i].average << endl;
   }
    unsigned long int inpid;
    cout << "enter the id of student" << endl;
    cin  >> inpid;
    for (int i = 0; i < p.size(); i++){
        if(p[i].id == inpid){
            student(p[i]);
        }
    }
}

void lessons (vector<person>& p)
{

}

void index (vector<person>& p)
{
    short int key;
    cout << "Welcome to Student Managment App" << endl;
    cout << "-----------------------------------" << endl;
    cout << "select and option" << endl;
    cout << "1-Show students" << endl;
    cout << "2-Show lessons" << endl;
    cin >> key;
    if (key > 2 || key < 1)
        cout << "invalid input";
        index(p);

    switch (key)
    {
    case 1:
        students(p);
        break;
    case 2:
        students(p);
        break;
    }
}

