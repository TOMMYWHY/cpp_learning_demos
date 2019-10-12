//
// Created by Tommy on 2019-10-12.
//
#pragma once

#include <iostream>
#include <string>
using namespace std;
#ifndef BASIC02_STAFF_H
#define BASIC02_STAFF_H


class Staff {
public:
    int m_Id;
    string m_Name;
    int m_DeptId;

    virtual void showInfo() = 0;
    virtual string getDeptName ()= 0;
};


#endif //BASIC02_STAFF_H
