#pragma once
#include <iostream>
//#include "Node.hpp"
#include <vector>
using namespace std;
#include <stack>
//template<typename T>
namespace ariel{
    //template<class T = string>
class OrgChart{
    //class Node{};
            private:
        //template<typename T>
        struct Node {
		string position;
		vector<Node*> children;
		Node(string p)
			: position(p){
		}
        Node()
			: position(NULL){
		}
        string get_position(){
            return position;
        }
        vector<Node*> get_children(){
                v.clear();
                stack<Node*> stack;
                stack.push(&root);
                while(!stack.empty()){
                    Node* current = stack.pop();
                    if(current.position == root){
                        current.add_child(&(new Node(child)));
                        return &OrgChart;
                    }
                    v.push_back(current);
                    for(size_t i=0;i<current.children.size();i++){
                        stack.push(&(current.children[i]));
                    }
                }
        }
        Node& add_child(Node& child){
            this->children.push_back(&child);
            return child;
        }
	    };
        Node* root;
    public:
        OrgChart(){root = new Node();};
        //OrgChart(T a = NULL){root = new Node();};
        //template<class T> OrgChart(T){};
        //template<typename T> 
        void add_root(string root){
            this->root = new Node(root);
            //return *this;
        }
        //template<typename T> 
        OrgChart& add_sub(T root, T child){
            new stack<T>
            return *this;
        }
        //template<typename T> 
        bool add_sub_help( string root, string child, size_t size){
            for(size_t i=size; i<this->root->get_children().size(); i++){
                if(root == this->root->get_children()[i]->get_position()){
                    Node new_child(child);
                    this->root->get_children()[i]->add_child(new_child);
                    return true;
                }
                add_sub_help(this->root->get_children()[i]->get_position(),child,i);
            }
            return false;
        }
};
}