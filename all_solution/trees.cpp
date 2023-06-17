#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Treenode
{
public:
    T data;
    vector<Treenode<T> *> children;

    Treenode(int data)
    {
        this->data = data;
    }
};

Treenode<int> *input()
{
    int data;
    cout << "Enter root : ";
    cin >> data;
    Treenode<int> *root = new Treenode<int>(data);

    int n;
    cout << "enter child of " << data << endl;
    cin >> n; // no of chilren of root
    for (int i = 0; i < n; i++)
    {
        Treenode<int> *child = input();
        root->children.push_back(child);
    }
    return root;
}

void print(Treenode<int> *root)
{
    cout << root->data << " ";
    ;
    for (int i = 0; i < root->children.size(); i++)
    {
        print(root->children[i]);
    }
}

void print1(Treenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    int n = root->children.size();
    cout << root->data << " : ";
    for (int i = 0; i < n; i++)
    {
        cout << root->children[i]->data << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        print1(root->children[i]);
    }
}

Treenode<int> *lvlinput()
{
    int data;
    cout << "enter root : ";
    cin >> data;

    Treenode<int> *root = new Treenode<int>(data);

    queue<Treenode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        Treenode<int> *front = q.front();
        q.pop();

        cout << "enter number child of" << front->data << endl;
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild; i++)
        {
            int childdata;
            cout << "enter " << i+1 << "th child of " << front->data << endl;
            cin >> childdata;
            Treenode<int> *child = new Treenode<int>(childdata);
            front->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

void lvlprint(Treenode<int> *root)
{

    queue<Treenode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        Treenode<int> *front = q.front();
        q.pop();
        cout << front->data <<": ";

        for (int i = 0; i < front->children.size(); i++)
        {
            if (i < front->children.size() - 1)
                cout << front->children[i]->data << ", ";
            else
            {
                cout << front->children[i]->data;
            }
            q.push(front->children[i]);
        }
        cout << endl;
    }
}

int nodes(Treenode<int> *root){
    // if(root==NULL) return 0;
int ans=1;
    for(int i=0; i<root->children.size(); i++){
        ans+=nodes(root->children[i]);
    }
    return ans;
}

int sum_ofnodes(Treenode<int> *root){
    int sum =root->data;
    for(int i=0; i<root->children.size(); i++){
        sum+=sum_ofnodes(root->children[i]);
    }
    return sum;
}


int max_node(Treenode<int>*root){
    int max=root->data;
    for(int i=0; i<root->children.size(); i++){
        if(root->children[i]->data>max){
            max=root->children[i]->data;
        }
    }
}

int findMax(Treenode<int>* root) {
    if (root == nullptr) {
        
        return INT_MIN;
    }

    int maxVal = root->data; 

    // for (Treenode<int>* child : root->children) {
    //     int childMax = findMax(child); 
    //     if (childMax > maxVal) {
    //         maxVal = childMax;
    //     }
    // }

    for(int i=0; i<root->children.size(); i++){
        int childMax=findMax(root->children[i]);
         if (childMax > maxVal) {
            maxVal = childMax;
        }
    }

    return maxVal; 
}

int height(Treenode<int>* root) {
    if(root ==NULL){
        return 0;
    }
    int h=0;
    for(int i=0; i<root->children.size(); i++){
       int h1=height(root->children[i]);
       if(h1>h){
        h=h1;      
       }
    }
    return h+1;
}

void printk(Treenode<int>* root,int k) {
  if(k==0){
    cout<<root->data<<" ";
  }

  for(int i=0; i<root->children.size(); i++){
    printk(root->children[i],k-1);
  }
}

int countleaf(Treenode<int>*root){
    int count=0;
    if(root->children.size()==0){
        count++;
    }
    for(int i=0; i<root->children.size(); i++){
      count+= countleaf(root->children[i]);
    }

    return count;
}

void PostOrder(Treenode<int> *root) {
  
  if (root == NULL) {
    return;
  }

  for (int i = 0; i < root->children.size(); i++) {
   PostOrder(root->children[i]);
  }

  cout << root->data << " ";
}

void PreOrder(Treenode<int> *root) {
  
  if (root == NULL) {
    return;
  }
cout << root->data << " ";
  for (int i = 0; i < root->children.size(); i++) {
   PreOrder(root->children[i]);
  }
}

  bool find(Treenode<int> *root,int x){
    if (root == NULL) {
        return false;
    }

    for (int i = 0; i < root->children.size(); i++){
      bool val= find(root->children[i],x);
      if(val==true) {
        return true;
      }
    }
 if(root->data==x){
    return true;
 }else{
    return false;
 }
  
  }

int  greaterx(Treenode<int> *root,int x){
    if (root == NULL) {
        return 0;
    }
int count=0;
 
    for (int i = 0; i < root->children.size(); i++){
    count+= greaterx(root->children[i],x);
     }

    if((root->data)>x) {
       count++;
      }
    return count;
  
  }
  
bool indentical(Treenode<int> *root1,Treenode<int>*root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    if((root1==NULL&&root2!=NULL)||(root1!=NULL&&root2==NULL)){
        return false;
    }
    
    if((root1->data!=root2->data)||(root1->children.size()!=root2->children.size())){
        return false;
    }
bool flag = true;
    for(int i=0; i<root1->children.size(); i++){
           flag =indentical(root1->children[i],root2->children[i]);
           if(!flag){
            return false;
           }
    }

    if(root1->data==root2->data){
        return true;
    }else{
        return false;
    }
}



void depthreplace(Treenode<int>* root,int depth){
   root->data = depth;
    for (int i = 0; i < root->children.size(); i++)
    depthreplace(root->children[i], depth + 1);
}
void replaceDepthValue(Treenode<int> *root) {
  // Write your code here
  if (root == NULL)
    return;
  int depth = 0;
  depthreplace(root, depth);
}




int main()
{
    Treenode<int> *root = lvlinput();
    // Treenode<int> *root2 = lvlinput();
    // lvlprint(root);
    // int numnodes = nodes(root);
    // cout<<"numnodes: "<<numnodes<<endl;
    // int x=findMax(root);
    // cout<<"max : "<<x<<endl;
    // int h=height(root);
    // cout<<"height : "<<h<<endl;
    // printk(root,3);
    // int leaf=countleaf(root);
    // cout<<"leaf : "<<leaf<<endl;
    // PostOrder(root);
    // cout<<endl;
    // PreOrder(root);
    //   cout<<endl;
    // bool b=find(root,3);
    // cout<<"found status : "<<b<<endl;
    // int k=greaterx(root ,2);
    // cout<<"greater than 2 : "<<k<<endl;
    // bool id= indentical(root1 ,root2);
    // cout<<"identical or not : "<<id<<endl;
    replaceDepthValue(root);
    lvlprint(root);
}
