#include <queue>

// TreeNode class should go in the "ufl_cap4053::fundamentals" namespace!
namespace ufl_cap4053 { namespace fundamentals {
    using namespace std;
template <typename T>
class TreeNode
{
    vector<TreeNode<T>*> Children;
    TreeNode<T>* Parent;
   
    T data;
public:
    TreeNode() {
        data = T();
        Children = vector<TreeNode<T>*>();
        Parent = nullptr; // signifies root
    }
    TreeNode(T element) {
        data = element;
        Children = vector<TreeNode<T>*>();
        Parent = nullptr; // signifies root
    }
    const T& getData() const {
        return data;
    }
    size_t getChildCount() const {
        return Children.size();
    }
    TreeNode<T>* getChild(size_t index) {
        return Children[index];
    }
    TreeNode<T>* getChild(size_t index) const {
        return Children[index];
    }
    void addChild(TreeNode<T>* child) {
                
        Parent = this;
        Children.push_back(child);

    }
    TreeNode<T>* removeChild(size_t index) {
        TreeNode<T>* temp = Children[index];
        Children.erase(Children.begin() + index);
        return temp;
    }
    void breadthFirstTraverse(void (*dataFunction)(const T)) const {
        queue<TreeNode<T>*> q;
        q.push(Parent);
        while (!q.empty()) {
            TreeNode<T>* temp = q.front();
            q.pop();
            dataFunction(temp->getData());
            for (int i = 0; i < temp->getChildCount(); i++) {
                q.push(temp->getChild(i));
            }
        }
    }
    void preOrderTraverse(void (*dataFunction)(const T)) const {
        dataFunction(this->getData());
        for (int i = 0; i < this->getChildCount(); i++) {
            this->getChild(i)->preOrderTraverse(dataFunction);
        }
    }
    void postOrderTraverse(void (*dataFunction)(const T)) const {
        for (int i = 0; i < this->getChildCount(); i++) {
            this->getChild(i)->postOrderTraverse(dataFunction);
        }
        dataFunction(this->getData());
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