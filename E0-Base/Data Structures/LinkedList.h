

// LinkedList class should go in the "ufl_cap4053::fundamentals" namespace!
namespace ufl_cap4053 { namespace fundamentals {
        template <typename T>

        class LinkedList{
            struct Node{
                T data;
                struct Node *next;
                struct Node *prev;
            };

            Node* head;
            Node* tail;

            public:
                LinkedList<T>() {
                    head = nullptr;
                    tail = nullptr;
                }

                class Iterator;


                //        This is the constructor for LinkedList.

                Iterator begin() const{
                    return Iterator(head);
                }
                //        Returns an Iterator pointing to the beginning of the list.
                Iterator end() const{
                    return Iterator(nullptr);
                }
                //        Returns an Iterator pointing past the end of the list (an invalid, unique state).

            class Iterator{
                    public:

                        T operator*() const{
                            return current->data;
                        }

                        //Return the element at the iterator's current position in the queue.
                        Iterator& operator++(){
                            Iterator iterator = *this;
                            ++*this;
                            return iterator;
                        }
                        //Pre-increment overload; advance the operator one position in the list. Return this iterator. NOTE: if the iterator has reached the end of the list (past the last element), ita should be equal to LinkedList<T>::end().
                        bool operator==(Iterator const& rhs){
                            return current == rhs.current;
                        }
                        //Returns true it both iterators point to the same node in the list, and false otherwise.
                        bool operator!=(Iterator const& rhs){
                            return current != rhs.current;
                        }
                        //Returns false it both iterators point to the same node in the list, and true otherwise.
                    private:
                        const Node* current;
                };

                bool isEmpty() const{
                    return head == nullptr;
                }
                //        Returns true if there are no elements, false otherwise.
                T getFront() const{
                    return head;
                }
                //    Returns the first element in the list.
                T getBack() const{
                    return tail;
                }
                //    Returns the last element in the list.
                void enqueue(T element){
                    Node *toInsert = new Node;
                    toInsert->data = element;
                    if(head != nullptr) {
                        head->prev = toInsert;
                        toInsert->next = head;
                        return;
                    }

                    toInsert->next = nullptr;
                    toInsert->prev = nullptr;
                    head = toInsert;
                }
                //    Inserts the specified element to the list.
                void dequeue(){
                    //if the head is not null, and the next is not null, there
                    //are at least 2 elements in the list, so we must detach
                    //the old head and set it to the second element, newHead
                    if(head != nullptr && head->next != nullptr){
                        Node *newHead = head->next;
                        newHead->prev = nullptr;
                        head = newHead;
                    }
                    else
                        head = nullptr;
                }
                //        Removes the first element from the list.
                void pop(){
                    //if head is null, then there is nothing in the list
                    //if head is not null, but tail is null there is 1 element
                    //if both head and tail are not null, then there are 2 elements
                    if(head == nullptr)
                        return head;
                    else if(head != nullptr && tail == nullptr){
                        return head;
                    }
                    else{
                        //create new tail, unlink with old tail, set tail to new tail
                        Node *newTail = tail->prev;
                        newTail->next = nullptr;
                        tail = newTail;
                    }
                }
                //        Removes the last element from the list.
                void clear();
                //        Removes all elements from the list.
                bool contains(T element) const;
                //        Returns true if you find a node whose data equals the specified element, false otherwise.
                void remove(T element);
                //        Removes the first node you find whose data equals the specified element.
            };





    } }  // namespace ufl_cap4053::fundamentals
