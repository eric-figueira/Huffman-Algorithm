#ifndef LISTNODE
#define LISTNODE

#include "Types.h"

using namespace std;

class ListNode
{
    private:
        byte data;
        ListNode* next;

    public:
        byte get_data() const;
        void set_data(byte data);
        void set_next(ListNode* n);

        ListNode* get_next() const;

        ListNode();
        ListNode(byte data);
        ListNode(byte data, ListNode* next);
        ~ListNode();
};

#endif