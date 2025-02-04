#include "string"
#include "vector"
#include "iostream"
using namespace std;
struct lesson
{
    unsigned int lesson_id;
    string lesson_name;
    unsigned int student_id;
    short unsigned int vahed;
    float grade;
};

struct person
{
    string name;
    unsigned int id;
    string reshte;
    vector<lesson> lessons;
    float average;
    float getavg(){
        if (lessons.empty()){

            average = 0;
            return 0;
        }
            
        float avg = 0;
        int vahedcount = 0;
        for (auto& li:lessons){
            avg += (li.vahed * li.grade);
            vahedcount += li.vahed;
        }
        avg = avg/vahedcount;
        average = avg;
        return avg;
    }
};


inline bool compare (person& a,person& b){
    return a.getavg() > b.getavg();
}

vector<person> personsdata;

static unsigned long int last = 0;
static unsigned long int last_lesson = 0;

void addStudent(person& p){
    personsdata.push_back(p);
}

void removeStudent(unsigned long int payload){
    for (unsigned long int i = 0; i < personsdata.size(); i++){
        auto li = personsdata[i];
        if (li.id == payload){
            personsdata.erase(personsdata.begin() + i);
            return;
        }
    }
    cout << "student not found" << endl;
}

void updateStudent(person& payload,unsigned long int id){
    
    for (auto li:personsdata){
        if (li.id == id){
            if (payload.average != NULL)
                li.average = payload.average;
            if (!payload.name.empty())
                li.name = payload.name;
            if (!payload.reshte.empty())
                li.reshte = payload.reshte;
            return;
        }
    }
    cout << "student not found" << endl;
}

void addLesson(lesson& payload,unsigned long int id){
    for (auto& li:personsdata){
        if (li.id == id){
            li.lessons.push_back(payload);
            return;
        }
    }
    cout << "student not found" << endl;
}

void removeLesson(lesson& course,unsigned long int id){
    for (auto& li:personsdata){
        if (li.id == id){
            for (unsigned long int i = 0; i < li.lessons.size();i++){
                auto& c = li.lessons[i];
                if (c.student_id == id && id == course.student_id && c.lesson_name == course.lesson_name){
                       li.lessons.erase(li.lessons.begin() + i); 
                        delete(&course);
                        return;
                }
            }
        }
    }
    cout << "student not found" << endl;
}


void updateLesson(lesson& course,unsigned long int id){
    for (auto& li:personsdata){
        if (li.id == id){
            for (auto& c:li.lessons){
                if (c.student_id == id && id == course.student_id && c.lesson_name == course.lesson_name){
                    if (course.grade != NULL)
                    c.grade = course.grade;
                    if (course.lesson_id != NULL)
                    c.lesson_id = course.lesson_id;
                    if (!course.lesson_name.empty())
                    c.lesson_name = course.lesson_name;
                    if (course.student_id != NULL)
                    c.student_id = course.student_id;
                    if (course.vahed != NULL)
                    c.vahed = course.vahed;
                }
            }    
        }
    }
    cout << "student not found" << endl;
}

void calcaverage(person& p){
    if (p.lessons.empty())
        p.average=0;
    float avg = 0;
    float vaheds = 0;
    for (auto& li:p.lessons){
        avg += li.grade;
        vaheds += li.vahed;
    }
    p.average = avg / vaheds;
}