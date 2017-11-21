#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
struct Node
{
    T value;
int x;
Node *Next, *Prev;
};


template <class T>
class List {

public:
    Node <T> *Head;
    Node <T> *Tail;
public:
List(): Head(NULL), Tail(NULL){};
~List();

    void Add(T value);
    void AddTail (T value);
    void Show();
    void ShowTail();
    void Ins(T value, int x);
};


template <class T>
List<T>::~List<T> ()
{
    Node <T> *temp;
    while (Head)
    {
        Tail=Head -> Next;
        delete Head;
        Head=Tail;
    }
}

template <class T>
void List<T> :: Add(T value) {
    Node <T> *temp=new Node <T>;
    temp -> Prev=NULL;
    temp -> value=value;

    if (Head!=NULL) {
        Node <T>  *pwn = Head;
        while (pwn != NULL){
            (pwn -> x)+=1;
            pwn = pwn->Next;
        }
        temp -> x = ((Head->x)-1);
        temp -> Next = Head;
        temp -> Prev= temp;
        Head = temp;
    }
    else {
        temp -> x = 1;
        temp -> Next=NULL;
        Head=Tail=temp;
    }
}

template <class T>
void List<T> :: AddTail(T value) {
    Node <T> *temp=new Node <T>;
    temp -> Next=NULL;
    temp -> value=value;

    if (Head!=NULL) {
        temp -> x = ((Head->x)+1);
        Tail -> Prev = Head;
        Tail -> Next= temp;
        Tail = temp;
    }
    else {
        temp -> x = 1;
        temp -> Prev=NULL;
        Head=Tail=temp;
    }
}


template <class T>
void List <T>:: Ins (T value, int x) {
    if (x==1) {
        Add(value);
    } else if (x== ((Tail-> x)+1)) {
        AddTail(value);
    } else if (x> ((Tail-> x)+1)) {
        cout << "don't do this" << x << endl;
    } else {
            Node <T> *pwn = Head;
            while ((pwn->x)!=x){
                pwn = pwn-> Next;
            }
            Node <T> *pwnprev= pwn -> Prev;
            Node <T> *temp = new Node <T>;
            temp -> value = value;
            temp -> x=x;

            pwnprev->Next=temp;
            temp -> Prev = pwnprev;
            temp -> Next = pwn;
            pwn -> Prev = temp;
            while (pwn != NULL) {
                (pwn -> x) +=1;
                pwn = pwn -> Next;

            }
        }}
template <class T>
void List <T>::Show() {

    Node <T> *temp = Head;
    while (temp != NULL) {
        cout << temp->x << " " << temp->value << ";";
        temp = temp->Next;
    }
    cout << "\n";
}

    template <class T>
    void List <T>::ShowTail() {

        Node <T> *temp = Tail;
        while (temp != NULL) {
            cout << temp->x << " " << temp->value << ";";
            temp = temp->Prev;
        }
        cout << "\n";
    }
int main() {

    List<int> lst;


 lst.AddTail(100);
    lst.AddTail(200);
    lst.AddTail(0);
    lst.AddTail(1888);



    lst.Add(1);
    lst.Add(2);
    lst.Add(6);
    lst.Add(4338);

    lst.Ins(454,1);
    lst.Ins(4114,7);


lst.AddTail (423);

    lst.Show();
cout << endl;
    lst.ShowTail();
    return 0;
}