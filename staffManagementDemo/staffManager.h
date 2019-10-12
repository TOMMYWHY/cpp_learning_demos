//
// Created by Tommy on 2019-10-12.
//
#pragma once

#include <iostream>
#include "staff/staff.h"
#include "staff/employee.h"
#include "staff/manager.h"
#include "staff/boss.h"
#include <fstream>
#define  FILENAME "empFile.txt"
using namespace std;

#ifndef BASIC02_STAFFMANAGER_H
#define BASIC02_STAFFMANAGER_H


class StaffManager{
public:
    StaffManager();
    void showMenu();
    void exitSystem();

    int m_EmpNum;
    Staff ** m_EmpArray ;
    void addEmp();
    int save();
    bool m_FileIsEmpty;
    int get_EmpNum();
    void init_Employee();
    void showAllEmployee();
    int IsExist(int id);
    void Delete_Emp();
    void modify_Emp();
    void clean_data();
    ~StaffManager();
};


#endif //BASIC02_STAFFMANAGER_H
