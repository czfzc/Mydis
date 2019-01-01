#ifndef MYDIS_OPERATOR_H_INCLUDED
#define MYDIS_OPERATOR_H_INCLUDED
#include <string>
#include <vector>
using namespace std;

class linked_set{
    public:
        linked_set(string db_name);
        bool set_string(string value);
        bool rm_string(string value);
        vector<string> get_strings();
        string get_dbname();
        void print_all_sets();
    private:
        string db_name;
        vector<string> strings;
};

linked_set::linked_set(string db_name){
    this->db_name=db_name;
}

bool linked_set::set_string(string value){
    this->strings.push_back(value);
    return true;
}

bool linked_set::rm_string(string value){
    for(vector<string>::iterator it=strings.begin();it!=strings.end();it++){
        if(*it==value){
            strings.erase(it);
            return true;
        }
    }
    return false;
}

vector<string> linked_set::get_strings(){
    return strings;
}

string linked_set::get_dbname(){
    return db_name;
}

void linked_set::print_all_sets(){
    for(vector<string>::iterator it=strings.begin();it!=strings.end();it++){
        cout<<*it<<endl;
    }
}


#endif // MYDIS_OPERATOR_H_INCLUDED
