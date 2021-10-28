#include <iostream>
#include <list>
#include <vector>
#include <fstream>
using namespace std;
void dna_1(int s,int e,list <char> &dna) {
   if(e>=dna.size())e=dna.size();
   if(s>=dna.size())return;
   auto it_s=dna.begin();auto it_e=dna.begin();
   advance(it_s,s-1);advance(it_e,e);
   dna.splice(dna.begin(),dna,it_s,it_e);
}
void dna_2(int s,int e,list <char> &dna) {
   if(e>=dna.size())e=dna.size();
   if(s>=dna.size())return;
   auto it_s=dna.begin();auto it_e=dna.begin();
   advance(it_s,s-1);advance(it_e,e);
   dna.splice(dna.end(),dna,it_s,it_e);
}
void dna_3(int s,int e,list <char> &dna) {
   if(e>=dna.size())e=dna.size();
   if(s>=dna.size())return;
   auto it_s=dna.begin();auto it_e=dna.begin();
   advance(it_s,s-1);advance(it_e,e);
   dna.erase(it_s,it_e);
}
void dna_4(int s,int e,list <char> &dna) {
   if(e>=dna.size())e=dna.size();
   if(s>=dna.size())return;
   auto it_s=dna.begin();auto it_e=dna.begin();
   advance(it_s,s-1);advance(it_e,e);
   dna.insert(it_s,it_s,it_e);
}
void dna_5(int s,int e,list <char> &dna) {
   if(e>=dna.size())e=dna.size();
   if(s>=dna.size())return;
   list <char> temp;
   auto it_s=dna.begin();auto it_e=dna.begin();
   advance(it_s,s-1);advance(it_e,e);
   temp.splice(temp.begin(),dna,it_s,it_e);
   temp.reverse();
   it_s=dna.begin();advance(it_s,s-1);
   dna.splice(it_s,temp);
}
void dna_6(int s,int e,list <char> dna) {
   if(e>=dna.size())e=dna.size();
   if(s>=dna.size()){cout<<"NONE";return;}
   auto it_s=dna.begin();auto it_e=dna.begin();
   advance(it_s,s-1);advance(it_e,e);
   for(auto it=it_s;it!=it_e;it++){cout<<*it;}
}
int op_i(string op,vector <string> op_l) {
   for (int i=0;i<op_l.size();i++) {if(op==op_l[i])return i;}
   return 0;
}
void op_in(int n,list <char> &dna){
   string oper;int op,s,e;
   vector <string> oper_list{"front","back","cut","double","flip","report"};
   for(int i=0;i<n;i++) {
      cin>>oper>>s>>e;
      op=op_i(oper, oper_list);
      switch(op){
      case 0:dna_1(s,e,dna);break; 
      case 1:dna_2(s,e,dna);break;
      case 2:dna_3(s,e,dna);break;
      case 3:dna_4(s,e,dna);break;
      case 4:dna_5(s,e,dna);break;
      case 5:dna_6(s,e,dna);break;
      }
   }
}
int main(void){
   list <char> dna;
   ifstream fin("/NESPA/sapiens.txt");
   char c;bool ch=false;
   while(fin.get(c)){if(c=='\n')ch=true;if(ch&&c!='\n')dna.push_back(c);}
   fin.close();
   int n;
   cin>>n;
   op_in(n,dna);
   return 0;
}
