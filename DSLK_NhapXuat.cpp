#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class dslk;
class node{
friend dslk;
  int data;
  node* next;
public:
  node(int _data = 0){
    data = _data;
    next = NULL;
  }
  node(const node & p){
    data = p.data;
    next = p.next;
  }
  void crNode(node p){
    data = p.data;
    next = NULL;
  }
  int get_data(){
    return data;
  }
};

class dslk{
  node* first;
  node* last;
  int iC;
public:
  dslk(){
    first = last = NULL;
    iC = 0;
  }
  void nhapcuoi(int _data){
    node *p = new node(_data);
    if(first == NULL){
      first = last = p;
    }else{
      last -> next = p;
      last = p;
    }
    iC ++;
  }
  
  void xuat(){
    node *p = first;
    while(p -> next != NULL){
      cout << p -> data << ' ';
      p = p -> next;
    }
  }
  
  node* get_last(){
    return last;
  }
  
  int get_iC(){
     return iC;
  }
};

int main(){
  int s;
  dslk p;
  
  cin >> s;
  while(s != -1){
    p.nhapcuoi(s);
    cin >> s;
  }
  
  cout << "DSLK ban dau: ";
  if(p.get_iC() != 0){
    p.xuat();
    cout << p.get_last() -> get_data();
  }
  return 0;
}
