//
// Created by Tommy on 2019-10-12.
//

#include "manager.h"


Manager::Manager(int id, string name , int dId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}


void Manager::showInfo() {
    cout <<"Manager Id : " << this->m_Id
         <<"\tname : " << this->m_Name
         <<"\tposition :" << this->getDeptName() << endl;
}

string Manager::getDeptName() {
    return std::string("Manager");
}


