#ifndef LISTNODE
#define LISTNODE


template <typename Data>
class ListNode
{
private:
    Data data;
    ListNode<Data>* next;

public:
    Data get_data() const;
    void set_data(Data data);

    ListNode<Data>* get_next() const;

    ListNode();
    ListNode(Data data);
    ListNode(Data data, ListNode* next);
};

#endif