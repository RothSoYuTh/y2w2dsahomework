#include<iostream>
#include"link.hpp"
using namespace std;


int main(){
    linkList list;
    list.insertFront(20);
    list.insertFront(30);
    list.insertFront(40);
    cout << "Size: "<<list.size()<<endl;
    list.printValue();

    list.insertEnd(50);
    list.printValue();
    cout << "Size: "<<list.size()<<endl;
    
    list.insertMiddle(22,1);
    list.printValue();
    cout << "Size: "<<list.size()<<endl;

    list.deleteFront();
    list.printValue();
    cout << "Size: "<<list.size()<<endl;
    
    list.deleteEnd();
    list.printValue();
    cout << "Size: "<<list.size()<<endl;
    
    list.deleteMiddle(1);
    list.printValue();
    cout << "Size: "<<list.size()<<endl;
    
    list.swap(0,1);
    list.printValue();
    cout << "Size: "<<list.size()<<endl;

    list.searchValue(22);
    return 0;
}