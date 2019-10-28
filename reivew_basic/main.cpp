#include <iostream>
using namespace std;

#if 0
// reference
void change_value(int* p ){
    *p =30;
}
void change_value2(int & r){
    r = 33;
}
int main(){
    int a =10;
    int b = 20;
    int *p = NULL;
    p = &a;
    *p = 11;
    p = &b;
    *p = 22;
    cout << "a: " << a <<endl;
    cout << "b: " << b <<endl;

    int & ref = a;//引用声明后 不可变
    ref = 111;
    ref = b;
    cout << "a: " << a <<endl;
    cout << "ref: " << ref <<endl;
    change_value(&a);
    cout << "change_value a: " << a <<endl;// 指针 传递
    change_value2(a);
    cout << "change_value2 a: " << a <<endl; // 引用 传递
}

#endif
//============================

#if 1
//
void swap_byPointer (int * a, int * b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}
void swap_byRef(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b= temp;
}
int main(){
    int a = 11;
    int b = 22;
//    swap_byPointer(&a,&b);
    swap_byRef(a,b);
    cout << "a: " << a <<endl;
    cout << "b: " << b <<endl;


    return 0;
}
#endif
//*********************************
