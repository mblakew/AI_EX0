

// LinkedList class should go in the "ufl_cap4053::fundamentals" namespace!
namespace ufl_cap4053 { namespace fundamentals {
        using namespace std;
        template <class T>

        class LinkedList{
        public:
            struct Node{
                T data;
                Node *next = nullptr;
                Node *prev = nullptr;
            };

            class Iterator;

                explicit LinkedList<T>() {
                    head = nullptr;
                    tail = nullptr;
                }

            class Iterator {

            protected:
                Node *current;

            public:
                T operator*() const {
                    if (current)
                        return current->data;
                    else
                        return NULL;
                }

                Iterator &operator++() {
                    current = current->next;
                    return *this;
                }

                bool operator!=(Iterator const &rhs) {
                    return (current != rhs.current);
                }

                bool operator==(Iterator const &rhs) {
                    return (current == rhs.current);
                }


                Iterator(Node *head) {
                    current = head;
                };

            };

            Iterator begin() const {
                return head ? Iterator(head) : NULL;
            }

            Iterator end() const {
                return NULL;
            }

                bool isEmpty() const{
                    return head == nullptr;
                }
                //        Returns true if there are no elements, false otherwise.
                T getFront() const{
                    return head == NULL ? "null" : head->data;
                }
                //    Returns the first element in the list.
                T getBack() const{
                    return tail == NULL ? "null" : tail->data;
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
                    tail = NULL;
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
                    //empty list
                    Node *current = head;

                    if (head == nullptr)
                        return;
                    //value is at head
                    if (head->data == element) {
                        //only node
                        if (head->next == nullptr) {
                            head = nullptr;
                            return;
                        }else{
                            //multiple nodes
                            head = head->next;
                            head->prev = nullptr;
                            delete current;
                            return;
                        }
                    }

                    while(current != nullptr){
                        if(current->data == element){
                            if(current == tail){
                                if(current->prev){
                                    current->prev->next = nullptr;
                                    tail = current;
                                }
                                else
                                    tail = nullptr;
                            }
                            else{
                                current->prev->next = current->next;
                                current->next->prev = current->prev;
                            }
                            delete current;
                            return;
                        }
                        current = current->next;
                    }


                }

            ~LinkedList(){
                clear();
            }

        private:
                struct Node *head;
                struct Node *tail;
                //        Removes the first node you find whose data equals the specified element.


        };






    } }  // namespace ufl_cap4053::fundamentals
