#pragma once
#include <iostream>
#include <list>
#include <queue>

using namespace std;


// TreeNode class should go in the "ufl_cap4053::fundamentals" namespace!
namespace ufl_cap4053 { namespace fundamentals {

        template <class T>
        class TreeNode
        {

        public:


            TreeNode<T>(T element)
            {
                data = element;
                children = 0;
            }

            TreeNode<T>()
            {
                data = NULL;
                children = 0;

            }

            const T& getData() const
            {
                return data;
            }

            size_t getChildCount() const
            {
                return tree.size();
            }

            TreeNode* getChild(size_t index)
            {
                list<TreeNode*> tree2(tree);
                int size = 0;

                while (size < index && !tree2.empty())
                {
                    tree2.pop_front();
                    size++;
                }

                if (!tree2.empty())
                    return tree2.front();
                else
                    return nullptr;
            }

            TreeNode* getChild(size_t index) const
            {

                list<TreeNode*> tree2(tree);
                int size = 0;

                while (size < index && !tree2.empty())
                {
                    tree2.pop_front();
                    size++;
                }

                if (!tree2.empty())
                    return tree2.front();
                else
                    return nullptr;
            }

            void addChild(TreeNode* child)
            {
                tree.push_back(child);
                children++;
            }

            void removeChild(size_t index)
            {
                int counter = 0;
                auto it = tree.begin();

                while(it != tree.end())
                {
                    if (counter == index)
                    {
                        tree.remove(*it);
                        children--;
                        return;
                    }
                    it++;
                    counter++;

                }
            }

            void breadthFirstTraverse(void (*dataFunction)(const T)) const
            {
                list<TreeNode> tree2;

                tree2.push_front(*this);


                while (!tree2.empty())
                {
                    TreeNode node = tree2.front();
                    tree2.pop_front();

                    (*dataFunction)(node.getData());

                    for(size_t x = 0; x < node.getChildCount(); x++)
                    {
                        tree2.push_back(*node.getChild(x));
                    }
                }

            }

            void preOrderTraverse(void (*dataFunction)(const T))
            {
                (*dataFunction)(data);

                for (size_t x = 0; x < this->getChildCount(); x++)
                {
                    this->getChild(x)->preOrderTraverse(dataFunction);
                }
            }

            void postOrderTraverse(void (*dataFunction)(const T))
            {

                auto iter = tree.begin();
                while (iter != tree.end())
                {
                    (**iter).postOrderTraverse(dataFunction);
                    iter++;
                }
                (*dataFunction)(data);
            }

        protected:
            T data;
            int children;
            list<TreeNode*> tree;
        };
    }}  // namespace ufl_cap4053::fundamentals
