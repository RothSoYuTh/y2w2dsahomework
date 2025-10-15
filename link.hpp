#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    

    Node(int data){
        this->data = data;
        next = nullptr;  
        
    }
};

class linkList{
    private:
    Node* head, *cur;
    int n;
    public:
        linkList(){
            head = nullptr;
            cur = nullptr;
            n = 0;
        }

        int size(){return n;}

        void printValue(){
            cur = head;
            while(cur){
                cout << cur->data<<"->";
                cur = cur->next;
            }
            cout << "Null"<< endl;
        }

        void traverse(){
            cur = head;
            while(cur->next != nullptr){
                cur = cur->next;
            }
        }

        void insertFront(int val){
            Node* nNode = new Node(val);
            nNode->next = head;
            head = nNode;
            n++;
        }

        void insertEnd(int val){
            if(head == nullptr){
                insertFront(val);
                return;
            }

            traverse();
            Node* nNode = new Node(val);
            cur->next = nNode;
            n++;
            
        }

        void insertMiddle(int val,int pos){
            if(pos > n || pos < 0){
                cout << "Out of range."<< endl;
                return;
            }
            if(pos == 0){
                insertFront(val);
                return;
            }
            if(pos == n){
                insertEnd(val);
                return;
            }
            Node* nNode = new Node(val);
            cur = head;
            for(int i = 0; i < pos-1; i++){
                cur = cur->next;
            }
            nNode->next = cur->next;
            cur->next = nNode;
            n++;
        }


        void deleteFront(){
            if(head == nullptr){
                cout << "Nothing to delete"<<endl;
                return;
            }
            Node* tmp = head;
            head = head->next;
            delete tmp;
            n--;
        }

        void deleteEnd(){
             if(head == nullptr){
                cout << "Nothing to delete"<<endl;
                return;
            }
            cur = head;
            while(cur->next->next !=  nullptr){
                cur = cur->next;
            }
            Node* tmp = cur->next;
            cur->next = nullptr;
            delete tmp;
            n--;
        }


        void deleteMiddle(int pos){
            if(head == nullptr || pos < 0){
                cout << "Nothing to delete"<<endl;
                return;
            }
            if(pos == 0){
                deleteFront();
                return;
            }
            if(pos == n){
                deleteEnd();
                return;
            }
            cur = head;
            for(int i = 0; i < pos-1; i++){
                cur = cur->next;
            }
            Node* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
            n--;
        }

        void swap(int pos1, int pos2){
            if (pos1 < 0 || pos2 < 0 || pos1 >= n || pos2 >= n) {
                cout << "Out of range" << endl;
                return;
            }


            if (pos1 == pos2) {
                cout << "Both positions are the same, no swap needed." << endl;
                return;
            }
            Node* posSwap1 = head;
            Node* posSwap2 = head;
            Node* pre1 = nullptr;
            Node* pre2 = nullptr;

            for(int i = 0; i < pos1; i++){
                pre1 = posSwap1;
                posSwap1 = posSwap1->next;
            }

            for(int i = 0; i < pos2; i++){
                pre2 = posSwap2;
                posSwap2 = posSwap2->next;
            }

            if(pre1 != nullptr){
                pre1->next = posSwap2;
            }else{
                head = posSwap2;
            }
            
            if(pre2 != nullptr){
                pre2->next = posSwap1;
            }else{
                head = posSwap1;
            }

            Node* temp = posSwap1->next;
            posSwap1->next = posSwap2->next;
            posSwap2->next = temp;
        }


        void searchValue(int val){
            if(head == nullptr ){
                cout << "No elememt to search!"<<endl;
                return;
            }

            cur = head;
            bool isFound = false;
            int pos = 0;
            while(cur){
                if(cur->data == val){
                    cout << "Value is found at position: "<<pos<<"."<< endl;
                    isFound = true;
                    return;
                }
                cur = cur->next;
                pos++;
            }

            if(!isFound){
                cout << "Element is not exist."<< endl;
            }
        }
};
