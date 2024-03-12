#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int size;
    int top;
    public:
    Stack(){
        top=-1;
        size=1000;
        arr=new int[size];
    }
    int push(int x){
        top++;
        arr[top]=x;
        return top;
    }
    void pop(){
        int x=arr[top];
        top--;
    }
    int top1(){
        return top;
    }
    int size1(){
        return top+1;
    }
};

int main(){
    Stack s;
    int n=5;
    for(int i=0;i<n;i++){
        cout<<s.push(i);
    }

    

}