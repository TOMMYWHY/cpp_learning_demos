//
// Created by Tommy on 2019-10-12.
//

#pragma once

#include <iostream>
#include <string>
#include "staff.h"
using namespace std;

#ifndef BASIC02_BOSS_H
#define BASIC02_BOSS_H


class Boss :public Staff{
public:
    Boss(int id, string name, int dId);
    void showInfo() override ;
    string getDeptName() override ;
};


#endif //BASIC02_BOSS_H
