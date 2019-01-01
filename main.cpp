#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include "mydis_main.h"
#include "mydis_operator.h"
using namespace std;

int init(){
    vector<linked_set> sets;
    while(true){
        cout<<">";
        string arg;
        cin>>arg;
        if(arg=="set"){
            string db_name,value;
            cin>>db_name>>value;
            if(!check_dbname_and_insert_set(sets,db_name,value)){
                linked_set a_set(db_name);
                a_set.set_string(value);
                sets.push_back(a_set);
            }
            cout<<"success"<<endl;
        }else if(arg=="rm"){
            string db_name,value;
            cin>>db_name>>value;
            if(check_dbname_and_insert_set(sets,db_name,value)){
                cout<<"success"<<endl;
            }else cout<<"faliure"<<endl;
        }else if(arg=="getall"){
            string db_name;
            cin>>db_name;
            if(check_dbname_and_print_all_set(sets,db_name)){
                cout<<"success"<<endl;
            }else cout<<"faliure"<<endl;
        }else if(arg=="exit"){
            return 0;
        }
    }
}

int main(int argc, char * argv[])
{
    while(true&&argc>1){
        if(!strcmp(argv[1],"-h")){
            cout<<"usage: mydis user@password"<<endl;
            return 0;
        }else if(contains(string(argv[1]))){
            if(check_login(string(argv[1])))
                return init();
            else{
                cout<<"you are denied for your entered user and password."<<endl;
                return 0;
            }
        }else{
            cout<<"please type -h to get help"<<endl;
            return 0;
        }

    }

    cout<<"goodbye!"<<endl;

    return 0;

}
