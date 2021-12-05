#include <iostream>
#include <vector>
#include <algorithm>
#define NP nullptr
using namespace std;

struct node{ // 보통 배열로 만들면 Skewed Tree 같은 특수한 Case에 시간이 너무 많이 소요된다.
	node* left; // 따라서 이렇게 직접 구조체로 Tree의 모양을 만든다.
	node* right;
	string str;
};

void bts::add_node(){ // Binary Tree에 Node를 추가하는 함수이다.
	string s;
	cin >> s;
	
	node* new_node = new node{NP,NP,s}; // Left, Right, str 구조체에 순서대로 집어넣은 것이다.
	new_node->str = s; // 이렇게 보통은 구조체 포인터에 대한 접근으로 구조를 만든다.
	
	if(root==NP)	root=new_node; // Root가 Nullptr(없다) 이면, New_Node를 Root에 집어넣는다.
	else{
		node* ptr=root; // Root가 이미 존재한다면, root를 가리키는 포인터를 하나 만들고
		node* parent=NP; // parent를 저장한 포인터를 하나 만든다.
		
		while(ptr!=NP){ 
			parent=ptr; // parent(ptr)가 NP를 가리키게 되면, 그것은 Root인 것이다.
			if		(s==ptr->str)	return; // 입력받은 string s가 이미 존재하는 단어라면 그냥 return한다.
			else if	(s> ptr->str)	ptr = ptr->right; // 입력받은 string s가 가리키고 있는 ptr의 단어보다 크다면 오른쪽으로 들어간다.
			else 						ptr = ptr->left; // 입력받은 string s가 가리키고 있는 ptr의 단어보다 작다면 왼쪽으로 들어간다.
		}
		if(s > parent->str)		parent->right = new_node; // 들어간 s가 parent의 단어보다 크다면 parent의 오른쪽 노드로 들어가고
		else						parent->left  = new_node; // s가 parent의 단어보다 작다면, 왼쪽 노드로 들어간다.
	}
}

int main(){
	vector<string> menu={"+","-","depth","leaf","quit"}; // Switch 문을 사용할 때는 이렇게 Token을 사용하는 것이 좋다.
	bool run=true;
	bts BTS=bts();
	
	while(run){
		string s;
		cin>>s;
		
		int select=find(menu.begin(),menu.end(),s)-menu.begin(); // 이런식으로 Token에 번호를 부여해 이용한다.
		switch(select){
			case 0:
				BTS.add_node();		break;
			case 1:
				BTS.remove_node();	break;
			case 2:
				BTS.print_depth();	break;
			case 3:
				BTS.print_leaf();	break;
			case 4:
				run=false;			break;
			default:
				exit(1);
		}
	}
}
