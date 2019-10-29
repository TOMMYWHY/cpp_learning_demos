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

#if 0
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

#if 0
/*
 * reference
 */
int getA1 (){
    int a = 10;
    return  a;//只拷贝
}
void getA2(int *pa){
    *pa = 11;//地址修改
}
char * getMem(int num){
    char *p = NULL;
    p = (char * )malloc(num);
    return p;
}
int getMem2(char **pp,int num){
    char *p = NULL;
    p = (char * )malloc(num);
    *pp = p;
    return 0;
}
// 不要反回局部变量的引用
int& getA3(){
    int a = 13;
    return a;//int &temp = a
}
int& getA4(){
    static int a =14;
    return a;
}
int main (){
    int a = 0;
    a = getA1();
    cout << a << endl;
    getA2(&a);
    cout << a << endl;
    a = getA3(); //a = temp //值拷贝
    cout << a << endl;
//    int &main_a_ref = getA3();//
//    cout << main_a_ref << endl; //err
//    cout << main_a_ref << endl; //err
    int &main_a_ref = getA4(); // 引用所在内存属于 static，不被释放。
    cout << main_a_ref << endl;//14
    cout << main_a_ref << endl;
    getA4() = 1000;
    cout << main_a_ref << endl;//1000
    return 0;
}
#endif
//*********************************

#if 0
/*
 * 指针引用
 * 将指针类型 以引用形式传递。减缓二级指针
 */
struct teacher {
    int id;
    char name[64];
};

int get_mem(struct teacher* &tp) {
    // 形参 struct teacher* 类型    &tp引用
    tp = (struct teacher *) malloc(sizeof(struct teacher));
    tp->id = 300;
    strcpy(tp->name, "tommy");
    return 0;
}

int main() {
    teacher *tp = NULL;
    get_mem(tp);
    cout << tp->id << tp->name << endl;
    return 0;
}

#endif
//*********************************
#if 1
/*
 * const引用
 */
int main(){
    const int a = 10;
    //int &ref = a;//err
    int const &ref = a;

    return 0;
}
#endif
//*********************************
