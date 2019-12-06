#include <stdio.h>
#include "before.hpp"

vector<User> users;
int current_login = -1;
vector<Snail*> snail(5);
void show_menu();
bool login(vector<User> users, string id, string password){

    for(int i = 0; i < users.size(); i++){
        if(id == users[i].name){
            if(password == users[i].password){
                current_login = i;
                return true;
            }
        }
    }
    return false;
}


void my_page() {
   cout << "▶ 마이 페이지 ◀" << endl;
   cout<<current_login<<endl;
   cout << "아이디 : " << users.at(current_login).name << endl;
   cout << "보유 금액 : " << users.at(current_login).money << endl;
   for (int i = 0; i < users.at(current_login).record.length(); i++) {
      cout << i + 1 << "번 째 경기 : ";
      if (users.at(current_login).record[i])
         cout << "승" << endl;
      else
         cout << "패" << endl;
   }
}

void charge_money() {
   if (users.at(current_login).money == 0) {
      do {
         cout << "충전할 금액 (1~100,000) ▶ ";
         int charge;
         cin >> charge;
         if (charge > 1 && charge < 100000) {
            users.at(current_login).money = charge;
            cout << charge << "원이 충전되었습니다." << endl;
            break;
         }
         else {
            cout << "충전할 수 있는 금액은 1원 이상, 100,000원 이하입니다." << endl;
         }
      } while (true);

   }
   else
      cout << "현재 보유하고 있는 금액이 0원이 아닙니다. 충전할 수 없습니다!" << endl;
}


int main(){

    FILE *fp;
    char buf[1024];
    
    //fp = fopen("/home/noakfakf/바탕화면/workspace/noa/userinfo.txt", "r");
    fp = fopen("./userinfo.txt", "r");
    if(fp == NULL){
        printf("fail \n");
        return 1;
    }
    
    loadFile(fp);

    for(int i = 0; i < users.size(); i++){
        cout << users[i].name << endl;
        cout<<users[i].password<<endl;
        cout<<users[i].money<<endl;
        cout<<users[i].record<<endl;
    }
    fclose(fp);


    // Login
    while (1)
    {
        int num;
        cout << "1) Log in    2) Exit : " ;
        cin >> num;
        if(num == 1){
         string t1;
         string t2;
         cout << " id : ";
         cin >> t1;
         cout << " pw : ";
         cin >> t2;
            if (login(users, t1, t2)) {
                //cout << "login success" << endl;
                show_menu();
            }
            else {
                cout << "회원 정보가 없습니다." << endl;
            }
        }
        else if(num == 2){
            exit(0);
        }
        else{
            cout << "잘못된 입력입니다" << endl;
        }
    }
    return 0;
}

void show_menu() {
   int menu;
   do {
      cout << "1. 경주\n2. 마이 페이지\n3. 충전하기\n4. 로그아웃" << endl;
      cout << "메뉴 선택 ▶ ";
      cin >> menu;
      switch (menu) {
      case 1:
         race_start();
         break;
      case 2:
         my_page();
         break;
      case 3:
         charge_money();
         break;
      case 4:
         cout << "로그아웃 되었습니다." << endl;
         break;
      default:
         cout << "잘못된 입력입니다." << endl;
         break;
      }
   }while(menu != 4);
}
