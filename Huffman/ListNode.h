#ifndef LISTNODE
#define LISTNODE


using namespace std;

class ListNode
{
private:
    char data;
    ListNode* next;

public:
    char get_data() const;
    void set_data(char data);
    void set_next(ListNode* n);

    ListNode* get_next() const;

    ListNode();
    ListNode(char data);
    ListNode(char data, ListNode* next);
    ~ListNode();
};

#endif