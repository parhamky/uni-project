#include <iostream>
#include "models.h"
#include "vector"
#include "algorithm"
using namespace std;

void student (person& p){
    cout << "welcome" <<p.name << endl;
    cout << "1-lessons list" << endl;
    cout << "2-edit students" << endl;
    short int key;
    cin >> key;
    switch (key){
        case 1:
            lessons(p);
            break;
        case 2:

           break; 
    }
}

void students (vector<person>& p)
{
    cout << "name" << "\t|" << "id" << "\t|" << "average" << endl;
    sort(p.begin(),p.end(),compare);
    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i].name << "\t|" << p[i].id << "\t|" << p[i].average << endl;
    }
    unsigned long int inpid;
    cout << "-------------------------------------------------------" << endl;
    cout << "enter the id of student" << endl;
    cin  >> inpid;
    for (int i = 0; i < p.size(); i++){
        if(p[i].id == inpid){
            student(p[i]);
        }
    }
    cout << "student not found " << endl;
}

void lessons (person& p)
{
    auto list = p.lessons;
    cout << "id" << "name" << "\t|" << "vahed" << "\t|" << "grade" << endl;
    for (auto li:list){
           
        cout << li.lesson_name << "\t|" << li.vahed << "\t|" << li.grade << endl;

    }
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "if you want to edit lesson type lesson id or 0 to exit" << endl; 
    unsigned long int inpid;
    cin >> inpid;
    
    for (auto li:list){
        if (li.lesson_id == inpid){
            editlesson(li);
        }
    }
    cout << "lesson not found" << endl;
}

void editlesson(lesson& l){

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

