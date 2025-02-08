#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next =NULL;
    }
};
class list {
    node* head;
    node*  tail;
public:
    list() {
        head = tail = NULL;
    }
        void pushfront(int val) {

            node* newnode= new node(val);
            if(head==NULL) {
                head= tail =newnode;
                return;
            }else {
                newnode -> next= head;
                head= newnode;
            }
        }
    void print_ll() {
        node* temp = head;

        while(temp!=NULL) {
            cout<< temp-> data<< "->";
            temp= temp-> next;
        }
    }
};

int main() {
    list ll;
    ll.pushfront(1);
    ll.pushfront(2);
    ll.pushfront(3);
    ll.print_ll();

}

/*  OUTPUT : 
    3->2->1->  */

