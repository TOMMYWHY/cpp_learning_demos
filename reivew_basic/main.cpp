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

#if 0
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

#if 0
/*
 * reload 函数指针
 */
//1
int fun (int a, int b){
    cout<< "fun" <<endl;
    return 0;
}
typedef int (MY_fun) (int,int);

int fun(int a, int b,int c){
    cout<< "fun +a+b+c" <<endl;
    return 0;
}
int main(){
    MY_fun * fp = NULL;
    fp = fun;
    fp(10,20);//
    (*fp)(10,20);//same with above
//3
    int(*fp3)(int,int) = NULL;
    fp3= fun;
    fp3(10,20);
    int(*fp4)(int,int,int) = NULL;
    fp4 =fun;
    fp4(1,2,3);
    return 0;

}
#endif
//*********************************


#if 0

/*
 * 拷贝构造
 */
class Test {
public:
    Test(){
        this->x = 0;
        this->y = 0;
    }
    Test(int x, int y) {
        this->x = x;
        this->y = y;
        cout << " 构造构造函数 "<< endl;
    }

    void printT() {
        cout << x << "," << y << endl;
    }
    // 拷贝构造函数 对象作为参数或返回值都会调用 // 默认拷贝构造函数 如下
    Test(const Test &other){
        this->x = other.x;
        this->y = other.y;
        cout << " 拷贝构造函数 "<< endl;
    }
    ~Test(){
        cout << " 我死啦。。。"<< endl;
    }
private:
    int x;
    int y;
};

void test1(){
    Test t1(10,20);
    Test t2(t1);
}
//

int main() {
#if 0
    Test t3; // 无参构造 不能加（ ）
    Test t1(1,2);
    Test t2(t1);
    t2.printT();
    Test t4= t1; //操作符重载
    t4.printT();
    cout << " ============== " <<endl;
#endif
    test1();
    return 0;
}

#endif
//*********************************


#if 1
/*
 * 深拷贝
 * 浅拷贝：拷贝常量区或字符区时，二次析构释放非法内存。
 */
class Teacher{
public:
    int id;
    char * name;
    Teacher(int id, char * name){
        this->id = id;
        int len = strlen(name);
        this->name =(char *) malloc(len+1);
        strcpy(this->name,name);
    }
    Teacher(const Teacher &other){
        this->id = other.id;
        //深拷贝
        int len = strlen(other.name);
        this->name = (char *) malloc(len+1);
        strcpy(this->name, other.name);
    }

    ~Teacher(){
        if(this->name != NULL){
            free(this->name);
            this->name = NULL;
        }
    }
    void printT() {
        cout << this->id << " : " << this->name << endl;
    }
};
void test1(){
    Teacher t1(100,"tommy");
    t1.printT();
    Teacher t2(t1);
    t2.printT();
}
int main(){
    test1();
    return 0;
}
#endif
//*********************************
