#include <stdio.h>
#include "before.hpp"

vector<User> user;
int current_login = -1;
vector<Snail*> snail(5);

bool login(vector<User> users, string id, string password){

    for(int i = 0; i < users.size(); i++){
        if(id == users[i].name){
            if(password == users[i].password){
                return true;
            }
        }
    }

    return false;
}

int main(){

    FILE *fp;
    char buf[1024];
    
    vector<User> users;
    
//    fp = fopen("/home/noakfakf/바탕화면/workspace/noa/userinfo.txt", "r");
	fp = fopen("./userinfo.txt", "r");
    if(fp == NULL){
        printf("fail \n");
        return 1;
    }
    
    users = loadFile(fp);

    // for(int i = 0; i < users.size(); i++){
    //     cout << users[i].name << endl;
    // }
    fclose(fp);


    //input id & pw
    string inputId = "";
    string inputPw = "";
    // Login
    while (1)
    {
        int num;
        cout << "1) Log in    2) Exit : " ;
        cin >> num;
        if(num == 1){
            string t1;
            string t2;
            cout << " id : " ;
            cin >> t1;
            cout << " pw : " ;
            cin >> t2;
            if(login(users, t1, t2)){
                //success
                    //start menu
                    cout << "login success" << endl;

					// In a menu
					// race_start();
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
