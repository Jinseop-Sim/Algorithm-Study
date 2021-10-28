#include <iostream>
#include <list>
#include <fstream>
#include <vector>
using namespace std;

void my_front(int s, int e, list <char>& chro) {
   if (e>chro.size())return;
   auto s_it = chro.begin(), e_it = chro.begin(); advance(s_it, s - 1); advance(e_it, e);
   chro.splice(chro.begin(),chro,s_it,e_it);
}
void my_back(int s, int e, list <char>& chro) {
   if (e>chro.size())return;
   auto s_it = chro.begin(), e_it = chro.begin(); advance(s_it, s - 1); advance(e_it, e);
   chro.splice(chro.end(),chro,s_it,e_it);
}
void cut(int s, int e, list <char>& chro) {
   if (e>chro.size())return;
   auto s_it = chro.begin(), e_it = chro.begin(); advance(s_it, s - 1); advance(e_it, e);
   chro.erase(s_it,e_it);
}
void my_double(int s, int e, list <char>& chro) {
   if (e>chro.size())return;
   auto s_it = chro.begin(), e_it = chro.begin(); advance(s_it, s - 1); advance(e_it, e);
   chro.insert(e_it,s_it,e_it);
}
void my_flip(int s, int e, list <char>& chro) {
   if (e>chro.size())return;
   list<char> temp;
   auto s_it = chro.begin(), e_it = chro.begin(); advance(s_it,s-1); advance(e_it, e);
   temp.splice(temp.begin(),chro,s_it,e_it); temp.reverse();
   s_it = chro.begin(); advance(s_it,s-1);
   chro.splice(s_it,temp,temp.begin(),temp.end());
}
void my_report(int s, int e, list <char> chro) {
   if (e>chro.size()) e = chro.size();
   if (s>chro.size()) {
      cout <<"NONE"<< endl; return;
   }
   auto s_it = chro.begin(), e_it = chro.begin(); advance(s_it,s-1); advance(e_it,e);
   for (auto i=s-1;i<e;i++) cout << *s_it++; cout << endl;
}
int act(string action) {
   vector <string> oper{"front","back","cut","double","flip","report"};
   int code=0;
   for (auto i :oper) {
      if (i==action) return code;
      else code++;
   }
}
void act_in(int n, list<char> &chro) {
   string action;
   int s = 0, e = 0;
   for (int i=0;i<n;i++){
      cin >> action;
      cin >> s >> e;
      int code = act(action);
      switch(code){
      case 0: my_front(s,e,chro); break;
      case 1: my_back(s,e,chro); break;
      case 2: my_cut(s,e,chro); break;
      case 3: my_double(s,e,chro); break;
      case 4: my_flip(s,e,chro); break;
      case 5: my_report(s,e,chro); break;
      }
   }
}
int main(void) {
   list <char> chro;
   ifstream in("/NESPA/sapiens.txt");
   char c; bool f = false;
   while (in.get(c)) {
      if (c=='\n') f = true;
      if (f&&c!='\n') chro.push_back(c);
   } in.close();
   int n=0;
   cin >> n;
   act_in(n,chro);
   return 0;
}
