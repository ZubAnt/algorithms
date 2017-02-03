#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>

template<class data_t, class priority_t>
class Huffman
{
public:
    Huffman();
    ~Huffman();
    void push_back_DataWithPriority(data_t data, priority_t priority);
    void build_bi_tree();
    std::string get_code(const data_t &data);
    std::string string_to_code(const std::string &str);

private:

    struct bi_Node{

        bi_Node(data_t data, priority_t priority)
        {
           Data = data;
           Priority = priority;
           Left = nullptr;
           Right = nullptr;
           empty_data = false;
        }
        bi_Node(bi_Node *left, bi_Node *right)
        {
            Priority = left->Priority + right->Priority;
            Left = left;
            Right = right;
            empty_data = true;
        }

        data_t Data;
        priority_t Priority;
        bi_Node *Left;
        bi_Node *Right;
        bool empty_data;
    };

    struct Comp
    {
        bool operator()(const bi_Node *p1, const bi_Node *p2)
        {return p1->Priority > p2->Priority;}
    };

    bi_Node *Root;

    std::vector<bi_Node*> v_node;
    std::vector<bool> code;
    std::unordered_map<data_t, std::string> table_code;

    void build_table_code(const bi_Node *root);
    std::string to_string_code(const std::vector<bool> &v);
    void destroy_bi_Tree(Huffman<data_t, priority_t>::bi_Node *root);
};

template<class data_t, class priority_t>
Huffman<data_t, priority_t>::Huffman()
{
    Root = nullptr;
}

template<class data_t, class priority_t>
Huffman<data_t, priority_t>::~Huffman()
{
    if(Root != nullptr){
        destroy_bi_Tree(Root);
        delete Root;
    }
}

template<class data_t, class priority_t>
void Huffman<data_t, priority_t>::push_back_DataWithPriority(data_t data, priority_t priority)
{
    v_node.push_back(new bi_Node(data, priority));
}

template<class data_t, class priority_t>
void Huffman<data_t, priority_t>::build_bi_tree()
{
    if(v_node.size() != 1){

        while (v_node.size() != 1) {

            std::sort(v_node.begin(), v_node.end(), Comp());

            bi_Node *left = v_node.back();

            v_node.pop_back();

            bi_Node *right= v_node.back();
            v_node.pop_back();

            bi_Node *root = new bi_Node(left, right);
            v_node.push_back(root);
        }

        Root = v_node.front();

        build_table_code(Root);
    }
    else if(v_node.size() == 1){

        Root = v_node.front();
        table_code.insert({Root->Data, std::string("0")});
    }
}

template<class data_t, class priority_t>
std::string Huffman<data_t, priority_t>::get_code(const data_t &data)
{
    std::string empty_string;
    if(table_code.find(data) != table_code.end()){

        return table_code[data];
    }
    return empty_string;
}

template<class data_t, class priority_t>
std::string Huffman<data_t, priority_t>::string_to_code(const std::string &str)
{
    std::string out_code;
    std::unordered_map<char, int> map_symb_numb;

    for(auto &symb:str){

        if(map_symb_numb.find(symb) != map_symb_numb.end()){

            map_symb_numb[symb] += 1;
        }
        else{

            map_symb_numb.insert({symb, 1});
        }
    }

    for(auto &it:map_symb_numb){
        push_back_DataWithPriority(it.first, it.second);
    }

    build_bi_tree();

    for(auto &c:str){
        out_code += get_code(c);
    }

    return out_code;
}

template<class data_t, class priority_t>
void Huffman<data_t, priority_t>::build_table_code(const Huffman<data_t, priority_t>::bi_Node *root)
{
    if(root->Left != nullptr){
        code.push_back(false);
        build_table_code(root->Left);
    }
    if(root->Right != nullptr){
        code.push_back(true);
        build_table_code(root->Right);
    }
    if(root->Left == nullptr && root->Right == nullptr){
        table_code[root->Data] = to_string_code(code);
    }
    code.pop_back();
}

template<class data_t, class priority_t>
std::string Huffman<data_t, priority_t>::to_string_code(const std::vector<bool> &b_code)
{
    std::string s_code;
    for(auto b:b_code){
        if(b){
            s_code += '1';
        }
        else{
            s_code += '0';
        }
    }
    return s_code;
}

template<class data_t, class priority_t>
void Huffman<data_t, priority_t>::destroy_bi_Tree(Huffman::bi_Node *root)
{
    if(root->Left != nullptr){
        destroy_bi_Tree(root->Left);
        delete root->Left;
    }
    if(root->Right != nullptr){
        destroy_bi_Tree(root->Right);
        delete root->Right;
    }
}

#endif // HUFFMAN_H
