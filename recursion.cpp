#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;


int mx(int arr[],int n){

if(n==0){
    return arr[0];
}

int maxx=mx(arr,n-1);
if(maxx>arr[n-1]){
    return maxx;
}else
return arr[n-1];

}

int last(int *arr,int id,int n,int x){
    if(id==n){
        return -1;
    }

    int lid=last(arr,id+1,n,x);
    if(lid==-1){
        if(arr[id]==x){
            return id;
        }else{
          return   -1;
        }
    }else{
        return lid;
    }
}

vector<int> all(int *arr,int id,int n,int x){
vector<int>v;
    if(id==n){
        return v ;
    }
    
    if(arr[id]==x){
     v.push_back(id);
    }
      vector<int>v1= all(arr,id+1,n,x);
      v.insert(v.end(),v1.begin(),v1.end());

}


int allid(vector<int>v,int n,int x,vector<int>&op){
        
        if(n==0){
            return 0;
        }
        int idx=allid(v,n-1,x,op);
        if(v[n-1]==x){
            op.push_back(n-1);
            return idx+1;
        }else{
            return idx;
        }
  
}

void allsubset(vector<int>ns,vector<int>op,int idx,vector<vector<int> >&ans){
   if(idx==ns.size()){
    ans.push_back(op);
      return;
   }   

   allsubset(ns,op,idx+1,ans);
   op.push_back(ns[idx]);
   allsubset(ns,op,idx+1,ans);


}

int search(vector<int>v,int x,int low,int high){
    if(low>high){
        return -1;
    }

    int mid=low+(high-low)/2;
    if(v[mid]==x){
        return mid;
    }
    if(v[mid]>x){
        return (v,x,low,mid-1);
    }else{
        return (v,x,mid+1,high);
    }

}


int digitSum(int n){
    if(n/10==0){
        return n%10;
    }
    return n%10+digitSum(n/10);
} 


class rev{
    public:
    long long sum=0;
    void reverse(long long n ){
        if(n==0){
            return;
        }
        int rem=n%10;
        sum=sum*10+rem;
        reverse(n/10);
    }
};

int revr(int n, int sum) {
    if (n == 0) {
        return sum;
    }

    int rem = n % 10;
    sum = sum * 10 + rem;
    return revr(n / 10, sum);
}

bool pal(int n ){
     return (n==revr(n,0));
}
int help(int n,int x){
     if(n==0){
        return x;
    }
    int rem=n % 10;
   if(rem==0){
     return help(n/10,x+1);
   }else{
    return help(n/10,x);
   }
}
int zero(int n) {
 
   return help(n,0);
}

int zero1(int n){
  if(n==0){
    return 0;
  }
  int x=zero(n/10);
  if(n%10==0){
    x++;
  }
  return x;
}


int help1(int n,int x){
   if(n==0){
    return x;
   }

   if(n%2==0){
    return help1(n/2,x+1);
   }
   if(n%2==1){
    return help1(n-1,x+1);
   }
    

}

int redtoZeros(int n){
    return help1(n,0);
}

bool sorted(vector<int>& v,int i){
    if(i==v.size()){
        return true;
    }

    return (v[i+1]>=v[i])&&sorted(v,i+1);
}

int linear(vector<int>&v,int i,int x){
    if(i==v.size()){
        return -1;
    }
    if(v[i]==x){
        return i;
    }
    return linear(v,i+1,x);
}

int rotBinary(vector<int>&v,int target,int lo ,int hi){
    if(lo>hi){
        return -1;
    }
    int mid=lo+(hi-lo)/2;
    if(v[mid]==target){
        return mid;
    }
    if(v[lo]<=v[mid]){
        if(v[lo]<=target&&v[mid]>=target){
         return   rotBinary(v,target,lo,mid-1);
        }else{
          return    rotBinary(v,target,mid+1,hi);
        }
    }else{
        if(v[mid]<=target&& v[hi]>=target){
         return     rotBinary(v,target,mid+1,hi);
        }else{
         return     rotBinary(v,target,lo,mid-1);
        }
    }
}

void pattern(int r,int c){
    if(r==0){
        return;
    }

    if(r>c){
        cout<<"*"<<" ";
        pattern(r,c+1);
    }else{
        cout<<endl;
        pattern(r-1,0);
    }
}

void pattern2(int r,int c){
    if(r==0){
        return;
    }

    if(r>c){ 
        pattern2(r,c+1);
        cout<<"*"<<" ";
    }else{
        pattern2(r-1,0);
        cout<<endl;
    }


}


void allSubarray(vector<int>v,int i,int j,int n){
if(i==n||j==n){
    return;
}   

for(int it=i;it<=j;it++){
    cout<<v[it]<<" ";
}
cout<<endl;
if(j==n-1)
    allSubarray(v,i+1,i+1,n);
else
  allSubarray(v,i,j+1,n);

}

void skip(string s,char x,int i,string&st){
    
    if(i==s.length()){
        return ;
    }

    if(s[i]!=x){
      st+=s[i];
      
    }
     skip(s,x,i+1,st);

}

void ptr(int n,vector<int>&v){
    if(n<=0){
        v.push_back(n);
        return ;
    }
    v.push_back(n);
    ptr(n-5,v);
    v.push_back(n);
}

vector<int>ptrn(int n){
vector<int>v;
ptr(n,v);
return v;
}


void substrhelp(string s,int i,int j,vector<string>&v){
  if(i==s.length()){
    return ;
  }

  if(j<s.length()){
   v.push_back(s.substr(i,j+1));
    substrhelp(s,i,j+1,v);
  }else{
    substrhelp(s,i+1,i+1,v);
  }
    
}

vector<string>substr(string s){
    vector<string>v;
    substrhelp(s,0,0,v);
    return v;
}

vector<string> subseqhelp(string s){
     if(s.length()==0){
        vector<string>v={""};
         return v; 
     }
       
       char ch =s[0];
        string str =s.substr(1);
       vector<string>res= subseqhelp(str);

       vector<string>myres;
       for(string i:res){
        myres.push_back(ch+i);
        myres.push_back(""+i);
       }
        return myres;
    }


    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0){
            vector<int>v={};
            vector<vector<int>>v1;
            v1.push_back(v);
            return v1;
        }

        int x=nums[0];
         vector<int>str(nums.begin()+1,nums.end());
         vector<vector<int>>s=permute(str);

         vector<vector<int>>res;
         for(vector<int> i:s){
             res.push_back(i);
             i.push_back(x);
             res.push_back(i);
         }
         return res;
    }



int cnt(int n,vector<int>&v,int x) {
    if (n == 0) {
        v.push_back(x);
        return 1;
    }
     else if (n < 0) {
        return 0;
    }

    return cnt(n - 3,v,x+1) + cnt(n - 10,v,x+1)+cnt(n - 11,v,x+1) ;
}


int maze(int n,int m ,int i,int j){
    if(j==m&&i==n) {
        return 1;
    }
    if(i>n||j>m) {
        return 0;
    }

  return  maze(n,m,i+1,j)+maze(n,m,i,j+1);
}

vector<string>getpaths(int n,int m ,int i,int j ){
    if(j==m&&i==n) {
        vector<string>v={""};
        return v;
    }
     vector<string>hpath;
     vector<string>vpath;
    if(i<n)
    hpath=getpaths(n,m,i+1,j);
    if(j<m)
    vpath=getpaths(n,m,i,j+1);

    vector<string>paths;

    for(string hp:hpath){
        paths.push_back("h"+hp);
    }
    for(string vp:vpath){
        paths.push_back("v"+vp);
    }

    return paths;
}


int stair(int n,vector<int>&v,int x) {
    if (n == 0) {
        v.push_back(x);
        return 1;
    }
     else if (n < 0) {
        return 0;
    }

    return cnt(n - 1,v,x+1) + cnt(n - 2,v,x+1) ;
}

vector<string>stairpaths(int n){
    if(n==0){
        vector<string>s={""};
        return s;
    }
    if(n<0){
        vector<string>s={};
        return s;
    }

    vector<string>cn1=stairpaths(n-1);
    vector<string>cn2 =stairpaths(n-2);
    vector<string>steps;

    for(string cnt1:cn1){
        steps.push_back("1"+cnt1);
    }
    for(string cnt2: cn2){
        steps.push_back("2"+cnt2);
    }
return steps;
}





vector<string> allpath(int n, int m, int i, int j) {
    if (i == n && j == m) {
        vector<string> v = {""};
        return v;
    }

    vector<string> paths;
    // horizontal
    for (int h = 1; h <= n - i; h++) {
        vector<string> hpath = allpath(n, m, i + h, j);
        for (string hr : hpath) {
            paths.push_back("h" + to_string(h) + hr);
        }
    }

    // vertical
    for (int v = 1; v <=m - j; v++) {
        vector<string> vpath = allpath(n, m, i, j + v);
        for (string vr : vpath) {
            paths.push_back("v" + to_string(v) + vr);
        }
    }

    // diagonal
    for (int d = 1; d <= n - i && d <= m - j; d++) {
        vector<string> dpath = allpath(n, m, i + d, j + d);
        for (string dr : dpath) {
            paths.push_back("d" + to_string(d) + dr);
        }
    }

    return paths;
}




vector<string>allfour(int n ,int m ,int a ,int b,int i ,int j){
   if(i==n&&j==m){
    vector<string>v={""};
    return v;
   }
   if(a==i&&b==j){
     vector<string>v={""};
    return v;
   }

     vector<string>lpath;
     vector<string>rpath;
     vector<string>upath;
     vector<string>dpath;
  
    if(i>a){
     lpath=allfour(n,m,a,b,i-1,j);
    }
if(j>b){
     upath=allfour(n,m,a,b,i,j-1);
    }
if(n>i){
     rpath=allfour(n,m,a,b,i+1,j);
    }
if(m>j){
     dpath=allfour(n,m,a,b,i,j+1);
    }

vector<string>path;

for(string l:lpath){
    path.push_back("l"+l);
}
for(string r:rpath){
    path.push_back("r"+r);
}
for(string u:upath){
    path.push_back("u"+u);
}
for(string d:dpath){
    path.push_back("d"+d);
}
   return path;
}


vector<string>s(int n , int o ,int c){
    if( o==n && c==n){
        vector<string>v={""};
        return v;
    }
vector<string>open;
vector<string>close;

    if(o<n){
      open=s(n,o+1,c);   
    }
    if(o>c){
      close=s(n,o,c+1);
    }
vector<string>all;
for(string i : open){
    all.push_back("("+i);
}
for(string i :close){
    all.push_back(")"+i);
}

return all;
}


void printsubseq(string s,string ans){
     if(s.length()==0){
        cout<<ans<<endl;
         return ;
     }
       
       char ch =s[0];
        string str =s.substr(1);
         printsubseq(str,ans+ch);
         printsubseq(str,ans+"");

        
    }

void printStair(int n,string ans){
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    if(n<0){
        return;
    }
    
    printStair(n-1,"1"+ans);
    printStair(n-2,"2"+ans);
    printStair(n-3,"3"+ans);
}

void printMaze(int n,int m,int i,int j,string s){
    if(i==n&&j==m){
        cout<<s<<endl;
       return;
    }
    if(i>n||j>m){
        return;
    }
    printMaze(n,m,i+1,j,s+"h");
    printMaze(n,m,i,j+1,s+"v");

}

void printMazeJumps(int n,int m,int i,int j,string s){
    if(i>n||j>m){
        return;
    }
    if(i==n&&j==m){
        cout<<s<<endl;
        return;
    }

    for(int h=1; h<=n-i; h++){
        printMazeJumps(n,m,i+h,j,s+"h"+to_string(h));
    }
    for(int v=1;v<=m-j; v++){
        printMazeJumps(n,m,i,j+v,s+"v"+to_string(v));
    }
    for(int d=1; d<=n-i&&d<=m-j; d++){
        printMazeJumps(n,m,i+d,j+d,s+"d"+to_string(d));
    }
}

int partition(int n, int m){
    if(n==0){
        return 1;
    }
    if(m==0){
        return 0; 
    }
    return partition(n-1,m)+partition(n,m-1);
}

void printpermutation(string s,string st){
    if(s.length()==0){
        cout<<st<<endl;
        return;
    }
  for(int i=0; i<s.length(); i++){
    char ch =s[i];
    string s_left=s.substr(0,i);
    string s_right=s.substr(i+1);
    string str=s_left+s_right;
    printpermutation(str,st+ch);
  }
}


vector<string> keypad(vector<string>& codes, string s) {
    if (s.length() == 0) {
        vector<string> v;
        v.push_back("");
        return v;
    }

    char ch = s[0];
    string ros = s.substr(1);

    vector<string> rres = keypad(codes, ros);
    vector<string> mres;

    string codeforch = codes[ch - '0']; // Convert char to int
    for (int i = 0; i < codeforch.length(); i++) {
        char chcode = codeforch[i];
        for (string it : rres) {
            mres.push_back(chcode + it);
        }
    }
    return mres;
}


vector<vector<int>>combination(vector<int>&v,int i,int sum,vector<int>&temp){
    if(sum==0){

    }
}

int main() {
//   vector<int>v={1,2,3,4,5,6,7,8,21};
//    cout<<search(v,4,0,v.size()-1);
//    int n=v.size();
//    vector<int>op;
//    int x=allid(v,n,2,op);

//    for(int i=0;i<x;i++){
//     cout<<op[i]<<" ";
//    }

// rev r;
// r.reverse(126734);
// cout<<r.sum<<endl;

// cout<<pal(121)<<" "<<pal(123)<<endl;
// cout<<zero1(10100)<<endl;
// cout<<redtoZeros(64)<<endl;

// cout<<sorted(v,0)<<endl;
// cout<<linear(v,0,6)<<endl;
// cout<<rotBinary(v,21,0,v.size()-1)<<endl;
// pattern(4,0);
// allSubarray(v,0,0,v.size());
// string s="";
// skip("absbbs",'a',0,s);
// cout<<s<<endl;
// pattern2(5,0);
// vector<int>v1=ptrn(16);
// for(int i=0;i<v1.size();i++){
//     cout<<v1[i]<<endl;
// }

// vector<string>s=substr("mansi");
// for(int i=0;i<s.size();i++){
//     cout<<s[i]<<endl;
// }

// vector<string>s=subseqhelp("abc");
// for(int i=0;i<s.size();i++){
//     cout<<s[i]<<endl;
// }

// vector<int>v;
// cout<<cnt(74,v,0)<<endl;
// // for(int i=0;i<v.size();i++){
// //     cout<<v[i]<<endl;
// // }
// cout<<*max_element(v.begin(),v.end())<<endl;

// vector<string>s=getpaths(3,3,1,1);
// for(int i=0;i<s.size();i++){
//     cout<<s[i]<<endl;
// }
    
//     vector<string>st=allfour(3,4,0,0,2,1);
//     for(int i=0;i<st.size();i++){
//     cout<<st[i]<<endl;
// }
// string h="";
// printsubseq("abc",h);

// vector<string>s=allpath(3,3,1,1);
// for(int i=0;i<s.size();i++){
//     cout<<s[i]<<endl;
// }

// printStair(4,"");
// string s="";
// printMazeJumps(3,3,1,1,s);
// int x=partition(2,2);
// cout<<x;
// printpermutation("abcde","");
// vector<string>codes={".,","abc","def","ghi","jkl","mno","pqrs","tu","vw","xyz"};
// vector<string>v=keypad(codes,"                                             zz                                                                                                                    vcaS56");
// for(string i:v){
//     cout<<i<<endl;
// }
    return 0;
}





