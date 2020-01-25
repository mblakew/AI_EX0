#include <list>
using namespace std;


// TreeNode class should go in the "ufl_cap4053::fundamentals" namespace!
namespace ufl_cap4053 {
    namespace fundamentals {

        template <class T>
        class TreeNode {

        public:
            //Constructor for TreeNode. Should store a default constructed
            //data value and start with no children
            TreeNode<T>()
            {
                val = NULL;

                num_child = 0;

            }

            //Constructor for TreeNode. Should store
            //an element as its dara value and start
            //with no children
            TreeNode<T>(T element)
            {
                num_child = 0;

                val = element;
            }


            //returns a reference to the stored data
            const T& getData() const
            {
                return val;
            }

            //returns the child node at specified by index
            TreeNode *getChild(size_t index)
            {
                list<TreeNode*> tempTree(binaryTree);
                for(int i = 0; i < index; i++){
                    if(tempTree.empty())
                        break;
                    tempTree.pop_front();
                }
                return !tempTree.empty() ? tempTree.front() : nullptr;
            }

            //return sthe number of children
            //of this node
            size_t getChildCount() const
            {
                return binaryTree.size();
            }

            //returns the child node at specified by idex
            //the const version of the other method
            TreeNode* getChild(size_t index) const
            {
                list<TreeNode*> tempTree2(binaryTree);
                for(int i = 0; i < index; i++){
                    if(tempTree2.empty())
                        break;
                    tempTree2.pop_front();
                }

                return !tempTree2.empty() ? tempTree2.front() : nullptr;

            }

            //adds child to the children of this node
            void addChild(TreeNode* child)
            {
                num_child++;
                //push child back
                binaryTree.push_back(child);
            }

            //removes a chid at the node
            //specified by index
            void removeChild(size_t index)
            {
                int counter = 0;
                //iterator to traverse tree
                auto iterator = binaryTree.begin();
                for(int i = 0; iterator != binaryTree.end(); i++){
                    if (index == i){
                        num_child = num_child - 1;
                        binaryTree.remove(*iterator);
                        return;
                    }
                }
            }
            //Breadth-first traversal starting at this node
            void breadthFirstTraverse(void (*dataFunction)(const T)) const
            {
                list<TreeNode> tempTree;
                tempTree.push_front(*this);

                //while the tree is not empty
                //continue iterating
                size_t counter = 0;
                while (tempTree.empty() == false)
                {
                    TreeNode n = tempTree.front();
                    tempTree.pop_front();
                    (*dataFunction)(n.getData());
                    while(counter < n.getChildCount()){
                        tempTree.push_back(*n.getChild(counter));
                        counter++;
                    }

                }

            }

            void preOrderTraverse(void (*dataFunction)(const T))
            {
                (*dataFunction)(val);

                for(int i = 0; i < binaryTree.size(); i++){
                    getChild(i)->preOrderTraverse(dataFunction);
                }
            }

            void postOrderTraverse(void (*dataFunction)(const T))
            {

                auto iter = binaryTree.begin();
                while (iter != binaryTree.end())
                {
                    (**iter).postOrderTraverse(dataFunction);
                    iter++;
                }
                (*dataFunction)(val);
            }

        protected:
            T val;
            int num_child;
            list<TreeNode*> binaryTree;
        };
    }}  // namespace ufl_cap4053::fundamentals
