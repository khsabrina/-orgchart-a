#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

namespace ariel{
    template <class T = string>
    class OrgChart{
        private:
            class Node {
                public:
                T position;
                vector<Node*> children;
                Node(T p): position(p), children(){}
                Node(): position(nullptr), children(){}
                Node(Node* new_node):position(new_node->position),children(new_node->children){}
                void add_child(T child){
                    Node* new_child = new Node(child);
                    children.push_back(new_child);
                    
                }
            };
            class OrgChart_itertaor{
                private:
                    Node* current =nullptr;
                    size_t counter;
                    vector<Node*> current_order;
                public:
                    OrgChart_itertaor(Node* new_node , vector<Node*> vector): current(new_node), current_order(vector),counter(0) {}
                    OrgChart_itertaor(Node* new_node = nullptr): current(new_node),counter(0){}
                    T& operator*() const {
                        return current->position;
                    }
                    T* operator->() const {
                        return &(current->position);
                    }
                    OrgChart_itertaor& operator++() {
                        this->counter++;
                        this->current = current_order[this->counter];
                        return *this;
                    }
                    OrgChart_itertaor operator++(int) {
                        OrgChart_itertaor tmp= *this;
                        this->current= current_order[this->counter];
                        this->counter++;
                        return tmp;
		            }
                    bool operator==(const OrgChart_itertaor& another_node) const {
                        return this->current == another_node.current;
                    }
                    bool operator!=(const OrgChart_itertaor& another_node) const {
			            return !(*this == another_node);
		            }
		    };
            Node* root =nullptr;
            vector<Node*> level_order;
            vector<Node*> _reverse_order;
            vector<Node*> pre_order;
            
        public:
            OrgChart(): root(nullptr){}
            OrgChart& add_root(T new_root){
                Node* new_node = new Node(new_root);
                this->root= new_node;
                return *this;
            }
            void update_level_order(){
                queue<Node*> q;
                this->level_order.clear();
                q.push(this->root);
                while(!q.empty()){
                    Node* current=q.front();
                    q.pop();
                    this->level_order.push_back(current);
                    for(size_t i=0;i<current->children.size();i++){
                        q.push(current->children[i]);
                    }
                }
            }
            void update_reverse_order(){
                queue<Node*> q;
                stack<Node*> s;
                this->_reverse_order.clear();
                q.push(this->root);
                while(!q.empty()){
                    Node* current=q.front();
                    q.pop();
                    s.push(current);
                    if(current->children.size() >0){
                    for(int i= (current->children.size()-1) ; i>=0 ; i-- ){
                        q.push(current->children.at((size_t)i));
                    }
                    }
                }
                while(!s.empty()){
                    this->_reverse_order.push_back(s.top());
                    s.pop();
                }
            }
            void update_pre_order(){
                this->pre_order.clear();
                this->pre_order.push_back(this->root);
                update_pre_order_help(this->root->children,0);
            }
            void update_pre_order_help(vector<Node*> vector, size_t size){
                for(size_t i=size; i<vector.size(); i++){
                    this->pre_order.push_back(vector.at(i));
                    update_pre_order_help(vector.at(i)->children,size);
                }
            }
            OrgChart& add_sub(T root, T child){
                queue<Node*> q;
                q.push(this->root);
                while(!q.empty()){
                    Node* current=q.front();
                    q.pop();
                    if(current->position == root){
                        current->add_child(child);
                        // update_level_order();
                        // update_reverse_order();
                        // update_pre_order();
                        return *this;
                    }
                    for(size_t i=0;i<current->children.size();++i){
                        q.push(current->children[i]);
                    }
                }
                throw std::invalid_argument("cant find sup");;
            }
            OrgChart_itertaor begin_level_order() {
                update_level_order();
                return OrgChart_itertaor{this->level_order.at(0),this->level_order};
            }
            OrgChart_itertaor end_level_order() {
                return OrgChart_itertaor{};
            }
            OrgChart_itertaor begin_reverse_order() {
                update_reverse_order();
                return OrgChart_itertaor{this->_reverse_order.at(0),this->_reverse_order};
            }
            OrgChart_itertaor reverse_order() {
                return OrgChart_itertaor{};
            }
            OrgChart_itertaor begin_preorder() {
                update_pre_order();
                return OrgChart_itertaor{this->pre_order.at(0),this->pre_order};
            }
            OrgChart_itertaor end_preorder() {
                return OrgChart_itertaor{};
            }
            OrgChart_itertaor begin() {
                update_level_order();
                return OrgChart_itertaor{this->level_order.at(0),this->level_order};
            }
            OrgChart_itertaor end() {
                return OrgChart_itertaor{};
            }
            friend ostream& operator<< (ostream& output, OrgChart const &m) {
                return output;
            }


    };
}