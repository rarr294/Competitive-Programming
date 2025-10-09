#include <string>
typedef unsigned int Str;

class Linked_list{
public:
  Node *head = new Node(0);
  Node *cpyhead = head;

  void addNode(int value){
    Node *node = new Node(value);

    head->next = node;
    head = head->next;
  }

  Node* getFirstNode(){
    return cpyhead->next;
  }
};

Node *parse(const std::string& list) {
   Linked_list linkList;
   Str size = list.length();
   if(list[0] =='n'){
    return nullptr;
   }else{
    std::string value;
    for(int a = 0;list[a] != 'n';a++){
      if(list[a] == ' '){
        if(value.size() == 0){
           continue;
        }
        linkList.addNode(stoi(value));
        value = "";
      }else if(list[a] >= 48 && list[a] <= 57){
        value += list[a];
      }
    }
  }
  return linkList.getFirstNode();
}
