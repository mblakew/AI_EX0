

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
                    return head == nullptr ? "null" : head->data;
                }
                //    Returns the first element in the list.
                T getBack() const{
                    return tail == nullptr ? "null" : tail->data;
                }
                //    Returns the last element in the list.
                void enqueue(T element){
                    Node *toInsert = new Node;
                    toInsert->data = element;
                    if(head == nullptr) {
                        toInsert->next = nullptr;
                        toInsert->prev = nullptr;
                        head = toInsert;
//                        Node *temp = head;
//                        temp->prev = toInsert;
//                        toInsert->next = temp;
//                        head = toInsert;
                    }
                    else if(tail == nullptr){
                        Node *curr = head;
                        while(curr->next != nullptr){
                            curr = curr->next;
                        }
                        toInsert->next = nullptr;
                        toInsert->prev = curr;
                        curr->next = toInsert;
                        tail = toInsert;
                    }
                    else{
                        tail->next = toInsert;
                        toInsert->prev = tail;
                        toInsert->next = nullptr;
                        tail = toInsert;
                    }
                }
                //    Inserts the specified element to the list.
                void dequeue(){
                    //if head is null, return
                    //if head->next is not null, increment head to next
                    //check if on tail after this move, if so set tail to null (avoid duplicate nodes)
                    //if head->next is null, remove head
                    if(head == NULL)
                        return;
                    else if(head->next != nullptr){
                        head = head->next;
                        head->prev = nullptr;
                        if(head->next == nullptr)
                            tail = nullptr;
                    } else{
                        head = nullptr;
                    }

                }
                //        Removes the first element from the list.
                void pop(){
                    if(!isEmpty()){
                        if(tail){
                            Node *temp = tail;
                            tail = temp->prev;
                            free(temp);
                            temp->next = nullptr;

                        } else {
                            head = nullptr;
                            tail = nullptr;
                        }
                    }
                    //if head is null, then there is nothing in the list
                    //if head is not null, but tail is null there is 1 element
                    //if both head and tail are not null, then there are 2 elements
//                    if(head == nullptr)
//                        return;
//                    if(tail == nullptr)
//                    Node *current = head;
//                    while(current->next != nullptr){
//                        current = current->next;
//                    }
//                    Node *prev = current->prev;
//                    current = nullptr;
//                    tail = prev;


                }
                //        Removes the last element from the list.
                void clear(){
                    Node *current = head;
                    Node *next;
                    while(current != nullptr){
                        next = current->next;
                        free(current);
                        current = next;
                    }
                    head = NULL;
                }
                //        Removes all elements from the list.
                bool contains(T element) const{
                    if(head == nullptr)
                        return false;
                    Node *curr = head;
                    while(curr != nullptr){
                        if(curr->data == element)
                            return true;
                        curr = curr->next;
                    }
                    return false;
                }
                //        Returns true if you find a node whose data equals the specified element, false otherwise.
                void remove(T element){
                    /* base case */
                    if (head == nullptr)
                        return;
                    else if (head->data == element && head->next == nullptr){
                        head = nullptr;
                        return;
                    }


                    Node *current = head;
                    while(current != nullptr){
                        //if find node and length > 2
                        if(current->data == element && current->next != nullptr && current->prev != nullptr){
                            Node *prev = current->prev;
                            Node *next = current->next;
                            next->prev = prev;
                            prev->next = next;
//                            free(current);
                        }
                        else if(current->data == element && current == head && current->next != nullptr){
                            //if head is to be removed and list length > 1
                            head = current->next;
                            head->prev = nullptr;
//                            free(current);
                        }
                        else if(current->data == element && current == head && current->next == nullptr){
                            //if head is to be removed and list length = 1
                            head = nullptr;
//                            free(current);
                        }
                        else{
                            //if tail is to be removed
                            tail = tail->prev;
//                            free(current);
                        }
                    }

                    /* Change next only if node to be
                    deleted is NOT the last node */
//                    if (del->next != NULL)
//                        del->next->prev = del->prev;
//
//                    /* Change prev only if node to be
//                    deleted is NOT the first node */
//                    if (del->prev != NULL)
//                        del->prev->next = del->next;
//
//                    /* Finally, free the memory occupied by del*/
//                    free(del);
//                    return;
//                    Node *current = head;
//                    while(current != nullptr){
//
//                        if(current->data == element){
//                            Node *next = current->next;
//                            Node *prev = current->prev;
//                            //head node removal list length > 1
//                            if(current == head && tail != nullptr){
//                                next->prev = nullptr;
//                                free(current);
//                                head = next;
//                                head->next = tail;
//                            }
//                            else if(current == head && tail == nullptr){
//
//                            }
//
//                        }
//                        free(current);
//                    }
//                    head = NULL;
                }
                //        Removes the first node you find whose data equals the specified element.
            };





    } }  // namespace ufl_cap4053::fundamentals
