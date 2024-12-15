//
// Created by dorbi on 03/03/2024.
//

#ifndef EX3_STACK_H
#define EX3_STACK_H

template <class T> class  Stack{
    struct  Link {
        T *data;
        Link *next;

        Link(T *dat, Link *nxt) : data(dat), next(nxt) {}
    }* head;
    bool own;

public:
    explicit Stack(bool own = true):head(0),own(own){}
    ~Stack() {
        if (!own)return;
        while (head)
            delete pop();
    }
    void push(T* dat){head = new Link(dat,head);}
    T* peek()const{return head? head->data:0;}
    T * pop(){
        if (head == 0) return 0;
        T *result = head->data;
        Link *oldHead = head;
        head = head->next;
        delete oldHead;
        return result;
    }
    bool owns()const {return own;}
    void owns(bool newownership){own = newownership;}
    explicit operator bool()const {return  head !=0;}
    bool operator()(const T* const other)const{
        return  *other == *(head->data);}

    };

#endif //EX3_STACK_H
