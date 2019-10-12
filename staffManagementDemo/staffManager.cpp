//
// Created by Tommy on 2019-10-12.
//

#include "staffManager.h"


StaffManager::StaffManager() {
//    this->m_EmpArray=NULL;
    //this->m_EmpNum = 0;
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if(!ifs.is_open()){
        cout << "file is not exist~!" << endl;
        this-> m_EmpNum =0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return ;
    }
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        cout << "file is empty"<< endl;
        this-> m_EmpNum =0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return ;
    }
    //file is not empty
    int num = this->get_EmpNum();
    cout<<"staff amount : " << num << endl;
    this->m_EmpNum = num; //get staff amount

    this->m_EmpArray = new Staff*[this->m_EmpNum];
    this->init_Employee(); // init m_EmpArray
//    testing
  /*  for (int i = 0; i < this->m_EmpNum; i++) {
        cout<<"name:"<<this->m_EmpArray[i]->m_Name << endl;
    }*/


}

void StaffManager::init_Employee(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int index = 0;
    while (ifs >> id && ifs>>name && ifs>> dId){
        Staff * staff = NULL;
        if(dId == 1){
            staff = new Employee(id,name,dId);
        } else if(dId == 2){
           staff = new Manager(id,name,dId);
        } else{
            staff = new Boss(id,name,dId);
        }

        this->m_EmpArray[index] = staff;
        index ++;
    }
    ifs.close();

};

void StaffManager::showAllEmployee(){

    if(this->m_FileIsEmpty){
        cout << "file is empty or no data" << endl;
    }else{
        for (int i = 0; i < this->m_EmpNum; ++i) {
            this->m_EmpArray[i]->showInfo();// 多态， this 对象不同，调用不同的 showInfo()
        }
    }
    cout <<"######################################"<<endl;
//    system( "clear" );
    system( "read -n 1 -s -p \"Press any key to continue...\"" );

};

void StaffManager::addEmp(){
    cout << "enter amount of staff : " <<endl;
    int addNum = 0;
    cin >> addNum;
    if(addNum >0){
        int newSize = this->m_EmpNum + addNum;
        Staff** newSpace =  new Staff* [newSize];
        if(this->m_EmpArray != NULL){
            for (int i = 0; i < this->m_EmpNum; ++i) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        for (int i = 0; i < addNum; ++i) {
            int id;
            string name;
            int departSelect;
            cout << "enter "<< i+1 << " staff number : " <<endl;
            cin>>id;
            cout << "enter "<< i+1 << " staff name : " <<endl;
            cin>>name;
            cout << "enter "<< i+1 << " staff department : " <<endl;
            cout << "1: employee" <<endl;
            cout << "2: manager" <<endl;
            cout << "3: CEO" <<endl;
            cin >> departSelect;

            Staff* staff = NULL;
            switch (departSelect){
                case 1:
                    staff = new Employee(id,name, departSelect);
                    break;
                case 2:
                    staff = new Manager(id,name, departSelect);
                    break;
                case 3:
                    staff = new Boss(id,name, departSelect);
                    break;
                default:
                    break;
            }

            newSpace[(this->m_EmpNum) + i] = staff;
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = newSpace;
        this->m_EmpNum =  newSize;

//        cout << "add "<< addNum << " successfully~!" <<endl;
        int result = this->save();
        cout <<"~!!!!~"<<endl;
        if(result == 1){
//            cout<< "result: " << result << endl;
            this->m_FileIsEmpty= false;
            cout << "add"<< addNum << "successfully~!" <<endl;
        } else{
            cout << "fail to save~!" <<endl;

        }
    } else{
        cout << "enter error~! " <<endl;
        return;
    }

}

int StaffManager::IsExist(int id){
    int index =-1;
    for (int i = 0; i < this->m_EmpNum; ++i) {
        if(this->m_EmpArray[i]->m_Id==id){
            index = i;
            break;
        }
    }
    return index;
};

void StaffManager::modify_Emp(){
    if(this->m_FileIsEmpty){
        cout <<"file empty or no data" << endl;
    } else{
        cout <<" enter id to edit : " <<endl;
        int id =0 ;
        cin >> id;
        int index = this->IsExist(id);
        if(index != -1){
            cout << "get info : "
            <<this->m_EmpArray[index]->m_Id << " "
            <<this->m_EmpArray[index]->m_Name << " "
            <<this->m_EmpArray[index]->m_DeptId << " "
            <<endl;
            delete this->m_EmpArray[index];
            int newId = 0;
            string newName = "";
            int newDepartId=0;
            cout<< "enter new Id"<<endl;
            cin >> newId;
            cout<< "enter new name"<<endl;
            cin >> newName;
            cout<< "enter new department id"<<endl;
            cin >> newDepartId;
            Staff * staff = NULL;
            switch (newDepartId){
                case 1:
                    staff = new Employee(newId, newName,newDepartId);
                    break;
                case 2:
                    staff = new Manager(newId, newName,newDepartId);
                    break;
                case 3:
                    staff = new Boss(newId, newName,newDepartId);
                    break;
                default:
                    break;
            }

            this->m_EmpArray[index] = staff;
            this->save();
            cout<< "edit successful~!" << endl;
            system( "read -n 1 -s -p \"Press any key to continue...\"" );

        } else{
            cout <<" fail to edit~!" <<endl;
            system( "read -n 1 -s -p \"Press any key to continue...\"" );
        }
    }
};

void StaffManager::Delete_Emp(){
    if(this->m_FileIsEmpty){
        cout <<"file empty or no data" << endl;
    } else{
        cout <<" enter id to delete : " <<endl;
        int id =0 ;
        cin >> id;
        int index = this->IsExist(id);
        if(index != -1){
//            this->m_EmpArray[index] = NULL;
            for (int i = index; i < this->m_EmpNum -1; i++) {
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }
            this->m_EmpNum --;
            this->save();
            cout<<" delete successful~!"<<endl;
            system( "read -n 1 -s -p \"Press any key to continue...\"" );
        }else{
            cout <<" fail to delete~!" <<endl;
            system( "read -n 1 -s -p \"Press any key to continue...\"" );
        }
    }

};

int StaffManager::save(){
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    for (int i = 0; i < this->m_EmpNum; ++i) {
        ofs<<this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name <<" "
            << this->m_EmpArray[i]->m_DeptId <<" "
            << endl;
    }
    ofs.close();
    return 1;
}

int StaffManager::get_EmpNum(){
    //get file staff amount
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int dId;
    int num = 0;
    while(ifs>>id && ifs >> name && ifs>>dId){
        num++;
    }

    return num;
};

void StaffManager:: showMenu(){
    cout <<"**************************************" <<endl;
    cout <<"*welcome to staff management system~!*" <<endl;
    cout <<"**** 0 : exit ************************" <<endl;
    cout <<"**** 1 : add staff information *******" <<endl;
    cout <<"**** 2 : show staff information ******" <<endl;
    cout <<"**** 3 : delete staff information ****" <<endl;
    cout <<"**** 4 : edit staff information ******" <<endl;
    cout <<"**** 5 : find staff information ******" <<endl;
    cout <<"**** 6 : sort all staff **************" <<endl;
    cout <<"**** 7 : clean file ******************" <<endl;
    cout <<"**************************************" <<endl;

};

void StaffManager::exitSystem() {
    cout <<"exit system. bye~!" <<endl;
    exit(0);

}


StaffManager::~StaffManager() {
    if(this->m_EmpArray !=NULL){
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
};