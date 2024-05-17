#include<iostream>
#include"Martyr.h"
using namespace std;



template<typename T>
class SNode
{
private:
    T data;  
    SNode<T>* next;
    template<typename T>
    friend class SinglyList;
public:
};
template<typename T>
class  SinglyList
{
private:
    SNode<T>* head;
    int n; // the size of the list ( the number of nodes )

public:
    SinglyList() // constructor
    {
        head = NULL;
        n = 0;
    }

    SinglyList(const SinglyList<T>& M) // copy constructor
    {
        SNode<T>* p = M.head;
        this->n = 0;
        while (p != NULL)
        {
            this->addLast(p->data); // adding to the end of the list
            p = p->next;
        }

    }

    SNode<T>* getHead()
    {
        return head;
    }

    bool empty() const
    {
        return head == NULL;
    }

    int size()
    {
        return n;
    }

    void addFront(const T& item)
    {
        SNode<T>* newNode = new SNode<T>;
        newNode->data = item; // newNode->data=item;
        newNode->next = NULL; // newNode->next=NULL;

        newNode->next = head; // if the list is empty , head will be NULL , so  newNode->next = NULL
        head = newNode;
        n++;

    }

    void addLast(const T& item)
    {
        SNode<T>* newNode = new SNode<T>;
        newNode->data = item;
        newNode->next = NULL;
        SNode<T>* p = head;
        if (empty()) // same as -> (n==0) or (head==NULL)
        {
            addFront(item);
            return;
        }
        while (p != NULL && p->next != NULL) // (p && p->next)  // mainly the second condition is the most important  , the first condition is for confirmation
            p = p->next;
        p->next = newNode;
        n++;
    }

    void add_at_the_end(const T& item)
    {
        SNode<T>* newNode = new SNode<T>;
        newNode->data = item;
        newNode->next = NULL;

        SNode<T>* p = head;
        if (n == 0) // empty
        {
            head = newNode;
            n++;
        }
        while (p != NULL && p->next != NULL)
        {
            p = p->next;
        }
        p->next = newNode;
        n++;
    }
    void updateMartyrLocationSingly(const string &name)
    {
        SNode<T>* p = head; 
        while (p!=NULL)
        {
            p->data.location = name; 
            p = p->next;
        }

    }

    void addInOrder(const T& item)
    {
        if (empty())
        {
            addFront(item);
            return;
        }
        SNode<T>* current = head;
        SNode<T>* prev = NULL;
        while (current && current->data < item)
        {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) // the first node's data is larger than item
        {
            addFront(item);
            return;
        }
        SNode<T>* newNode = new SNode<T>;
        newNode->next = NULL;
        newNode->data = item;
        newNode->next = current; // or newNode->next = c;
        prev->next = newNode;
        n++;
    }

    void diplay_list()
    {
        SNode<T>* p = head;
        cout << "head --> ";
        while (p != NULL)
        {
            cout << p->data << " --> ";
            p = p->next;
        }
        cout << "NULL" << endl;
    }

    T getback() const
    {
        if (empty()) exit(1);
        SNode<T>* p = head;
        while (p && p->next) // (p!=NULL && p->next != NULL) // mainly the second condition is the most important  , the first condition is for confirmation
        {
            p = p->next;
        }
        return p->data; 
    } 
    void updateNameSingly(const string& martyr, const string& locationy,
        const string& newName, const string& newAge, const string& newGender)
    {
        SNode <T>* p = head; 
        do
        {
            if (p->data.name == martyr && p->data.location == locationy) 
                break;
            p = p->next;
        } while (p!=head);

        if (p == head) return;

        p->data.name = newName; 
        p->data.age = newAge;  
        p->data.gender = newGender; 


    }

    T getFront() const
    {
        if (empty()) return NULL; // or NULL ?

        return head->data;
    }

    bool removeFront()
    {
        if (empty()) return false;
        SNode<T>* old = head;
        head = head->next;
        old->next = NULL; // the first node (head)
        delete old;
        n--;
        return true;
    }
    bool removeLast() // using one pointer
    {
        if (empty()) return false;
        if (head->next == NULL) // or n==1
        {
            return  removeFront();
        }
        SNode<T>* p = head;
        SNode<T>* check = head;
        while (p != NULL && (p->next)->next != NULL) // mainly the second condition is the most important  , the first condition is for confirmation 
        {
            p = p->next;
        }
        delete p->next;
        p->next = NULL;
        n--;
    }
    bool removeLast2() // using two pointers
    {
        if (empty()) return false;
        if (head->next == NULL)
        {
            return  removeFront();
        }
        SNode<T>* p = head;
        SNode<T>* check = head;
        while (check && check->next) // p--> p !=NULL --> the head is Not NULL 
        {
            p = check;
            check = check->next;
        }

        p->next = NULL;
        delete check;
        n--;
        return true;
    }
    bool deleteMartyrSingly(const string& name2)  
    {
        SNode<T>* p = findName(name2); 
        return removeByAddress(p);
    }

    bool removeByAddress( SNode<T>* pointer)
    {
        if (empty()) return false;

        // case 1 : having 1 node only in the list
        if (head->next == NULL)
            if (head == pointer) 
            {
                delete head;
                head = NULL;
                n--;
                return true;
            }
            else return false;

        //case 2 : having more than one node in the list
        SNode<T>* p = pointer; 
        if (p == NULL) return false;
        SNode<T>* prev = head;
        while (prev->next != p)
        {
            prev = prev->next;
        }
        prev->next = p->next; // or prev->next=prev-> next ->next;
        p->next = NULL; // in this case p-next is not the same as q->next->next .... because q->next is changed in the previous line code
        delete p;
        return true;
    }

    SNode<T>* findName(const string& namey)  
    {
        if (empty()) return NULL; 
        SNode<T>* p = head; 
        while (p != NULL)
        {
            if (p->data.name == namey)
            {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }

    SNode<T>* find(const T& item)
    {
        if (empty()) return NULL;
        SNode<T>* p = head;
        while (p != NULL)
        {
            if (p->data == item)
            {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }

    T get(SNode<T>* p)
    {
        if (p != NULL) return p->data;
        exit(1);
    }

    bool remove(const T& item)
    {
        if (empty()) return false;

        // case 1 : having 1 node only in the list
        if (head->next == NULL)
            if (head->data == item)
            {
                delete head;
                head = NULL;
                n--;
                return true;
            }
            else return false;

        //case 2 : having more than one node in the list
        SNode<T>* p = find(item);
        if (p == NULL) return false;
        SNode<T>* prev = head;
        while (prev->next != p)
        {
            prev = prev->next;
        }
        prev->next = p->next; // or prev->next=prev-> next ->next;
        p->next = NULL; // in this case p-next is not the same as q->next->next .... because q->next is changed in the previous line code
        delete p;
        return true;
    }
    bool remove2(const T& item) // with using the previous functions
    {
        SNode<T>* p = find(item);
        if (p == NULL) return false;

        if (p == head) removeFront();
        else if (p->next == NULL)
            removeLast();
        else
            removeBefore(p->next);

    }
    bool removeAfter(const T& item)
    {
        if (empty()) return false;
        if (head->next == NULL) return false; // or n==1

        SNode<T>* p = find(item);
        if (p == NULL) return false;
        if (p->next == NULL) return false;
        SNode<T>* q = p->next;
        q->next = NULL;
        p->next = p->next->next;
        delete q;
        n--;
        return true;
    }
    bool removeBefore(const T& item)
    {
        if (empty()) return false;
        if (head->next == NULL) return false; // or n==1
        SNode<T>* p = find(item);
        if (p == NULL) return false;
        // having 1 node
        if (p == head) return false;
        SNode<T>* q = head;

        // having 2 nodes
        if (q->next == p)
        {
            head = p;
            q->next = NULL;
            delete q; // or head
            n--;
            return true;
        }
        // having more than 2 nodes
        while (q->next->next != p)
        {
            q = q->next;
        }
        q->next->next = NULL;
        delete q->next;
        q->next = p;
        n--;
        return true;
    }
    bool removeAll() // using pointers
    {
        if (empty()) return false;
        SNode<T>* p = head;
        SNode<T>* q = head;
        while (q != NULL)
        {
            p = q;
            q = q->next;
            p->next = NULL;
            delete p;
        }
        head = NULL;
        n = 0;
        return true;

    }
    bool removeAll2() // using functions
    {
        if (empty()) return false;
        while (!empty()) // (head)
            removeFront();

        head = NULL;
        n = 0;
        return true;
    }

    void insertBefore(SNode<T>* p, const T& item)
    {
        SNode<T>* newNode = new SNode<T>;
        newNode->data = item; // newNode->data=item; 
        newNode->next = p;
        SNode<T>* q = head;
        if (empty()) // same as -> (n==0) or (head==NULL)
        {
            addFront(item);
            return;
        }
        if (p == head)
        {
            head = newNode;
            n++;
            return;
        }

        while (q->next != p)
        {
            q = q->next;
        }
        q->next = newNode;
        n++;
    }

    void insertAfter(SNode<T>* p, const T& item)
    {
        SNode<T>* newNode = new SNode<T>;
        newNode->data = item; // newNode->data=item; 
        SNode<T>* q = head;
        if (empty()) // same as -> (n==0) or (head==NULL)
        {
            addFront(item);
            return;
        }
        if (p == head)
        {
            newNode->next = p->next;
            p->next = newNode;
            n++;
            return;

        }
        while (q->next != p)
        {
            q = q->next;
        }

        newNode->next = p->next; // or  newNode->next = q->next->next;
        p->next = newNode;
        n++;

    }

    void swapNodes(SNode<T>* p1, SNode<T>* p2)
    {
        if (empty()) return;
        if (n == 1) return;
        if (p1 == head && p2 == head->next)
        {
            p1->next = p2->next;
            p2->next = p1;
            head = p2;
            return;
        }
        SNode<T>* z = p2->next;
        SNode<T>* q = head;
        while (q->next != p1) q = q->next;

        q->next = p2;
        p2->next = p1;
        p1->next = z;
    }
    /* else if (p2 == head && p1 == head->next)
       {
           p2->next = p1->next;
           p1->next = p2;
           head = p1;
           return;
       }*/
    void append_in_original(const SinglyList <T >& object)
    {
        SNode<T>* p = this->head;
        while (p->next != NULL)
        {
            p = p->next;
        }

        if (p == NULL) return; // for confirmation
        if (object.empty()) return; // or object.head==NULL
        p->next = object.head;
        this->n += object.n;
    }

    SinglyList<T>& operator =(const SinglyList<T>& M)
    {
        if (this->head != M.head)
            this->removeAll();
        else
            return *this;

        // Now same as the copy constructor

        SNode<T>* p = M.head;
        this->n = 0;
        while (p != NULL)
        {
            this->addLast(p->data); // adding to the end of the list
            p = p->next;
        }
        return *this;
    }

    void Sort(bool ascending)
    {
        if (empty())
        {
            return;
        }
        else if (ascending)
        {
            for (int i = 0; i < n - 1; i++)
            {
                SNode<T>* p = head;
                for (int j = 0; j < n - i - 1; j++)
                {
                    bool swapped = 0;
                    if ((p->data) > (p->next->data))
                    {
                        swapNodes(p, p->next);
                        swapped = 1;
                    }
                    if (swapped != 1)
                        p = p->next;
                }
            }
        }

        else
        {
            for (int i = 0; i < n - 1; i++)
            {
                SNode<T>* p = head;
                for (int j = 0; j < n - i - 1; j++)
                {
                    bool swapped = 0;
                    if ((p->data) < (p->next->data))
                    {
                        swapNodes(p, p->next);
                        swapped = 1;
                    }
                    if (swapped != 1)
                        p = p->next;
                }
            }
        }
    }// sort function end 


    friend ostream& operator << (ostream& out, SinglyList <T >& obj)
    {
        SNode<T>* p = obj.getHead();
        out << "head --> ";
        while (p != NULL)
        {
            out << p->getData() << " --> ";
            p = p->getNext();
        }
        out << "NULL" << endl;

        return out;
    }





    ~SinglyList()
    {
        while (!empty()) // (head)
            removeFront();

        head = NULL;
        n = 0;
    }



};
