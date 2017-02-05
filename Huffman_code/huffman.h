#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>


template<class data_t, class priority_t>
class Huffman
{
public:
    Huffman();
    ~Huffman();
    void push_back_DataWithPriority(data_t data, priority_t priority);
    void push_back_DataWithCode(data_t data, std::string code);
    void drop_table_code();
    void build_bi_tree_by_priority();
    void build_bi_tree_by_code();
    std::string get_code(const data_t &data);
    std::string string_to_code(const std::string &str);
    std::string code_to_string(const std::string &code);
    void show_table_code();


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
        bi_Node(bool jump = false){
            Jump = jump;
            Left = nullptr;
            Right = nullptr;
        }

        data_t Data;
        priority_t Priority;
        bi_Node *Left;
        bi_Node *Right;
        bool empty_data;
        bool Jump;
    };

    struct Comp
    {
        bool operator()(const bi_Node *p1, const bi_Node *p2)
        {return p1->Priority > p2->Priority;}
    };

    bi_Node *Root;

    std::vector<bi_Node*> v_node;
    std::vector<bool> code;
    std::unordered_map<data_t, std::string> table_data_code;
    std::unordered_map<std::string, data_t> table_code_data;

    void build_table_code(const bi_Node *root);
    data_t get_data(Huffman<data_t, priority_t>::bi_Node *root,
                    const std::__cxx11::string &code, size_t &index);

    std::string to_string_code(const std::vector<bool> &v);
    void destroy_bi_Node(Huffman<data_t, priority_t>::bi_Node *root);
    void create_bi_Node(Huffman<data_t, priority_t>::bi_Node *root, data_t &data, const std::string &code, size_t index);
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
        destroy_bi_Node(Root);
        delete Root;
    }
}

template<class data_t, class priority_t>
void Huffman<data_t, priority_t>::push_back_DataWithPriority(data_t data, priority_t priority)
{
    v_node.push_back(new bi_Node(data, priority));
}

template<class data_t, class priority_t>
void Huffman<data_t, priority_t>::push_back_DataWithCode(data_t data, std::string code)
{
    table_code_data.insert({code, data});
}

template<class data_t, class priority_t>
void Huffman<data_t, priority_t>::drop_table_code()
{
    table_data_code.clear();
}

template<class data_t, class priority_t>
void Huffman<data_t, priority_t>::build_bi_tree_by_priority()
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
        table_data_code.insert({Root->Data, std::string("0")});
    }
}

template<class data_t, class priority_t>
void Huffman<data_t, priority_t>::build_bi_tree_by_code()
{
    Root = new bi_Node;

    for(auto it = table_code_data.begin();
        it != table_code_data.end();
        ++it)
    {
        create_bi_Node(Root, it->second, it->first, 0);
    }
}

template<class data_t, class priority_t>
std::string Huffman<data_t, priority_t>::get_code(const data_t &data)
{
    std::string empty_string;
    if(table_data_code.find(data) != table_data_code.end()){

        return table_data_code[data];
    }
    return empty_string;
}

template<class data_t, class priority_t>
data_t Huffman<data_t, priority_t>::get_data(Huffman<data_t, priority_t>::bi_Node *root,
                                           const std::string &code, size_t &index)
{
    if((root->Left == nullptr && root->Right == nullptr) || index == code.length()){

        return root->Data;
    }

    if(root->Left != nullptr && code[index] == '0'){

        return get_data(root->Left, code, ++index);
    }
    else if(root->Right != nullptr && code[index] == '1'){

        return get_data(root->Right, code, ++index);
    }
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

    build_bi_tree_by_priority();

    for(auto &c:str){
        out_code += get_code(c);
    }

    std::fstream out_fstream("out.txt", std::fstream::out);
    out_fstream << map_symb_numb.size() << " " << out_code.length() << std::endl;

    for(auto &it:map_symb_numb){

        out_fstream << it.first << ": " << get_code(it.first) << std::endl;
    }
    out_fstream << out_code << std::endl;
    out_fstream.close();
    return out_code;
}

template<class data_t, class priority_t>
std::string Huffman<data_t, priority_t>::code_to_string(const std::string &code)
{
    std::string str;

    build_bi_tree_by_code();

    size_t len_code = code.length();
    size_t index = 0;

    while(index < len_code){

        str += get_data(Root, code, index);
    }

    return str;
}

template<class data_t, class priority_t>
void Huffman<data_t, priority_t>::show_table_code()
{
    for(auto &it:table_code_data){
        std::cout << it.first << " " << it.second << std::endl;
    }
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
        table_data_code[root->Data] = to_string_code(code);
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
void Huffman<data_t, priority_t>::destroy_bi_Node(Huffman::bi_Node *root)
{
    if(root->Left != nullptr){
        destroy_bi_Node(root->Left);
        delete root->Left;
    }
    if(root->Right != nullptr){
        destroy_bi_Node(root->Right);
        delete root->Right;
    }
}

template<class data_t, class priority_t>
void Huffman<data_t, priority_t>::create_bi_Node(Huffman::bi_Node *root, data_t &data, const std::string &code, size_t index)
{
    if(index == code.length()){

        root->Data = data;
        return;
    }
    else if(index < code.length()){

        if(code[index] == '0'){

            if(root->Left == nullptr){

                root->Left = new bi_Node(false);
            }

            create_bi_Node(root->Left, data, code, ++index);
        }
        else{

            if(root->Right == nullptr){

                root->Right = new bi_Node(true);
            }

            create_bi_Node(root->Right, data, code, ++index);
        }
    }
}

#endif // HUFFMAN_H
