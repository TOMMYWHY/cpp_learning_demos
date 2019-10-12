cmake_minimum_required(VERSION 3.14)
project(basic02)

set(CMAKE_CXX_STANDARD 14)

add_executable(basic02 staffManagementDemo/main.cpp staffManagementDemo/staffManager.h staffManagementDemo/staffManager.cpp staffManagementDemo/staff/staff.h staffManagementDemo/staff/employee.cpp staffManagementDemo/staff/employee.h staffManagementDemo/staff/manager.cpp staffManagementDemo/staff/manager.h staffManagementDemo/staff/boss.cpp staffManagementDemo/staff/boss.h)