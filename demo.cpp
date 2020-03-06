#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class demo{
    int data1, data2, *p;
    // Diapositiva 109
public:
    demo(){
        p = new int;
        cout << "Testing" << '\n';
    }

    demo(int a){
        data1 = a;
    }

    demo(demo &d){
        data1 = d.data1;
        data2 = d.data2;
        p = new int;
        *p = *(d.p);
    }

    void display(){
        cout << "data: " << data1 << '\n';
    }

    void exchange(int *px, int *py);
    void getdata(int a, int b, int c);
    void showdata();
    void deepCopy();
    void pointerOne();
    void pointerTwo();
    void pointerThree();
    void pointerFour();
    void shallowCopy();
    double* multiplyByTwo(double *input);
    void basic();
    void basic2();
    void testAssignment();
    void vector1();
    void vector2();
    int* foo();
    void exchange2(int& first, int& second);
    void referenceType();
};

void demo::getdata(int a, int b, int c){
    data1 = a;
    data2 = b;
    *p = c;
}

void demo::showdata(){
    cout << "data1: " << data1 << " data2: " << " *p: " << *p << '\n';
}
// Diapositiva 99
void demo::pointerOne(){
    int data = 55;
    int* dataPtr = &data;

    cout << "data1:" << data << " -- data2:" << &data << '\n';
    cout << "dataPtr1:" << dataPtr << " -- dataPtr2:" << *dataPtr << " -- dataPtr3 " << &dataPtr << '\n';
}
// Diapositiva 99
void demo::pointerTwo(){
    int data = 55;
    int* dataPtr = &data;

    cout << "data1:" << data << " -- data2:" << dataPtr << " -- data3:" << *dataPtr << '\n';
}
// Diapositiva 106
void demo::pointerThree(){
    int data;
    int* dataPtr;
    int* dataPtr_2;

    data      = 256;
    dataPtr   = &data;
    dataPtr_2 = &data;

    cout << "data1:" << data << " -- dataPtr:" << dataPtr << " -- dataPtr2:" << dataPtr_2 << '\n';

}

// Diapositiva 107
void demo::pointerFour(){
    int data;
    int* dataPtr;
    int* dataPtr_2;
    data      = 256;
    dataPtr   = &data;
    dataPtr_2 = dataPtr;

    cout << "data1:" << data << " -- dataPtr:" << dataPtr << " -- dataPtr2:" << dataPtr_2 << '\n';

}

void demo::shallowCopy(){
    int value = 5;
    int *pointer = &value;
    int *pointer2 = &value;

    cout << "pointer:" << pointer << " -- pointer2:" << pointer2 << '\n';
    cout << "pointer:" << *pointer << " -- pointer2:" << *pointer2 << '\n';
}

void demo::deepCopy(){
    demo obj1;
    obj1.getdata(10,20,30);
    obj1.showdata();
    demo obj2 = obj1;
    obj2.showdata();
}

double* demo::multiplyByTwo(double *input){
    double* twice;
    twice = (double *)malloc(sizeof(double));
    *twice = *input * 2.0;
    return twice;
}

void demo::basic(){
    int *age = (int *)malloc(sizeof(int));
    *age = 30;

    double *salary = (double *)malloc(sizeof(double));
    *salary = 12345.67;

    double *myList = (double *)malloc(3 * sizeof(double));
    myList[0] = 1.2;
    myList[1] = 2.3;
    myList[2] = 3.4;

    double *twiceSalary = multiplyByTwo(salary);

    cout << "The double of your salary is " << twiceSalary << '\n';
    cout << "Age " << *age << '\n';

    free(age);
    free(salary);
    free(myList);
    free(twiceSalary);
}

void demo::basic2(){
    int foo = 10;
    int *foo_ptr = &foo;

    cout << "2 " << foo << '\n';
    cout << "1 " << *foo_ptr << '\n';

    cout << "4 " << &foo << '\n';
    cout << "3 " << foo_ptr << '\n';

}

void demo::testAssignment(){
    int data = 55;
    int* dataPtr = &data;
    int* dataPtr_2 = &data;
    cout << "data " << &data << '\n';
    cout << "dataPtr " << dataPtr << '\n';
    cout << "dataPtr " << *dataPtr << '\n';
    cout << "dataPtr_2 " << *dataPtr_2 << '\n';
    dataPtr_2 = dataPtr;
    cout << "dataPtr_2 " << &dataPtr_2 << '\n';
}

// Diapositiva 117
void demo::vector1(){
    int *vec;
    vec = (int *)malloc(sizeof(int) * 3);
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;
    printf("vec[2]=%d\n", *(vec+2));
    free(vec);
}
// Diapositiva 118
void demo::vector2(){
    int *vec = (int *)malloc(sizeof(int) * 3);
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;
    for (int i = 0; i < 3; i++) {
        printf("%d ", *(vec+i));
    }
}
// Diapositiva 126
void demo::exchange(int *px, int *py){
    int temp;
    temp = *px;
    cout << "temp: " << &temp << " px: " << *px << '\n';
    *px = *py;
    *py = temp;


}
// Diapositiva 131
void demo::exchange2(int& first, int& second){
    int temp = first;
    first = second;
    second = temp;
}


// Diapositiva 127
int* demo::foo()
{
    int temp = 5;

    cout << "temp " << temp << '\n';
    return &temp;
}
// Diapositiva 128
void demo::referenceType(){
    int  temp      = 25;
    int& reference = temp;

    cout << "Reference: " << reference << '\n';

}

int main(int argc, char *argv[]){
    /* cout << "Ingrese el valor de la variable: ";
    int variable;
    cin >> variable;
    cout << "Imprimir variable: " << variable << '\n';
    */
    demo obj;

    //obj.pointerOne();
    //pointerTwo();
    //obj.pointerThree();
    //obj.shallowCopy();
    //basic();
    //basic2();
    //testAssignment();
    //obj.deepCopy();
    //vector();
    //vector2();
    int var1 = 6;
    int var2 = 9;
    obj.exchange(&var1, &var2);
    return 0;
}