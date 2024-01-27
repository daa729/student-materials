

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
            private:
            T Data; 
            Node* Next; 
            Node* Prev;
            public: 
            Node(T temp){
                Data = temp; 
                Next = nullptr;
                Prev = nullptr;
            }
            T getData(){
                return Data;
            }
            Node* getNext(){
                return Next;
            }
            Node * getPrev()
            {
                return Prev;
            }

            void setData(T temp){
                Data = temp; 
            }
            void setNext(Node* next){
                Next = next; 
            }
            void setPrev(Node* prev){
                Prev = prev; 
            }



        };
    class Iterator{
        Node* Current;
        public:
        Iterator(Node* current){
            Current = current;
        }
        
        T operator*() const{
            return Current->getData();
        }
        Iterator &operator++(){
            Current = Current->getNext();
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
     int Size;
    public:
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
        return Head->getData(); 
    }
    //Returns the first element in the list.
    T getBack() const{
            Node *nav = Head;
            while (nav->getNext() != nullptr)
            {
                nav = nav->getNext();
            }

            return nav->getData();
    }
    //Returns the last element in the list.
    void enqueue(T element){
        Node* Temp = Head;
        Node* Prev = nullptr; 
        bool placed = false; 
        while(placed ==false) {
            if(Temp == nullptr){
                Prev->setNext(new Node(element));
                Prev->getNext()->setPrev(Prev); 
                placed =true;
                Size++;
            }else {
                Temp = Prev->getNext();
            }
        }
    }
    //Inserts the specified element at the end of the list.
    void dequeue(){
        if (Head == nullptr){
          
        }else {
            Node* Temp = Head;
            Head = Head->getNext();
            delete Temp;
            Size--;
        }
    }
    //Removes the first element from the list.
    void pop(){
        Node* nav = Head; 
        while(nav->getNext()!=nullptr){
            nav = nav->getNext();
        }
         
        nav->getPrev()->setData(nullptr);
        delete nav; 
    }
    //Removes the last element from the list.
    void clear(){
       Node* temp = Head;
       while (temp!=nullptr){
        Head = temp->getNext();
        delete temp;
        temp= Head;
       }
    }
    //Removes all elements from the list.
    bool contains(T element) const{
            Node *temp = Head;
            while (temp != nullptr)
            {
                
                if(temp->getData() == element) {
                    return true;
                }
                temp = temp->getNext();
            }
            return false; 
    }
    //Returns true if you find a node whose data equals the specified element, false otherwise.
    void remove(T element){
            Node* temp = Head;
            while (temp != nullptr)
            {

                if (temp->getData() == element)
                {
                    delete temp; 
                    return;
                }
                temp = temp->getNext();
            }
        }
    
    //Removes the first node you find whose data equals the specified element.
    };




} }  // namespace ufl_cap4053::fundamentals
