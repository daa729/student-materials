

// TreeNode class should go in the "ufl_cap4053::fundamentals" namespace!
namespace ufl_cap4053 { namespace fundamentals {
template <typename T>
class TreeNode
{
private:
    T Data;
    TreeNode<T>* child;
    TreeNode<T>* next;
    TreeNode<T>* prev;
public:
    TreeNode<T>(){
        TreeNode<T>* child = nullptr;
        T Data = T();
    }
    TreeNode<T>(T element){
        TreeNode<T>* child = nullptr;
        T Data = element;
    }
    const T& getData() const{
        return Data;
    }
    size_t getChildCount() const{
        size_t count = 0;
        TreeNode<T>* temp = child;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }
    TreeNode<T>* getChild(size_t index){
        TreeNode<T>* temp = child;
        for(size_t i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp;
    }
    TreeNode<T>* getChild(size_t index) const{
        TreeNode<T>* temp = child;
        for(size_t i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp;
    }
    void addChild(TreeNode<T>* child){
        if(this->child == nullptr){
            this->child = child;
        }
        else{
            TreeNode<T>* temp = this->child;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = child;
            child->prev = temp;
        }
    }
    TreeNode<T>* removeChild(size_t index){
        TreeNode<T>* temp = child;
        for(size_t i = 0; i < index; i++){
            temp = temp->next;
        }
        if(temp->prev != nullptr){
            temp->prev->next = temp->next;
        }
        if(temp->next != nullptr){
            temp->next->prev = temp->prev;
        }
        return temp;
    }
    void breadthFirstTraverse(void (*dataFunction)(const T)) const{
        TreeNode<T>* temp = child;
        while(temp != nullptr){
            dataFunction(temp->getData());
            temp = temp->next;
        }
    }
    void preOrderTraverse(void (*dataFunction)(const T)) const{
        TreeNode<T>* temp = child;
        while(temp != nullptr){
            dataFunction(temp->getData());
            temp->preOrderTraverse(dataFunction);
            temp = temp->next;
        }
    }
    void postOrderTraverse(void (*dataFunction)(const T)) const{
        TreeNode<T>* temp = child;
        while(temp != nullptr){
            temp->postOrderTraverse(dataFunction);
            dataFunction(temp->getData());
            temp = temp->next;
        }
    
    }
};




}}  // namespace ufl_cap4053::fundamentals

/*
TreeNode<T> 
public TreeNode<T>() 
Constructor for TreeNode. Should store a default-constructed data value and start with no children. 
public TreeNode<T>(T element) 
Constructor for TreeNode. Should store element as its data value and start with no children. 
public const T& getData() const 
Returns a reference to the stored data. 
public size_t getChildCount() const 
Returns the number of children of this node. 
public TreeNode<T>* getChild(size_t index) 
Returns the child node as specified by index. 
public TreeNode<T>* getChild(size_t index) const 
Returns the child node as specified by index. Note: this is the const version of this method. 
public void addChild(TreeNode<T>* child) 
Add child to the children of this node. 
public TreeNode<T>* removeChild(size_t index) 
Remove and return the child node at specified by index. (Note that this does not delete the node!) 
public void breadthFirstTraverse(void (*dataFunction)(const T)) const 
Breadth-first traversal starting at this node. Calls dataFunction on the element to process it. 
public void preOrderTraverse(void (*dataFunction)(const T)) const 
Pre-order traversal starting at this node. Calls dataFunction on the element to process it. 
public void postOrderTraverse(void (*dataFunction)(const T)) const 
Post-order traversal starting at this node. Calls dataFunction on the element to process it.


*/