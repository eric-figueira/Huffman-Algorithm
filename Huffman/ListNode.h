#ifndef LISTNODE
#define LISTNODE


using namespace std;

class ListNode
{
    private:
        unsigned char data;
        ListNode* next;

    public:
        unsigned char get_data() const;
        void set_data(unsigned char data);
        void set_next(ListNode* n);

        ListNode* get_next() const;

        ListNode();
        ListNode(unsigned char data);
        ListNode(unsigned char data, ListNode* next);
};

#endif