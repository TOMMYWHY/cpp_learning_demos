//
// Created by Tommy on 2019-10-12.
//

#include "employee.h"

Employee::Employee(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}
void Employee:: showInfo(){
    cout <<"employee Id : " << this->m_Id
        <<"\tname : " << this->m_Name
        <<"\tposition :" << this->getDeptName() << endl;
};
string Employee::  getDeptName (){
    return string("employee");
};