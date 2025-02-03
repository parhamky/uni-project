#include "string"
#include "vector"
using namespace std;
static unsigned int last_id = 0;
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
};


