#ifndef MYDIS_MAIN_H_INCLUDED
#define MYDIS_MAIN_H_INCLUDED
#include<string>
#include<vector>
#include<iostream>
#include "mydis_operator.h"
using namespace std;

const static string user="root";
const static string pass="root";

bool contains(string arg){
    for(int i=0;arg[i]!='\0';i++){
        if((arg[i]=='@'&&i!=arg.length()-1)&&i!=0){
            return true;
        }
    }
    return false;
}

bool check_login(string arg){
    for(int i=0;i<arg.length();i++){
        string myuser=arg.substr(0,i);
        string mypass=arg.substr(i+1,arg.length()-i-1);
        if(user==myuser&&pass==mypass)
            return true;
    }
    return false;
}

bool check_dbname_and_insert_set(vector<linked_set> sets,string db_name,string value){
        for(vector<linked_set>::iterator it=sets.begin();it!=sets.end();it++){
            if(it->get_dbname()==db_name){
                it->set_string(value);
                return true;
            }
        }
        return false;
}

bool check_dbname_and_remove_set(vector<linked_set> sets,string db_name,string value){
        for(vector<linked_set>::iterator it=sets.begin();it!=sets.end();it++){
            if(it->get_dbname()==db_name){
                it->rm_string(value);
                return true;
            }
        }
        return false;
}

bool check_dbname_and_print_all_set(vector<linked_set> sets,string db_name){
        for(vector<linked_set>::iterator it=sets.begin();it!=sets.end();it++){
            if(it->get_dbname()==db_name){
                it->print_all_sets();
                return true;
            }
        }
        return false;
}


#endif // MYDIS_MAIN_H_INCLUDED
