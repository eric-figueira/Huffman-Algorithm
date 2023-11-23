#ifndef QUEUENODE
#define QUEUENODE


template <typename Data> 
class QueueNode 
{
  private:
    Data data;
    QueueNode<Data> *next;

  public:
    Data get_data() const;
    QueueNode<Data>* get_next() const;

    QueueNode();
    QueueNode(Data data);
    QueueNode(Data data, QueueNode *next);
};

#endif