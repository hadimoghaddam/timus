#include <stdio.h>
#include <stdlib.h>
#include <vector>
struct node{
  node *left;
  node *right;
  int val;
  node(int valIn) : left(NULL) ,right(NULL), val(valIn) {}
};
class tree{
  private:
    node * head;

    void printTreePvt(node *nodePtr){
      if(nodePtr->right != NULL)
        printTreePvt(nodePtr->right);
      if(nodePtr->left != NULL)
        printTreePvt(nodePtr->left);

      printf("%d\n",nodePtr->val);
    } 
   
    void addNodePvt(node * nodePtr ,int val){

      if (val > (nodePtr->val)){
        if(nodePtr->right!=NULL)
          addNodePvt(nodePtr->right, val);
        else
          nodePtr->right = new node(val);
      }
      else{
        if(nodePtr->left!=NULL)
          addNodePvt(nodePtr->left, val);
        else
          nodePtr->left = new node(val);
      }
      
    }

  public:
    tree(int val):  head( new node(val)){}
    void printTree(){
      printTreePvt(head);
    }
    void addNode(int val){
      addNodePvt(head, val);
    }
};

using namespace std;
int main(){

  int numPar,newMem;
  vector<int> membList;
  scanf("%d",&numPar);

  for(int i=0;i<numPar;i++){
    scanf("%d",&newMem);
    membList.push_back(newMem);
  }
  tree parliment(membList[membList.size()-1]);
  for(int i=membList.size()-2;i>=0;i--){
    parliment.addNode(membList[i]);
  }

  parliment.printTree();
return 0;
}


