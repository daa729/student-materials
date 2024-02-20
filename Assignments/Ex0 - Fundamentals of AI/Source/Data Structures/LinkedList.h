#include <limits>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;
// LinkedList class should go in the "ufl_cap4053::fundamentals" namespace!
namespace ufl_cap4053 { namespace fundamentals {

    // template <class T> 
    // class LinkedList<T>::Iterator{
    // public T operator*() const
    //  //Return the element at the iterator's current position in the queue. 
    //  public Iterator &operator++()
    //  //Pre- increment overload;advance the operator one position in the list.Return this iterator.NOTE : if the iterator has reached the end of the list(past the last element), it should be equal to LinkedList<T>::end().
    //  public bool operator==(Iterator const &rhs)
    //     //Returns true if both iterators point to the same node in the list,and false otherwise.
    // public bool operator!=(Iterator const &rhs)
    // //Returns false if both iterators point to the same node in the list, and true otherwise
    // };


    template <class T>
    class LinkedList{
    
        private:
    class Node{
        public:
            T Data;  
            Node* Next; 
            Node* Prev;
            
            Node(T temp){
                Data = temp; 
                Next = nullptr;
                Prev = nullptr;
            }

           



        };
    class Iterator{
        Node* Current;
        public:
        Iterator(Node* current){
            Current = current;
        }
        
        T operator*() const{
            return Current->Data;
        }
        Iterator &operator++(){
            Current = Current->Next;
            return *this;
        }
        bool operator==(Iterator const &rhs){
            return rhs.Current == Current;
        }
        bool operator!=(Iterator const &rhs){
            return rhs.Current != Current;
        }
    };
    
    
    Node* Head;
    
    public:
        int Size;
    LinkedList<T>(){
        Head = nullptr; 
        Size = 0;
    }
    //This is the constructor for LinkedList.
    Iterator begin() const{
        return Iterator(Head);
    }
    //Returns an Iterator pointing to the beginning of the list.
    Iterator end() const{
        return Iterator(nullptr);
    }
    //Returns an Iterator pointing past the end of the list (an invalid, unique state).
    bool isEmpty() const{
        if(Head == nullptr){
            return true;
        }
        return false;
    }
    //Returns true if there are no elements, false otherwise.
   T getFront() const{
        return Head->Data; 
    }
    //Returns the first element in the list.
    T getBack() const{
            Node *nav = Head;
            while (nav->Next != nullptr)
            {
                nav = nav->Next;
            }

            return nav->Data;
    }
    //Returns the last element in the list.
    void enqueue(T element){
        Node* Temp = Head;
        Node* Prev = nullptr;
        bool placed = false; 
        while(placed ==false) {
            if (Temp == nullptr && Prev == nullptr) {
                Head = new Node(element);
                placed = true;
                Size++;
            }else if(Temp==nullptr){
                Prev->Next = new Node(element);
                Prev->Next->Prev = Prev; 
                placed =true;
                Size++;
            }else {
                Prev = Temp;
                Temp = Temp->Next;
                
            }
            
        }
    }
    //Inserts the specified element at the end of the list.
    void dequeue(){
        if (Head == nullptr){
          
        }else {
            Node* Temp = Head;
            Head = Head->Next;
            delete Temp;
            Size--;
        }
    }
    //Removes the first element from the list.
    void pop() {
        if (Head == nullptr) {
            
            return;
        }

        if (Head->Next == nullptr) {
            
            delete Head;
            Head = nullptr;
            Size = 0;
            return;
        }

        Node* nav = Head;
        while (nav->Next != nullptr) {
            nav = nav->Next;
        }

        if (nav->Prev != nullptr) {
            nav->Prev->Next = nullptr;
            delete nav;
            Size--;
        }
        else {
       
        }
    }

    //Removes the last element from the list.
    void clear(){
       Node* temp = Head;
       while (temp!=nullptr){
        Head = temp->Next;
        delete temp;
        temp=Head;
       }
       Size = 0;
    }
    //Removes all elements from the list.
    bool contains(T element) const{
            Node *temp = Head;
            while (temp != nullptr)
            {
                
                if(temp->Data == element) {
                    return true;
                }
                temp = temp->Next;
            }
            return false; 
    }
    //Returns true if you find a node whose data equals the specified element, false otherwise.
    void remove(T element){
        if (Head == nullptr) {
            
            return;
        }
        Node* Nav = Head;
        
        while (Nav!=nullptr)
        {
            if (Nav->Data == element) {

                if (Nav->Prev != nullptr) {
                    if (Nav->Next != nullptr) {
                        Nav->Prev->Next = Nav->Next;
                        Nav->Next->Prev = Nav->Prev;

                    }
                    else {
                        Nav->Prev->Next = nullptr;
                    }
                }
                else {
                    if (Nav->Next != nullptr) {
                        Head = Nav->Next;
                        Head->Prev = nullptr;
                    }
                }

                

                if (Nav->Next == nullptr && Nav->Prev == nullptr) {
                    Head = nullptr;
                    cout << "Cleared Head" << endl;
                }
                
                
                delete Nav;
                Size--;
                if (Size <= 0) {
                    Head = nullptr;
                }



                break;
            }
            Nav = Nav->Next;
        }





        }
    
    //Removes the first node you find whose data equals the specified element.
    };




} }  // namespace ufl_cap4053::fundamentals
