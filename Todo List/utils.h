#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
using namespace std;

#define MAX_LONG_TITLE 20
#define MAX_LONG_DESCRIPTION 60

struct tarea {
    string title;
    string description;
};

enum RETURNS { SUCCESS = 1, ERROR = -1};

void input(int &value);
RETURNS validate(int &value, int start, int end);
void add_task(vector<tarea> &tareas);
void delete_task(vector<tarea> &tareas, int &id);
void view_all(vector<tarea> &tareas);

#endif //UTILS_H
