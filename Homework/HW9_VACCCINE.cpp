#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void vac_sort(int number, int age, int sex,
              vector<int> &oldman, vector<int> &oldwoman, vector<int> &child,
              vector<int> &adultman, vector<int> &adultwoman){

    if(age <= 15) child.push_back(number);
    else if(15 < age && age <= 60){
        if(sex == 'M') adultman.push_back(number);
        else adultwoman.push_back(number);
    }
    else if(60 < age){
        if(sex == 'M') oldman.push_back(number);
        else oldwoman.push_back(number);
    }
}

void vac_input(int n, vector<int> &oldman, vector<int> &oldwoman, vector<int> &child,
               vector<int> &adultman, vector<int> &adultwoman){
    vector<int> temp(3, 0);
    int number = 0, age = 0;
    char sex = 0;

    for(int i=0; i<n; i++){
        cin >> number >> age >> sex;
        vac_sort(number, age, sex, oldman, oldwoman, child, adultman, adultwoman);
    }
}

void print_answer(int n, vector<int> &oldman, vector<int> &oldwoman, vector<int> &child, vector<int> &adultman, vector<int> &adultwoman){
    for (int i = 0; i < oldman.size(); i++) {
        cout << oldman[i] << endl;
    }
    for (int i = 0; i < oldwoman.size(); i++) {
        cout << oldwoman[i] << endl;
    }
    for (int i = 0; i < child.size(); i++) {
        cout << child[i] << endl;
    }
    for (int i = 0; i < adultwoman.size(); i++) {
        cout << adultwoman[i] << endl;
    }
    for (int i = 0; i < adultman.size(); i++) {
        cout << adultman[i] << endl;
    }
}


int main(void){
    int n;
    cin >> n;
    vector<int> oldman;
    vector<int> oldwoman;
    vector<int> child;
    vector<int> adultman;
    vector<int> adultwoman;

    vac_input(n, oldman, oldwoman, child, adultman, adultwoman);
    print_answer(n, oldman, oldwoman, child, adultman, adultwoman);

    return 0;
}
