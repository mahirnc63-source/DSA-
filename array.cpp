#include <bits/stdc++.h>
using namespace std;
int largest(int arr[],int n){
    int large=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>large){
            large=arr[i];
        }
    }
    return large;
}
int secondlargest(int arr[],int n){
    int large=arr[0];
    int slarge=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>large){
            slarge=large;
            large=arr[i];
        }
        else if(arr[i]<large&&arr[i]>slarge){
            slarge=arr[i];
        }
    }
    return slarge;

}
int issorted(int arr[],int n){
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){

        }
        else{
            return 0;
        }
    }
    return 1;
}
void rotateleft1(vector<int>& arr,int k,int n){
    k=k%n;
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i]=arr[i];
    }
    
    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }
    for(int i=0;i<k;i++){
        arr[n-k+i]=temp[i];
    }
}
void rotateleft2(vector<int>& arr,int k,int n){
    k=k%n;
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.begin()+n);
    reverse(arr.begin(),arr.begin()+n);
}
void rightrotate(vector<int>& arr,int n,int k){
    k=k%n;
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i]=arr[n-k+i];

    }
    for(int i=n-1;i>=k;i--){
        arr[i]=arr[i-k];
    }
    for(int i=0;i<k;i++){
        arr[i]=temp[i];
    }

}
void rightrotate2(vector<int>& arr,int n,int k){
    k=k%n;
    
    reverse(arr.begin()+(n-k),arr.begin()+n);
    reverse(arr.begin(),arr.begin()+(n-k));
    reverse(arr.begin(),arr.begin()+n);

}
void movezero(vector<int>& a,int n){
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            temp.push_back(a[i]);
        }
    }
    int nz=temp.size();
    for(int i=0;i<nz;i++){
        a[i]=temp[i];
    }
    for(int i=nz;i<n;i++){
        a[i]=0;
    }
}
vector<int> movezero2(vector<int>& a,int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1) return a;
    for(int i=j+1;i<n;i++){
        if(a[i]!=0){
            swap(a[i],a[j]);
            j++;

        }
    }
    return a;
}
vector<int> findunion(vector<int> a,vector<int> b){
    int n1=a.size();
    int n2=b.size();
    set<int> st;
    for(int i=0;i<n1;i++){
        st.insert(a[i]);
    }
    for(int j=0;j<n2;j++){
        st.insert(b[j]);
    }
    vector<int> temp;
    for(auto x:st){
        temp.push_back(x);
    }
    return temp;
}
int main(){
    /*int arr[6]={2,3,6,8,4,9};;
    int n=sizeof(arr) / sizeof(arr[0]);
    int a=issorted(arr,n);
    cout<<"slargest="<<a;*/
    vector<int> a={1,0,2,0,0,3,4,5};
    vector<int> b={1,2,2,3,4,5,6};
    int k=8;
    //int n=a.size();
    vector<int> un=findunion(a,b);
    for(int x:un){
        cout<<x<<" ";
    }

    return 0;
}