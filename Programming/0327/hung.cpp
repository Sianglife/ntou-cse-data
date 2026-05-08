#include<bits/stdc++.h>
using namespace std;

class Number{
    private:
        int number;
    public:
        Number(int n){number=n;}
        int getNumber(){return number;}
        shared_ptr<Number> next;
        shared_ptr<Number> previous;
};

void readInput(vector<int> &v){
    string s;
    getline(cin,s);
    stringstream ss(s);

    int num;
    while(ss>>num){
        v.push_back(num);
    }
}

shared_ptr<Number> head;
shared_ptr<Number> tail;

void makeDLL(vector<int> &v){
    head=nullptr;
    tail=nullptr;

    for(int i=0;i<v.size();i++){
        shared_ptr<Number> node=make_shared<Number>(v[i]);

        if(head==nullptr){
            head=node;
            tail=node;
        }
        else{
            tail->next=node;
            node->previous=tail;
            tail=node;
        }
    }
}

void PrintDLLNumber(){ 
    shared_ptr<Number> cur=head;

    while(cur){
        cout<<cur->getNumber();
        if(cur->next) cout<<" ";
        cur=cur->next;
    }
    cout<<"\n";
}

void SortDLL(){
    if(!head || !head->next) return;

    shared_ptr<Number> cur=head->next;

    while(cur){
        shared_ptr<Number> nextjudge=cur->next;
        int value=cur->getNumber();
        shared_ptr<Number> pos=cur->previous;
        
        while(pos && pos->getNumber()>value){
            pos=pos->previous;
        }
        

        if(pos==cur->previous){
            cur=nextjudge;
            continue;
        }

        if(cur->next) cur->next->previous=cur->previous;
        else tail=cur->previous;
        
        cur->previous->next=cur->next;

        if(pos==nullptr){
            cur->next=head;
            cur->previous=nullptr;

            head->previous=cur;
            head=cur;
        }
        else{
            pos=pos->next;

            cur->next=pos;
            cur->previous=pos->previous;

            pos->previous->next=cur;
            pos->previous=cur;
        }
        
        

        cur=nextjudge;
    }
}

int main(){
    vector<int> tbl;
    readInput(tbl);
    
    if(tbl.size()==0){
        cout<<"\n";
        return 0;
    }

    makeDLL(tbl);
    SortDLL();
    PrintDLLNumber();
}