#include "string"

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
    lesson lessons[];
    float average;
};


