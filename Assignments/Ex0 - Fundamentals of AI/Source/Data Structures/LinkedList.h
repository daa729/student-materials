

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
    
        template <class T>
        class Node{
            private:
            <T> Data; 
            Node* Next; 
            Node* Prev;
            public: 
            Node(T temp){
                Data = temp; 
                Next = nullptr;
                Prev = nullptr;
            }
            <T> getData(){
                return Data;
            }
            Node* getNext(){
                return Next;
            }
            Node * getPrev()
            {
                return Prev;
            }

            void setData(<T> temp){
                Data = temp; 
            }
            void setNext(Node* next){
                Next = next; 
            }
            void setPrev(Node* prev){
                Prev = prev; 
            }



        }
     Node* Head;
     int Size;
    public LinkedList<T>(){
        Head = nullptr; 
        Size = 0;
    }
    //This is the constructor for LinkedList.
    public Iterator begin() const{

    }
    //Returns an Iterator pointing to the beginning of the list.
    public Iterator end() const{

    }
    //Returns an Iterator pointing past the end of the list (an invalid, unique state).
    public bool isEmpty() const{
        if(Head == nullptr){
            return true;
        }
        return false;
    }
    //Returns true if there are no elements, false otherwise.
    public T getFront() const{
        return Head; 
    }
    //Returns the first element in the list.
    public T getBack() const{
            Node *nav = Head;
            while (nav.getNex() t != nullptr)
            {
                nav = nav.getNext()
            }

            return nav;
    }
    //Returns the last element in the list.
    public void enqueue(T element){
        Node* Temp = Head;
        Node* Prev = nullptr; 
        bool placed = false; 
        while(placed ==false) {
            if(Temp == nullptr){
                Prev->Next = new Node(element);
                Prev->Next.setPrev(Prev); 
                placed =true;
                Size++;
            }else {
                Temp = Prev->Next;
            }
        }
    }
    //Inserts the specified element at the end of the list.
    public void dequeue(){
        if (Head == nullptr){
            cout<<"Dequeue on a null"<<endl;
        }else {
            Node* Temp = Head;
            Head = Head.getNext();
            delete Temp;
            Size--;
        }
    }
    //Removes the first element from the list.
    public void pop(){
        Node* nav = Head; 
        while(nav.getNex()t!=nullptr){
            nav = nav.getNext()
        }
         
        nav.getPrev.setData(nullptr);
        delete nav; 
    }
    //Removes the last element from the list.
    public void clear(){
       Node* temp = Head;
       while (temp!=nullptr){
        Head = temp.getNext();
        delete temp;
        temp= Head;
       }
    }
    //Removes all elements from the list.
    public bool contains(T element) const{
            Node *temp = Head;
            while (temp != nullptr)
            {
                
                if(temp.getData() == element) {
                    return true
                }
                temp = temp.getNext();
            }
            return false; 
    }
    //Returns true if you find a node whose data equals the specified element, false otherwise.
    public void remove(T element){
            Node *temp = Head;
            while (temp != nullptr)
            {

                if (temp.getData() == element)
                {
                    delete temp; 
                    return 0; 
                }
                temp = temp.getNext();
            }
        }
    
    //Removes the first node you find whose data equals the specified element.
    };




} }  // namespace ufl_cap4053::fundamentals
