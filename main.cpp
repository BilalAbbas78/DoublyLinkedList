#include <iostream>
using namespace std;

class Node{
public:
    int data = 0;
    Node* prev = nullptr;
    Node* next = nullptr;
};

class DoublyLinkedList{
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    void appendAtStart(int value){
        Node *temp = new Node;
        temp->data = value;
        if (head == nullptr){
            head = temp;
            tail = temp;
            return;
        }


        temp->next = head;
        head->prev = temp;
        head = temp;

//        temp = nullptr;
//        delete temp;
    }

    void appendAtEnd(int value){
        Node *temp = new Node;
        temp->data = value;
        if (head == nullptr){
            head = temp;
            tail = temp;
            return;
        }

        tail->next = temp;
        temp->next = nullptr;
        temp->prev = tail;
        tail = temp;

//        temp = nullptr;
//        delete temp;
    }

    void appendAtIndex(int value, int index){
        if (index <= 0 || index-1 > this->count()){
            cout << "Enter valid index" << endl;
            return;
        }
        Node *temp = new Node;
        temp->data = value;
        if (index == 1){
            temp->next = head;
            head->prev = temp;
            temp->prev = nullptr;
            head = temp;
            return;
        }
        if (index-1 == this->count()){
            tail->next = temp;
            temp->next = nullptr;
            temp->prev = tail;
            tail = temp;
            return;
        }

        Node* temp2 = head;
        int count = 1;
        while (count != index-1){
            temp2 = temp2->next;
            count++;
        }

        temp2->next->prev = temp;
        temp->next = temp2->next;
        temp2->next = temp;
        temp->prev = temp2;

//        temp = nullptr;
//        temp2 = nullptr;
//        delete temp;
//        delete temp2;
    }

    void removeAt(int position){
        Node* temp = head;
        Node* temp2;
        int count = 1;
        while (position != count){
            temp2 = temp;
            temp = temp->next;
            count++;
        }
        temp2->next = temp2->next->next;
        temp->prev = temp2;
        (temp2->next->next)->prev = temp;
    }

    int search(int value){
        Node* temp = head;
        int count = 1;
        while (temp != nullptr && temp->data != value ){
            count++;
            temp = temp->next;
        }
        if (temp != nullptr)
            return count;
        return 0;

//        delete temp;
    }

    int count(){
        Node* temp = head;
        int count = 1;
        while (temp->next != nullptr){
            count++;
            temp = temp->next;
        }

//        temp = nullptr;
//        delete temp;

        return count;
    }

    void moveToFront(int value){
        if (search(value) == 0){
            cout << "Element not found" << endl;
            return;
        }
        Node* temp = head;
        while (temp->data != value){
            temp = temp->next;
        }

        if (temp == head)
            return;

        if (temp == tail){
            temp->prev->next = nullptr;
            tail = temp->prev;
        } else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        temp->prev = nullptr;
        temp->next = head;
        head->prev = temp;
        head = temp;

//        temp = nullptr;
//        delete temp;
    }

    void moveToEnd(int value){
        if (search(value) == 0){
            cout << "Element not found" << endl;
            return;
        }
        Node* temp = head;
        while (temp->data != value) {
            temp = temp->next;
        }

        if (temp == tail)
            return;

        if (temp == head){
            temp->next->prev = nullptr;
            head = temp->next;

        } else{
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
        }

        temp->next = nullptr;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;

        temp = nullptr;
        delete temp;


    }


    void print(){
        if (head == nullptr){
            cout << "Linked list is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;

//        temp = nullptr;
//        delete temp;
    }

    void printReverse(){
        if (head == nullptr){
            cout << "Linked list is empty" << endl;
            return;
        }
        Node* temp = tail;
        while (temp != head->prev){
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;

//        temp = nullptr;
//        delete temp;
    }

    void deleteFromStart(){
        if (head == tail){
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    void deleteFromEnd(){
        if (head == tail){
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    void deleteAt(int index){
        if (index <= 0 || index > this->count()){
            cout << "Enter valid index" << endl;
            return;
        }
        if (head == tail){
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        if (index == 1){
            head->next->prev = nullptr;
            head = head->next;
            delete temp;
            return;
        }
        if (index == this->count()){
            temp = tail;
            tail->prev->next = nullptr;
            tail = tail->prev;
            delete temp;
            return;
        }
        int count = 1;
        while (count != index){
            temp = temp->next;
            count++;
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
    }

    void deleteNodeByValue(int value){
        if (head->data == value){
            head = head->next;
            return;
        }
        if (tail->data == value){
            tail = tail->prev;
            return;
        }
        Node* itr = head;
        while (itr->data != value){
            itr = itr->next;
        }

        itr->next->prev = itr->prev;
        itr->prev->next = itr->next;

        delete itr;
    }


//    void deleteDuplicates(){
//        Node* temp = head;
//        Node* temp2 = temp->next;
//
//        while (temp){
//            temp2 = temp->next;
//            while (temp2){
//                cout << "Temp " << temp->data << " Temp2 " << temp2->data << endl;
//                if (temp->data == temp2->data){
//                    cout << "Value matched " << temp2->data;
//                    deleteNodeByValue(temp2->data);
//                    cout << "deleted";
////                    temp2->next->prev = temp2->prev;
////                    temp2->prev->next = temp2->next;
//                }
//                temp2 = temp2->next;
//            }
//            temp = temp->next;
//        }
//
//    }



};

int main() {
    DoublyLinkedList l;

    l.appendAtEnd(1);
    l.appendAtEnd(2);
    l.appendAtEnd(3);
    l.appendAtStart(0);



    l.print();
    l.printReverse();


}
