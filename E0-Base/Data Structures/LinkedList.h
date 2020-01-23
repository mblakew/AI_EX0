

// LinkedList class should go in the "ufl_cap4053::fundamentals" namespace!
namespace ufl_cap4053 { namespace fundamentals {
        template <typename T>
        class LinkedList{
        public:
            class Iterator;

            T operator*() const;
            //Return the element at the iterator's current position in the queue.
            Iterator& operator++();
            //Pre-increment overload; advance the operator one position in the list. Return this iterator. NOTE: if the iterator has reached the end of the list (past the last element), ita should be equal to LinkedList<T>::end().
            bool operator==(Iterator const& rhs);
            //Returns true it both iterators point to the same node in the list, and false otherwise.
            bool operator!=(Iterator const& rhs);
            //Returns false it both iterators point to the same node in the list, and true otherwise.

            LinkedList<T>() {
                root = nullptr;
            }
            //        This is the constructor for LinkedList.

            Iterator begin() const{
                return Iterator(root);
            }
            //        Returns an Iterator pointing to the beginning of the list.
            Iterator end() const;
            //        Returns an Iterator pointing past the end of the list (an invalid, unique state).
            bool isEmpty() const;
            //        Returns true if there are no elements, false otherwise.
            T getFront() const;
            //    Returns the first element in the list.
            T getBack() const;
            //    Returns the last element in the list.
            void enqueue(T element);
            //    Inserts the specified element to the list.
            void dequeue();
            //        Removes the first element from the list.
            void pop();
            //        Removes the last element from the list.
            void clear();
            //        Removes all elements from the list.
            bool contains(T element) const;
            //        Returns true if you find a node whose data equals the specified element, false otherwise.
            void remove(T element);
            //        Removes the first node you find whose data equals the specified element.
            void *root;
        };



    } }  // namespace ufl_cap4053::fundamentals
