#ifndef LINKEDLIST
#define LINKEDLIST

#include "ListNode.h"


using namespace std;

class LinkedList
{
    private:
        ListNode* begin;
        ListNode* end;
        ListNode* current;
        ListNode* previous;

        unsigned int size;

    public:
        LinkedList();
        LinkedList(ListNode* begin, ListNode* end);
        //~LinkedList();

        ListNode* get_begin() const;
        ListNode* get_end() const;
        ListNode* get_current() const;
        ListNode* get_previous() const;

        unsigned int get_size() const;

        void set_begin(ListNode* data);
        void set_end(ListNode* data);
        void set_current(ListNode* data);
        void set_previous(ListNode* data);

        bool exists(unsigned char data);
        unsigned char get(unsigned int pos);
        void set(unsigned int pos, unsigned char data);
        void add(unsigned char data);
        void push(unsigned char data);
        void remove(unsigned char data);

        friend ofstream& operator<< (ofstream& os, const LinkedList& list);
};

#endif