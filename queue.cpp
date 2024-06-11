//fifo by array
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class queue_anshul{
        int *arr;
        int insert_var;
        int takeout_var;
        int size;
    public:
        queue_anshul(int n){
            cout<<"queue of "<<n<<" size is initialised"<<endl;
            arr = new int[n];
            insert_var = 0;
            takeout_var=0;
            size=n+1;
        }
        void push(int x){
            if( (insert_var+1) % size == takeout_var){
                cout<<"queue is filled, pop elements to inert new"<<endl;
            }
            else{
                cout<<x<<" is pushed"<<endl;
                arr[insert_var] = x;
                insert_var = (insert_var + 1) % size;
            }
        }
        void top(){
            if(insert_var==takeout_var){
                cout<<"NO elements in queue"<<endl;
                return ;
            }
            cout<<arr[takeout_var]<<" is the front value of queue"<<endl;
        }
        void pop(){
            if(insert_var==takeout_var){
                cout<<"NO elements in queue"<<endl;
                return;
            }
            cout<<arr[takeout_var]<<" is the popped value of queue"<<endl;
            takeout_var = (takeout_var+1)%size;
        }
        void isempty(){
            if(insert_var==takeout_var){
                cout<<"queue is EMPTY"<<endl;
            }
            else{
                cout<<"queue is NOT empty"<<endl;
            }
        }
        ~queue_anshul(){
            cout<<"queue of size "<<size-1<<" is released"<<endl;
            delete[] arr;
        }
};

int main(){
    queue_anshul *q_obj=new queue_anshul(5);
    q_obj->push(10);
    q_obj->push(3);
    q_obj->push(6);
    q_obj->push(86);
    q_obj->push(54);
    q_obj->push(333);
    q_obj->pop();
    q_obj->pop();
    q_obj->push(333);
    q_obj->top();
    q_obj->pop();
    q_obj->top();
    q_obj->pop();
    q_obj->pop();
    q_obj->pop();
    q_obj->pop();
    q_obj->push(69);
    q_obj->top();
    delete q_obj;

    return 0;
}

// queue of 5 size is initialised
// 10 is pushed
// 3 is pushed
// 6 is pushed
// 86 is pushed
// 54 is pushed
// queue is filled, pop elements to inert new
// 10 is the popped value of queue
// 3 is the popped value of queue
// 333 is pushed
// 6 is the front value of queue
// 6 is the popped value of queue
// 86 is the front value of queue
// 86 is the popped value of queue
// 54 is the popped value of queue
// 333 is the popped value of queue
// NO elements in queue
// 69 is pushed
// 69 is the front value of queue
// queue of size 5 is released