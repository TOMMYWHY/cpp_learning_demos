//
// Created by Tommy on 2019-10-12.
//
#pragma once

#include <iostream>
#include <string>
#include "staff.h"
using namespace std;
#ifndef BASIC02_EMPLOYEE_H
#define BASIC02_EMPLOYEE_H


class Employee: public Staff {
public:
    Employee(int id, string name, int dId);
     void showInfo();
     string getDeptName ();
};


#endif //BASIC02_EMPLOYEE_H
