#include <bits/stdc++.h>
using namespace std;

class priorityq{
    public:
    vector<int>pq;

    priorityq(){

    }

   bool isEmpty(){
        return pq.size() == 0;
    }

    int size(){
        return pq.size();
    }
  
void insert(int x){
    pq.push_back(x);

    int childIdx = pq.size() - 1;
    while(childIdx > 0){
    int parentIdx = (childIdx -1)/2;

    if(pq[childIdx]<pq[parentIdx]){
        swap(pq[childIdx], pq[parentIdx]);
    }else{
        break;
    }
    childIdx = parentIdx;
    }
  }  

void print(){
    for(int i=0; i<pq.size(); i++){
        cout<<pq[i]<<" ";
    }
    cout<<endl;
}

  int removeMin(){
    if(isEmpty()){
        return INT32_MIN;
    }
    int ans=pq[0];
    pq[0]=pq[pq.size()-1];
    pq.pop_back();
    cout<<"before : ";
 print();
    int parentIdx = 0;
    int leftIndex=2*parentIdx+1;
    int rightIndex=2*parentIdx+2;

    while(leftIndex<pq.size()){
        int minIndex=parentIdx;

        if (pq[parentIdx]>pq[leftIndex]){
            minIndex=leftIndex;
    }
        if(rightIndex<pq.size()&&pq[rightIndex]<pq[minIndex]){
           minIndex=rightIndex;
        }
if(minIndex==parentIdx){
    break;
}
        swap(pq[minIndex],pq[parentIdx]);

        parentIdx=minIndex;
        leftIndex=2*parentIdx+1;
        rightIndex=2*parentIdx+2;
  } 
  return ans;

  }
  




  int removeMax(){
    if(isEmpty()){
        return 0;
    }
    int ans=pq[0];
    pq[0]=pq[pq.size()-1];
    pq.pop_back();

    int parentIdx = 0;
    int leftIndex=2*parentIdx+1;
    int rightIndex=2*parentIdx+2;

    while(leftIndex<pq.size()){
        int maxIndex=parentIdx;
        if (pq[parentIdx]<pq[leftIndex]){
            maxIndex=leftIndex;
    }
        if(rightIndex<pq.size()&&pq[rightIndex]>pq[maxIndex]){
           maxIndex=rightIndex;
        }
if(maxIndex==parentIdx){
    break;
}
        swap(pq[maxIndex],pq[parentIdx]);

        parentIdx=maxIndex;
        leftIndex=2*parentIdx+1;
        rightIndex=2*parentIdx+2;
  } 
  }
  
  

//inplace heap sort

void heapSort(int*arr,int n){
         for(int i=1; i<n; i++) {

            int childIndex=i;

            while(childIndex>0){
                int parentIndex=(childIndex-1)/2;

                if(arr[childIndex]<arr[parentIndex]){
                    swap(arr[childIndex],arr[parentIndex]);
                }else{
                    break;
                }
                childIndex=parentIndex;
            }
         }

         //remove elements
          int size =n;
         swap(pq[0],pq[size-1]);
         size--;

         int parentIndex = 0;
    int leftIndex=2*parentIndex+1;
    int rightIndex=2*parentIndex+2;

           while(leftIndex<size){
        int minIndex=parentIndex;

        if (pq[parentIndex]>pq[leftIndex]){
            minIndex=leftIndex;
    }
        if(rightIndex<pq.size()&&pq[rightIndex]<pq[minIndex]){
           minIndex=rightIndex;
        }
if(minIndex==parentIndex){
    break;
}
        swap(pq[minIndex],pq[parentIndex]);
        parentIndex=minIndex;
        leftIndex=2*parentIndex+1;
        rightIndex=2*parentIndex+2;
    }
}



};


 void kSorted(int arr[] ,int n ,int k ){
    priority_queue<int>pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }

     int j=0;
    for(int i=k; i<n; i++){
        arr[j]=pq.top();
        pq.pop();
        j++;
        pq.push(arr[i]);
      
    }
  

    while (!pq.empty())
    {
        arr[j]=pq.top();
        pq.pop();
        j++;
       
    }
    
 }


 void median(vector<int>&arr,int n){
    priority_queue<int>maxH;
    priority_queue<int, vector<int>,greater<int> >minH;
  

  for(int i=0; i<n; i++){
      if(i==0){
        maxH.push(arr[i]);
        cout<<arr[i]<<" ";
      }
        else{
    if(arr[i]<maxH.top()){
    maxH.push(arr[i]);
}else{
    minH.push(arr[i]);
}

  

  if(maxH.size()-minH.size()>1){
    minH.push(maxH.top());
    maxH.pop();
  }
   if(maxH.size()-minH.size()>-11){
    maxH.push(minH.top());
    minH.pop();
  }

   int size=maxH.size()+minH.size();
   if(size%2!=0){
      if(maxH.size()>minH.size()){
        cout<<maxH.top()<<" ";
      }else{
         cout<<minH.top()<<" ";
      }
   }else{
    cout<<(minH.top()+maxH.top())/2<<" ";
   }
        }} 
 }

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

vector<int>v={12,15,7,2,9};
// kSorted(input,5,3);
// for(int i=0; i<5; i++){
//     cout<<input[i]<<" ";
// }

median(v,5);
    return 0;
}