#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
 
template <typename T>
class Stack{

    T* ptr;
    int size, top;

public: 
    Stack(int size = 10);
    virtual ~Stack();
    bool push(const T&);
    bool pop(T&);
    void destroy();
    bool isEmpty();
    bool isFull();

    template <class T1>
    friend ostream& operator << (ostream&, const Stack<T1>&);
};

template<class T>
Stack<T> :: Stack(int size){
    this->size = size >= 10 ? size : 10;
    this->top = -1;
    ptr = new T[size];
}

template <class T>
Stack<T> :: ~Stack(){
    destroy();
}

template <class T>
void Stack<T> :: destroy(){
    if(this->ptr != nullptr){
        delete[] ptr;
        ptr = nullptr;
    }
    size = 0;
    top = -1;
}

template <class T>
bool Stack<T> :: isEmpty(){
    return this->top == -1;
}

template <class T>
bool Stack<T> :: isFull(){
    return this->top == this->size-1;
}

template <class T>
bool Stack<T> :: push(const T &value){
    if(isFull()) return false;
    ptr[++top] = value;
    return true;
}

template <class T>
bool Stack<T> :: pop(T &value){
    if(isFull()) return false;
    value = ptr[top--];
    return true;
}

template <class T>
ostream& operator << (ostream& out, const Stack<T>& S){
    for(int i = 0; i< S.top; i++){
        out << S.ptr[i] << " ";
    }
    out << "\n";
    return out;
}

int main(){
    Stack <int> V;
    
    int valor = 10;
    while(V.push(valor++));

    cout << V;
}
