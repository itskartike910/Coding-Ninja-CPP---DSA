/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

/*
#include<bits/stdc++.h>
class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    // Complete the class
    public:
    //Default Constructor
    Polynomial(){
        degCoeff = new int[10]{0};
        capacity = 10;
    }
    Polynomial(int size){
        degCoeff = new int[size]{0};
        capacity = size;
    }
    //Copy Constructor
    Polynomial(Polynomial const &p){
        this->degCoeff = new int[p.capacity]{0};
        this->capacity = p.capacity;
        for(int i=0;i<p.capacity;i++){
            this->degCoeff[i] = p.degCoeff[i];
        }
    }
    //Set Coefficients
    void setCoefficient(int degree,int coeff){
        if(degree>=capacity){
            int *new_degCoeff = new int[2*capacity]{0};
            for(int i=0;i<capacity;i++){
                new_degCoeff[i] = degCoeff[i];
            }
            delete []degCoeff;
            degCoeff = new_degCoeff;
            capacity *= 2;
        }
        degCoeff[degree] = coeff;
    }
    //Print Function
    void print(){
        for(int i=0;i<capacity;i++){
            if(degCoeff[i]!=0){
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }
    //CopyAssignment Operator
    Polynomial & operator=(Polynomial const &p){
        if (this != &p) {
            delete[] degCoeff;
            this->degCoeff = new int[p.capacity]{0};
            this->capacity = p.capacity;
            for (int i = 0; i < p.capacity; i++) {
                this->degCoeff[i] = p.degCoeff[i];
            }
        }
        return *this;
    }
    //Operator + overloaded
    Polynomial operator+(Polynomial const &p){
        Polynomial p3;
        p3.capacity = max(this->capacity,p.capacity);
        for(int i=0;i<p3.capacity;i++){
            int coeff = this->degCoeff[i] + p.degCoeff[i];
            p3.setCoefficient(i,coeff);
        }
        return p3;
    }
    //Operator - overloaded
    Polynomial operator-(Polynomial const &p){
        Polynomial p3;
        p3.capacity = max(this->capacity,p.capacity);
        for(int i=0;i<p3.capacity;i++){
            int coeff = this->degCoeff[i] - p.degCoeff[i];
            p3.setCoefficient(i,coeff);
        }
        return p3;
    }
    //Operator * overloaded
    // Polynomial operator*(Polynomial const &p){
    //     int m = this->capacity,n=p.capacity;
    //     Polynomial p3(m+n-1);
    //     int **arr = new int *[m];
    //     for(int i=0;i<m;i++){
    //         arr[i]=new int [m+n-1];
    //         for(int j=0;j<m+n-1;j++){
    //             arr[i][j]=0;
    //         }
    //     }
    //     for(int i=0;i<m;i++){
    //         int k=0;
    //         for(int j = i;j<i+n;j++,k++){
    //             arr[i][j]=(this->degCoeff[i] * p.degCoeff[k]);
    //         }
    //     }
    //     for(int i=0;i<m+n-1;i++){
    //         int temp = 0;
    //         for(int j=0;j<m;j++){
    //             temp+=arr[j][i];
    //         }
    //         p3.degCoeff[i] = temp;
    //     }
    //     for(int i=0;i<m;i++){
    //         delete[] arr[i];
    //     }
    //     delete []arr;
    //     return p3;
    // }
    Polynomial operator*(const Polynomial& p) {
        int newCapacity = capacity + p.capacity - 1;
        Polynomial product(newCapacity);
        for (int i = 0; i < capacity; i++) {
            for (int j = 0; j < p.capacity; j++) {
                int coeff = degCoeff[i] * p.degCoeff[j];
                int degree = i + j;
                product.setCoefficient(degree, product.degCoeff[degree] + coeff);
            }
        }
        return product;
    }

    ~Polynomial() {
        delete[] degCoeff;
    }

};
*/
class Polynomial {
public:
    int* degCoeff;
    int capacity;

    Polynomial() {
        degCoeff = new int[10]{0};
        capacity = 10;
    }

    Polynomial(int size) {
        degCoeff = new int[size]{0};
        capacity = size;
    }

    Polynomial(const Polynomial& p) {
        degCoeff = new int[p.capacity];
        capacity = p.capacity;
        for (int i = 0; i < capacity; i++) {
            degCoeff[i] = p.degCoeff[i];
        }
    }

    void setCoefficient(int degree, int coefficient) {
        if (degree >= capacity) {
            int newCapacity = degree + 1;
            int* newDegCoeff = new int[newCapacity];
            for (int i = 0; i < capacity; i++) {
                newDegCoeff[i] = degCoeff[i];
            }
            for (int i = capacity; i < newCapacity; i++) {
                newDegCoeff[i] = 0;
            }
            delete[] degCoeff;
            degCoeff = newDegCoeff;
            capacity = newCapacity;
        }
        degCoeff[degree] = coefficient;
    }

    Polynomial operator+(const Polynomial& p) {
        int newCapacity = max(capacity, p.capacity);
        Polynomial result(newCapacity);
        for (int i = 0; i < newCapacity; i++) {
            int coeff = 0;
            if (i < capacity) {
                coeff += degCoeff[i];
            }
            if (i < p.capacity) {
                coeff += p.degCoeff[i];
            }
            result.setCoefficient(i, coeff);
        }
        return result;
    }

    Polynomial operator-(const Polynomial& p) {
        int newCapacity = max(capacity, p.capacity);
        Polynomial result(newCapacity);
        for (int i = 0; i < newCapacity; i++) {
            int coeff = 0;
            if (i < capacity) {
                coeff += degCoeff[i];
            }
            if (i < p.capacity) {
                coeff -= p.degCoeff[i];
            }
            result.setCoefficient(i, coeff);
        }
        return result;
    }

    Polynomial operator*(const Polynomial& p) {
        int newCapacity = capacity + p.capacity - 1;
        Polynomial result(newCapacity);
        for (int i = 0; i < capacity; i++) {
            for (int j = 0; j < p.capacity; j++) {
                int coeff = degCoeff[i] * p.degCoeff[j];
                int degree = i + j;
                result.setCoefficient(degree, result.degCoeff[degree] + coeff);
            }
        }
        return result;
    }

    Polynomial& operator=(const Polynomial& p) {
        if (this != &p) {
            delete[] degCoeff;
            degCoeff = new int[p.capacity];
            capacity = p.capacity;
            for (int i = 0; i < capacity; i++) {
                degCoeff[i] = p.degCoeff[i];
            }
        }
        return *this;
    }

    void print() {
        for (int i = 0; i < capacity; i++) {
            if (degCoeff[i] != 0) {
                cout << degCoeff[i] << "x^" << i << " ";
            }
        }
        cout << endl;
    }

    ~Polynomial() {
        delete[] degCoeff;
    }
};


//Driver program to test above functions
int main(){
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }  
    }
    return 0;
}
