#include "duallylist.h"

Node::Node(){
    Data = 0;
    Next = nullptr;
    Prev = nullptr;
}

Node::Node(int value):Data(value){
    Next = nullptr;
    Prev = nullptr;
}

DuallyList::DuallyList(){
    Size = 0;
    Head = nullptr;
    Tail = nullptr;
}

DuallyList::~DuallyList(){

    Node *cur = Head;
    Node *next = nullptr;

    while(cur){
        next = cur->getNext();
        //        delete Data   //Если ну вдруг буду инты хранить в куче ;)
        delete cur;
        cur = next;
    }
}

void DuallyList::push_back(int value){

    Node *new_node = new Node(value);

    new_node->setNext(nullptr);
    new_node->setPrev(Tail);

    if (Tail) {
        Tail->setNext(new_node);
    }

    Tail = new_node;

    if (Head == nullptr) {
        Head = new_node;
    }

    ++Size;
}

int DuallyList::popback(){

    if(Size == 0){ throw std::out_of_range("Empty data"); }

    int return_data = 0;

    Node *node_tail = Tail;         //присваиваем в node_tail текущий хвост
    Tail = Tail->getPrev();         //присваваем хвосту предыдущий узел, в случае если prev == nullptr, то хвост
    // указывет на nullptr. То есть голова и хвост указывали на один и тот же узел

    if(Tail){
        Tail->setNext(nullptr);        //в хорошем случае, в next записываем nullptr
    }
    else{
        Head = nullptr;                //в противном, голове присваиваем тоже nullptr (список пуст)
        //        Tail = nullptr;              //хвост уже указывает на nullptr
    }

    return_data = node_tail->getData();     //вытаскиваем данные
    delete node_tail;                       //освобождаем память, выделенную под бывший хвост
    --Size;                                 //уменьшаем размер списка

    return return_data;                     //возвращаем данные
}

void DuallyList::push_front(int value){


    Node *new_node = new Node(value);

    new_node->setNext(Head);
    new_node->setPrev(nullptr);

    if(Head){
        Head->setPrev(new_node);
    }

    Head = new_node;

    if(Tail == nullptr){
        Tail = new_node;
    }

    ++Size;
}

int DuallyList::pop_front(){

    if(Size == 0){ throw std::out_of_range("Empty data"); }

    int return_data = 0;

    Node *node_head = Head;

    Head = Head->getNext();
    if(Head){
        Head->setPrev(nullptr);
    }
    else{
        //        list->Head = nullptr;    //голова и так уже указывает на nullptr
        Tail = nullptr;            //Хвост теперь тоже указывает на nullptr(список пуст)
    }

    return_data = node_head->getData();
    delete node_head;
    --Size;

    return return_data;
}

void DuallyList::show_list(){

    if(Size == 0){ throw std::out_of_range("Empty data"); }
    Node *cur = Head;

    if(cur == nullptr){
        std::cout<<"[!!!ATTENTION!!!] List is empty"<<std::endl;
        return;
    }

    while(cur) {
        std::cout<<cur->getData()<<" ";
        cur = cur->getNext();
    }
    std::cout<<std::endl;
}


Node * DuallyList::operator[](int index){

    int index_cnt = -1;

    if((size_t)index >= Size || index < 0){
        std::cout<<"BAD INPUT INDEX"<<std::endl;
        return nullptr;
    }

    Node *cur = Head;

    while(cur) {
        ++index_cnt;
        if(index_cnt == index){
            return cur;
        }
        cur = cur->getNext();
    }

    return nullptr;;
}


bool Node::comp(Node *obj){
    return (this->getData() > obj->getData());
}
