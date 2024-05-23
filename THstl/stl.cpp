#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<set>
#include<unordered_set>
#include<map>
using namespace std;

void Explainpair(){
    pair<int,int> p= {1,3};
    cout<<p.first<<" "<<p.second<<endl;

    pair<int,pair<int,int>> q= {1,{3,4}};
    cout<<q.first<<" "<<q.second.second<<endl;

    pair<int,int> arr[]= {{1,2},{3,4},{5,6}};
    cout<<arr[1].first<<" "<<arr[2].second<<endl;
}


void Explainvector(){
    vector <int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector <pair<int,int>> vec;
    vec.push_back({1,2});
    //emplaceback assumes them to be a pair 
    vec.emplace_back(1,2);

    vector<int> v(5,100); //{100,100,100,100,100}
    vector<int> v(5);
    vector<int> v1(5,20);
    vector<int> v2(v1); 
    
    cout<<v[1]<<endl;
    cout<<v.back(); //prints last element

    //accessing the members in a vector
    vector<int>::iterator it=v.begin();  //it points to the memory of v elements
    it++;
    cout<<*(it)<<" ";

    it+=2;
    cout<<*(it)<<" ";

    vector<int>::iterator it=v.end(); //end points to one space after the last element

    //loops using iterator
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*(it);
    }
    for(auto it=v.begin();it!=v.end(); it++){
        cout<<*(it);
    }
    
    for(auto it:v){
        cout<<it;
    }

    //deletion in a vector
    v.erase(v.begin()+1);
    v.erase(v.begin()+2,v.begin()+4); //deletes from [start,end)

    //insertion in a vector
    vector<int> v(2,100);  //{100,100,100}
    v.insert(v.begin(),200);  //{200,100,100,100}
    v.insert(v.begin()+1,2,10);  //{200,10,10,100,100,100}

    vector<int> copy(2,50);
    v.insert(v.begin(),copy.begin(),copy.end()); //{50,50,200,10,10,100,100}

    cout<<v.size();
    v.pop_back();
    v1.swap(v2);
    v.clear();
    cout<<v.empty();
}

void Explainlist(){
    //same as a vector but can access from both sides(ie double linked list)
    list <int> ls;
    ls.push_back(2);
    ls.emplace_back(4);
    ls.push_front(5);
    ls.emplace_front(8);
}

void ExplainDeque(){
    //exactly same as list and vector
    deque <int> dq;
}

void ExplainStack(){
    //LIFO , cant be viewed as st[2]..etc
    stack <int> st,st1,st2;
    st.push(1);
    st.push(2);
    st.push(4);
    st.push(6);
    st.pop();
    st.top();
    st.size();
    st.empty();
    st1.swap(st2);
}

void ExplainQueue(){
    //FIFO
    queue<int> q;
    q.push(1);
    q.push(4);
    q.push(5);
    q.back();
    q.front();
    q.pop(); //first element pops out
}

void ExplainSet(){
    //stores in a ordered manner, no duplicates
    set <int> st;
    st.insert(1);
    st.insert(2);
    st.insert(4);
    st.insert(3);   //{1,2,3,4}
    set<int>::iterator it,it1,it2=st.begin();
    auto it = st.find(5);
    st.erase(it);
    st.count(1);
    auto it1=st.find(2);
    auto it1=st.find(4);
    st.erase(it1,it2);
    auto it= st.lower_bound(2);
}

void ExplainMultiset(){
    //everything is same as set
    //only stores duplicate elements also
    multiset <int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.erase(1);  //erases all the 1s
    int cnt= ms.count(1);
    ms.erase(ms.find(1));
    ms.erase(ms.find(1), ms.find(2));
}

void ExplainUnorderedset(){
    //same as set but not sorted ordered
    unordered_set <int> st;
    //all operations work except lower_bound or upperbound

}

void ExplainMap(){
    //stores unique keys in sorted order
    map <int,int> mpp;  //{key,value}
    map<int, pair<int,int>> mpp;
    mpp[1]=2; //1 is the key and 2 is the value
    mpp.emplace(3,1);
    mpp.insert({2,4});
    mpp[2,3]=10;

    for(auto it:mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<mpp[1];
    cout<<mpp[5]; //null
    
    map <int,int>::iterator it=mpp.begin();
    it++;
    auto it = mpp.find(5);

    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(3);
}

void ExplainMulitmap(){
    //same as map but stores multiple keys
    //only mpp[key] cannot be used here
}
void ExplainUnorderedmap(){
    //same as set and unordered set difference
}


//algorithms using stl
//analyse any two given pairs
bool comp(pair<int,int> p1, pair<int,int> p2){
    if (p1.second<p2.second) return true;
    else if (p1.second>p2.second) return false;
    else if(p1.first>p2.first) return true;
    return false;
}
void Extra(){
    int a,n;
    //sort(a,a+n);
    vector<int> v;
    //sort(v.begin(),v.end());
    pair<int,int> a[]={{1,2},{2,1},{4,1}};
    //sort in acc to second elem
    //sort(a,a+n,greater<int>);

    int num=7;
    int cnt= __builtin_popcount(num);
}
