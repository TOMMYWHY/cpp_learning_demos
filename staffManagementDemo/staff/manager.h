//
// Created by Tommy on 2019-10-12.
//

#pragma once

#include <iostream>
#include <string>
#include "staff.h"
using namespace std;

#ifndef BASIC02_MANAGER_H
#define BASIC02_MANAGER_H


class Manager :public Staff {
public:
    Manager(int id, string name, int dId);

public:
    void showInfo() override;

    string getDeptName() override;
};


#endif //BASIC02_MANAGER_H
