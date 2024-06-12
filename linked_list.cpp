#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int val){
            this->val = val;
            next = NULL;
        }
};

class LL{
    Node* head=NULL;
    Node* cur=NULL;
    int size=0;
    public:
        LL(int val){
            Node* node = new Node(val);
            head = node;
            cur = head;
            size +=1;
        }
        void insert_el(int el){
            Node* node = new Node(el);
            if(head == NULL){
                head = node;
            }
            else{
                cur->next=node;
            }
            cur = node;
            size+=1;
        }
        void traverse(){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
        void delete_el(int pos){
            if(pos>size-1){
                cout<<"enter valid position"<<endl;
                return;
            }
            if(pos == 0){
                Node* temp = head->next;
                delete head;
                head = temp;
                if(size == 1) cur = NULL;
            }
            else{
                Node* curr = head;
                Node* prev = NULL;
                for(int i=0;i<pos;i++){
                    prev=curr;
                    curr=curr->next;
                }
                Node* temp = curr->next;
                delete curr;
                prev->next = temp;
                if(pos == size-1){
                    cur = prev;
                }
            }
            size--;
        }
        void reverse(){
            Node* curr = head;
            Node* prev = NULL;
            while(curr!=NULL){
                Node* temp2 = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp2;
            }
            head = prev;
        }

};

int main(){
    LL linked_list(5);
    linked_list.insert_el(3);
    linked_list.insert_el(18);
    linked_list.insert_el(4);
    linked_list.insert_el(99);
    linked_list.traverse();
    linked_list.delete_el(0);
    linked_list.traverse();
    linked_list.delete_el(1);
    linked_list.traverse();
    linked_list.delete_el(2);
    linked_list.traverse();
    linked_list.insert_el(10);
    linked_list.traverse();
    linked_list.delete_el(2);
    linked_list.traverse();
    linked_list.delete_el(0);
    linked_list.traverse();
    linked_list.delete_el(0);
    linked_list.traverse();
    linked_list.insert_el(10);
    linked_list.traverse();
    linked_list.insert_el(18);
    linked_list.insert_el(4);
    linked_list.insert_el(99);
    linked_list.traverse();

    linked_list.reverse();
    linked_list.traverse();
    linked_list.reverse();
    linked_list.traverse();
    linked_list.delete_el(0);
    linked_list.traverse();
    linked_list.delete_el(2);
    linked_list.traverse();
    linked_list.delete_el(0);
    linked_list.traverse();

    linked_list.reverse();
    linked_list.traverse();
    linked_list.insert_el(10);
    linked_list.traverse();
    linked_list.reverse();
    linked_list.traverse();

    return 0;
}

// 5 3 18 4 99
// 3 18 4 99
// 3 4 99
// 3 4
// 3 4 10
// 3 4
// 4

// 10
// 10 18 4 99
// 99 4 18 10
// 10 18 4 99
// 18 4 99
// 18 4
// 4
// 4
// 4 10
// 10 4