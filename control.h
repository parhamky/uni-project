#include <iostream>
#include "models.h"
#include "vector"
#include "algorithm"
using namespace std;


void lessons (person& p);
void newlesson(person& p);

void editstudent (person& p){
    person* payload = new person;

    cin.ignore();
    cout << "enter new name :" ;
    getline(cin,payload->name);

    cout << endl;
    cout << "enter new reshte :" ;
    cin >> payload->reshte;
    cout << endl;
    cout << "enter new average :" ;
    cin >> payload->average;
    cout << endl;
    payload->id = p.id;
    updateStudent(*payload,p.id);
}

void deletestudent(person& p)
{
    removeStudent(p.id);
    delete(&p);
}

void student (person& p){
    cout << "welcome " <<p.name << endl;
    cout << "0-exit" << endl;
    cout << "1-lessons list" << endl;
    cout << "2-edit students" << endl;
    cout << "3-add lesson" << endl;
    cout << "4-delete student" <<endl;
    short int key;
    cin >> key;
    switch (key){
    case 1:
        lessons(p);
        break;
    case 2:
        editstudent(p);
        break;
    case 3:
        newlesson(p);
        break;
    case 4:
        deletestudent(p);
    case 0:
        return;
        break;
    }

}

void newlesson(person& p){
    lesson* payload = new lesson;
    cin.ignore();
    cout << "enter course name:";
    getline(cin,payload->lesson_name);
    if (payload->lesson_name.empty())
    {
        cout << "id is empty";
        return;
    }
    cout << endl;
    cout << "enter course grade:";
    cin >> payload->grade;
    if (payload->grade == NULL)
    {
        cout << "lesson is empty";
        return;
    }
    cout << endl;
    cout << "enter course vahed:";
    cin >> payload->vahed;
    if (payload->vahed == NULL)
    {
        cout << "name is empty";
        return;
    }
    cout << endl;
    payload->student_id = p.id;
    last_lesson++;
    payload->lesson_id = last_lesson;
    addLesson(*payload,p.id);
    p.getavg();
}

void editlesson(string name,unsigned long int id){
    lesson* payload = new lesson;
    cin.ignore();
    cout << "enter new course name:";
    getline(cin,payload->lesson_name);
    cout << endl;
    cout << "enter course grade:";
    cin >> payload->grade;
    cout << endl;
    cout << "enter course vahed:";
    cin >> payload->vahed;
    cout << endl;
    cout << "enter student id:";
    cin >> payload->student_id;
    cout << endl;
    updateLesson(*payload,id);
}

void students (vector<person>& p)
{
    cout << "name" << "\t|" << "id" << "\t|"<< "reshte" << "\t|" << "average" << endl;
    sort(p.begin(),p.end(),compare);
    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i].name << "\t|" << p[i].id << "\t|" << p[i].reshte << "\t|" << p[i].getavg() << endl;
    }
    unsigned long int inpid;
    cout << "-------------------------------------------------------" << endl;
    cout << "enter the id of student" << endl;
    cout <<"0 for exit" << endl;
    if (inpid == 0)
    {
        return;
    }
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
    cout << "id"<< "\t|" << "name" << "\t|" << "vahed" << "\t|" << "grade" << endl;
    for (auto& li:list){

        cout << li.lesson_id << "\t|"<< li.lesson_name << "\t|" << li.vahed << "\t|" << li.grade << endl;

    }
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "if you want to edit lesson type lesson id or 0 to exit" << endl;
    unsigned long int inpid;
    cin >> inpid;

    for (auto& li:list){
        if (li.lesson_id == inpid){
            editlesson(li.lesson_name,p.id);
        }
    }
    cout << "lesson not found" << endl;
}

void createstudent() {
    person* payload = new person;
    cin.ignore();
    cout << "enter name :" ;
    getline(cin,payload->name);
    cout << endl;
    cout << "enter reshte :" ;
    cin >> payload->reshte;
    cout << endl;
    last++;
    payload->id = last;
    auto list = new vector<lesson>;
    payload->lessons = *list;
    payload->getavg();
    addStudent(*payload);
}

void index ()
{
    auto p = personsdata;
    short int key;
    cout << "Welcome to Student Managment App" << endl;
    cout << "-----------------------------------" << endl;
    cout << "select and option" << endl;
    cout << "1-Show students" << endl;
    cout << "2-create student" << endl;
    cout <<  "3-exit" << endl;
    cin >> key;
    cout << "you choosed:" << key << endl;
    if (key > 3 || key < 1)
    {
        cout << "invalid input" << endl;
        index();
    }
    switch (key)
    {
    case 1:
        students(p);
        index();
        break;
    case 2:
        createstudent();
        index();
        break;
    case 3:
        return;
    }
}

