#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
template <typename T>

class BinaryTreeNode {
    public :
    T data;
    int distance;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};




BinaryTreeNode<int>* input() {
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;

  if(rootData ==-1){
    return NULL;
  }

  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
  queue<BinaryTreeNode<int>*>q;

  q.push(root);
  while(q.size()!=0){
    BinaryTreeNode<int>*front=q.front();
    q.pop();

     int leftChild;
    cout<<"enter left child of : "<<front->data << endl;
     cin>>leftChild;
     if(leftChild!=-1){
        BinaryTreeNode<int>*lchild=new BinaryTreeNode<int>(leftChild);
        front->left=lchild;
        q.push(lchild);
     }
     int rightChild;
    cout<<"enter right child of : "<<front->data << endl;
     cin>>rightChild;
     if(rightChild!=-1){
        BinaryTreeNode<int>*rchild=new BinaryTreeNode<int>(rightChild);
        front->right=rchild;
        q.push(rchild);
     }
  }
  return root;

}




void printlevelwise(BinaryTreeNode<int>*root) {
   

  if(root ==NULL){
    return ;
  }

  
  queue<BinaryTreeNode<int>*>q;
  q.push(root);


  while(q.size()!=0){
    BinaryTreeNode<int>*front=q.front();
    q.pop();
cout<<front->data<<": ";

    
     if(root->left!=NULL){
        cout<<"L: "<<front->left->data;
        q.push(front->left);
     }else{
        cout<<"L: null";
     }
     cout<<",";
     
     if(root->right!=NULL){
        cout<<"R: "<<front->right->data;
        q.push(front->right);
     }else{
        cout<<"R: null";
     }
     cout<<"\n";
  }
 
}

class BST{
  public:
     BinaryTreeNode<int>*root;

     BST(){
      root=NULL;
     }
     ~BST(){
      delete root;
     }

 //insert ************************************************************************************************************************************************
 private:
 BinaryTreeNode<int>*Insert(BinaryTreeNode<int>*root,int data){
     if(root==NULL){
      BinaryTreeNode<int>*newroot=new BinaryTreeNode<int>(data);
      return newroot;
     }

     if(data>root->data){
   root->left= Insert(root->left,data);
 }else {
  root->right= Insert(root->right,data);
 }
 return root;
 }
 public:
 void insert(int data){
  this->root= Insert(root,data);
 }

 //delete ***********************************************************************************
 private:
 BinaryTreeNode<int>*deletedata(BinaryTreeNode<int>*root,int data){
  if(root==NULL){
    return NULL;
  }
  if(data>root->data){
    root->right =deletedata(root->right,data);
    return root;
  }else if(data <root->data){
    root->left=deletedata(root->left,data);
  }else{

    if(root->left==NULL&&root->right==NULL){
      delete root;
      return NULL;
    }else if(root->left==NULL){
      BinaryTreeNode<int>*temp=root->right;
      root->right=NULL;
      delete root->right;
      return temp;
    }else if(root->left==NULL){
      BinaryTreeNode<int>*temp=root->left;
      root->left=NULL;
      delete root->left;
      return temp;
    }else{
       BinaryTreeNode<int>*minroot=root->right;
       while(minroot->left!=NULL){
        minroot=minroot->left;
       }

       int rightmin=minroot->data;
       root->data=rightmin;
       deletedata(root,rightmin);
       return root;
    }
  }

 }

 public:
 void deldata(int data){
  root=deletedata(root,data);
 }

//  find data*******************************************************************************

};
  

BinaryTreeNode<int>* SortArray(int*arr, int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(arr[mid]);
   root->left=SortArray(arr,s,mid-1);
   root->right=SortArray(arr,mid+1,e);
   return root;
}
BinaryTreeNode<int>* BST(int*arr,int n){
   return SortArray(arr,0,n-1);
}


void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2) {
  // Write your code here
  if (root == NULL)
    return;
  if (k1 < root->data && k2 < root->data)
    elementsInRangeK1K2(root->left, k1, k2);
  else if (k1 > root->data && k2 > root->data)
    elementsInRangeK1K2(root->right, k1, k2);
  else if (k1 <= root->data && k2 >= root->data) {
    elementsInRangeK1K2(root->left, k1, k2);
    cout << root->data << " ";
    elementsInRangeK1K2(root->right, k1, k2);
  }
}

template <typename T>
class Node{
    public:
    T data;
    Node<T>*next;

    Node(T data){
        this->data = data;
       this->next = NULL;
    }
};

class LL{
    public:
    Node<int>*head;
    Node<int>*tail;

    
};

LL BstLL(BinaryTreeNode<int>* root){
         
    if(root==NULL){
        LL combined;
          combined.head=NULL;
          combined.tail=NULL;
        return combined;
    }

      Node<int>*newnode=new Node<int>(root->data);
    LL leftlist = BstLL(root->left);
    LL rightlist = BstLL(root->right);

  LL combined;
  
  if(leftlist.head==NULL && rightlist.head==NULL){
    combined.head=newnode;
    combined.tail=newnode;
  }else if(leftlist.head == NULL && rightlist.head!=NULL){
    combined.head=newnode;
    newnode->next=rightlist.head;
    combined.tail=rightlist.tail;
  }else if(leftlist.head !=NULL && rightlist.head==NULL){
    combined.head=leftlist.head;
    leftlist.tail->next=newnode;
    combined.tail=newnode;
  }else{
    combined.head=leftlist.head;
    leftlist.tail->next=newnode;
    newnode->next=rightlist.head;
    combined.tail=rightlist.tail;
    
  }
 return combined;


};

Node<int> *constructLinkedList(BinaryTreeNode<int> *root) {
  return BstLL(root).head;
}


vector<int>*SumRootToNodePath(BinaryTreeNode<int> *root,int data) {
    if(root==NULL)
     return NULL;
int sum=0;
     if(root->data == data){
      vector<int>*path=new vector<int>();
      path->push_back(root->data);
      sum+=root->data;
      return path;
     }
     
     vector<int>*leftpath=SumRootToNodePath(root->left,data);
     if(leftpath!=NULL){
      leftpath->push_back(root->data);
      sum+=root->data;
      return leftpath;
     }

     vector<int>*rightpath =SumRootToNodePath(root->right,data);
     if(rightpath!=NULL){
      rightpath->push_back(root->data);
      sum+=root->data;
      return rightpath;
     }else{
      return NULL;
     }
    
    int x=sum;
    cout<<"total"<<sum<<endl; 
}

vector<int>leftView(BinaryTreeNode<int>*root){
  vector<int>v;
  if(root==NULL){
    return v;
  }

  queue<BinaryTreeNode<int>*>q;
  q.push(root);

  while(!q.empty()){
    int level=q.size();
    BinaryTreeNode<int>*first =NULL;
    for(int i=0;i<level; i++){
      BinaryTreeNode<int>*node=q.front();
      q.pop();
      first=node;
      if(i==0){
       cout<<first->data<<" ";
      }
      if(node->left){
        q.push(node->left);
      }
      if(node->right){
        q.push(node->right);
      }
    }
  }
  return v;
}

vector<int>rightView(BinaryTreeNode<int>*root){
  vector<int>v;
  if(root==NULL){
    return v;
  }

  queue<BinaryTreeNode<int>*>q;
  q.push(root);

  while(!q.empty()){
    int level=q.size();
    BinaryTreeNode<int>*last =NULL;
    for(int i=0;i<level; i++){
      BinaryTreeNode<int>*node=q.front();
      q.pop();
      last=node;
     if(!(node->left==NULL&&node->right==NULL)){
      if(node->left){
        q.push(node->left);
      }
      if(node->right){
        q.push(node->right);
      }
    }
    } 
    cout<<last->data<<" ";
  }
  
  return v;
}

void bottomview(BinaryTreeNode<int>*root){
   if(root==NULL){
    return ;
   }

   queue<BinaryTreeNode<int>*> q;
   q.push(root);
   while(q.size()>0){
   int level=q.size();
  

   for(int i=0;i<level;i++){
    BinaryTreeNode<int>*node=q.front();
    q.pop();
 

    if(node->left==NULL&&node->right==NULL){
      cout<<node->data<<" ";
    }else{
      if(node->left){
        q.push(node->left);
      }
      if(node->right){
        q.push(node->right);
      }
    }
   }
}
}

void topView(BinaryTreeNode<int>*root){
  vector<int>ans;

  if(root==NULL){
    return ;
  }
  map<int,int>m;
  queue<pair<BinaryTreeNode<int>*,int>>q;
  q.push({root,0});

  while(!q.empty()){
    auto it = q.front();
     q.pop();

     BinaryTreeNode<int>*node = it.first;
     int line=it.second;
     if(m.find(line)==m.end()){
      m[line]=node->data;
     }

     if(node->left){
      q.push({node->left,line-1});
     }

    if(node->right){
      q.push({node->right,line+1});
    }

  }

  for(auto it : m){
  cout<<it.second<<" ";
  }
   
}

vector<int>ZigzagTraversal(BinaryTreeNode<int>* root){
    vector<int>v;
    if(root==NULL){
      return v;
    }

    deque<BinaryTreeNode<int>*>q;
    q.push_back(root);
    v.push_back(root->data);
    cout<<root->data<<" ";
    BinaryTreeNode<int>*temp;

    int level=1;

    while(!q.empty()){
       int n=q.size();


       for(int i=0; i<n; i++){
           
           //right to left
          //  if(level%2!=0){
          //     temp=q.back();
          //     q.pop_back();
          //  }     else {
          //       temp = q.front();
          //       q.pop_front();
          //   }

            if(level%2==0){
              temp=q.back();
              q.pop_back();
           }     else {
                temp = q.front();
                q.pop_front();
            }
 
            // pushing mechanism
            if (level % 2 != 0) {
 
                if (temp->right) {
                    q.push_back(temp->right);
                    v.push_back(temp->right->data);
                    cout<<temp->right->data<<" ";
                }
                if (temp->left) {
                    q.push_back(temp->left);
                    v.push_back(temp->left->data);
                    cout<<temp->left->data<<" ";
                }
            }
            else if (level % 2 == 0) {
 
                if (temp->left) {
                    q.push_front(temp->left);
                    v.push_back(temp->left->data);
                     cout<<temp->left->data<<" ";
                }
                if (temp->right) {
                    q.push_front(temp->right);
                    v.push_back(temp->right->data);
                     cout<<temp->right->data<<" ";
                }
            }
        }
        level++; // level plus one
    }
    return v;
       
}


void printleftboundary(BinaryTreeNode<int>*root){
   while(!root)
   { return ;}

   root=root->left;
   while(root){
    if(root->left||root->right){
      cout<<root->data<<" ";
    }
    if(root->left){
      root=root->left;
    }else{
      root=root->right;
    }
   }
}

void printrightboundary(BinaryTreeNode<int>*root){
  if(!root){
    return ;
  }

root=root->right;
  while(root!=NULL){
   if(root->left||root->right){
      cout<<root->data<<" ";
    }
    if(root->right){
       root=root->right;
    }else{
      root=root->left;
    }
  }

}

void printLeaves(BinaryTreeNode<int>*root){
  if(!root){
    return ;
  }
   printLeaves(root->left);
    if (!root->left && !root->right) {
        cout << root->data << " ";
    }
    printLeaves(root->right);
}
void boundary(BinaryTreeNode<int>*root){
  
  if(root ==NULL){
    return;
  }
  cout<<root->data<<" ";
 printleftboundary(root);
 printLeaves(root->left);
 printLeaves(root->right);
 printrightboundary(root);



}

int main() {

  BinaryTreeNode<int>*root=input();
  // vector<int>*ans=SumRootToNodePath(root,5);
  // for(int i=0;i<ans->size();i++){
  //   cout<<ans->at(i)<<endl;
  // }
//   // delete ans;

// boundary(root);
topView(root);

}









