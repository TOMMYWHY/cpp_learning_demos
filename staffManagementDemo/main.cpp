#include <iostream>
#include "staffManager.h"
#include "staff/staff.h"
#include "staff/employee.h"
#include "staff/manager.h"
#include "staff/boss.h"

using namespace std;
// oop demo
int main() {


   /* Staff * staff  = NULL;
    staff = new Employee(1,"tommy",101);
    Staff * staff2 = new Boss(2,"sookie",102);
    staff->showInfo();
    staff2->showInfo();*/

    StaffManager staffManager;

    int action = 0;
    bool flag = true;
    while (flag){
        staffManager.showMenu();
        cout << "enter an action : " << endl;
        cin >> action;
        switch (action){
            case 0:
                staffManager.exitSystem();
                flag = false;
                break;
            case 1:
                staffManager.addEmp();
                break;
            case 2:
                staffManager.showAllEmployee();
                break;
            case 3:
                staffManager.Delete_Emp();
                break;
            case 4:
                staffManager.modify_Emp();

                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                system("cls");
                break;
        }
    }
    return 0;
}