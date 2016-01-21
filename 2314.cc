#include <cstdio>  
#include <cctype>  
#include <string>  
#include <map>  
#include <vector>  
#include <functional>  
#include <algorithm>  
using namespace std;  

bool isNumber(const string& s){
    if(s.empty()) return false;  
    for(int i = 0; i < s.size(); ++i){  
        if(!isdigit(s[i])) return false;  
    }  
    return true;  
}  
int toNumber(const string& s){
    int n;  
    sscanf(s.c_str(), "%d", &n);  
    return n;  
}  
struct Expression{  
    virtual ~Expression(){}  
    virtual void execute(){};  
};  
class Scope{  
private:  
    map<string,int> nameValueMap;  
    map<string,int>::const_iterator iter;  
    void intercept(const string& name){  
        printf("before access \"%s\"\n", name.c_str());  
        for(iter = nameValueMap.begin(); iter != nameValueMap.end(); ++iter){  
            printf("%s = %d\n", iter->first.c_str(), iter->second);  
        }  
    }  
public:  
    int& operator [] (const string& name){   
        return nameValueMap[name];  
    }  
} global;  
bool Terminate = false;  

struct Special : public Expression{  
    string variable;  
    Special(const string& s) : variable(s){}  
    virtual void execute(){  
        ::Terminate = true;  
        printf("%d\n", global[variable]);  
    }  
};  
struct Assignment : public Expression{  
    string A, B, OP, C;  
    Assignment(const string& s){   
        string::size_type equalSign = s.find('=');  
        A = s.substr(0, equalSign);  
        string::size_type op = s.find_first_of("+-*", equalSign+1);  
        if(op == string::npos) B = s.substr(equalSign+1);  
        else{  
            B = s.substr(equalSign+1, op-equalSign-1);  
            OP.push_back(s[op]);  
            C = s.substr(op+1);  
        }  
        if(isNumber(B)) global[B] = toNumber(B);  
        if(isNumber(C)) global[C] = toNumber(C);  
    }  
    virtual void execute(){  
        if(OP.empty()) global[A] = global[B];  
        else if(OP == "+") global[A] = global[B] + global[C];  
        else if(OP == "-") global[A] = global[B] - global[C];  
        else global[A] = global[B] * global[C];  
    }  
};  
struct Judgement : public Expression{  
    string A, OP, B;  
    bool result;  
    Judgement(const string& s){  
        string::size_type pos = s.find_first_of("<=");  
        if(s[pos+1] == '='){ 
            A = s.substr(0, pos);  
            OP = s.substr(pos, 2);  
            B = s.substr(pos+2);  
        }  
        else{
            A = s.substr(0, pos);  
            OP.push_back(s[pos]);  
            B = s.substr(pos+1);  
        }  
        if(isNumber(A)) global[A] = toNumber(A);  
        if(isNumber(B)) global[B] = toNumber(B);  
    }  
    virtual void execute(){  
        if(OP == "<") result = global[A] < global[B];  
        else if(OP == "==") result = global[A] == global[B];  
        else result = global[A] <= global[B];  
    }  
    bool judge(){  
        execute();  
        return result;  
    }  
};  
struct IfSuite : public Expression{  
    Judgement condition;  
    vector<Expression*> clause;  
    IfSuite(const string& s) : condition(s){}  
    ~IfSuite(){  
        for(int i = 0; i < clause.size(); ++i) delete clause[i];  
    }  
    void addClause(Expression* exp){  
        clause.push_back(exp);  
    }  
    virtual void execute(){  
        if(!::Terminate && condition.judge()){  
            for_each(clause.begin(), clause.end(), mem_fun(&Expression::execute));  
        }  
    }  
};  
struct WhileSuite : public Expression{  
    Judgement condition;  
    vector<Expression*> clause;  
    WhileSuite(const string& s) : condition(s){}  
    ~WhileSuite(){  
        for(int i = 0; i < clause.size(); ++i) delete clause[i];  
    }  
    void addClause(Expression* exp){  
        clause.push_back(exp);  
    }  
    virtual void execute(){  
        while(!::Terminate && condition.judge()){  
            for_each(clause.begin(), clause.end(), mem_fun(&Expression::execute));  
        }  
    }  
};  
class Program{  
private:  
    vector<Expression*> clause;  
private:  
    Expression* loadSpecial(){  
        char c;  
        string name;  
        while((c = getchar()) != ';'){  
            if(!isspace(c)) name.push_back(c);  
        }  
        return new Special(name);  
    }  
    Expression* loadIf(){  
        char c;  
        string condition;  
        while((c = getchar()) != ')'){  
            if(!isspace(c)) condition.push_back(c);  
        }  
        IfSuite* suite = new IfSuite(condition);  
        while(getchar() != '{') ;  
        load(suite->clause, '}');  
        return suite;  
    }  
    Expression* loadWhile(){  
        char c;  
        string condition;  
        while((c = getchar()) != ')'){  
            if(!isspace(c)) condition.push_back(c);  
        }  
        WhileSuite* suite = new WhileSuite(condition);  
        while(getchar() != '{') ;  
        load(suite->clause, '}');  
        return suite;  
    }  
    void load(vector<Expression*>& v, int endTag = -1){  
        int c;  
        string s;  
        while((c = getchar()) != endTag){
            if(isspace(c)) continue;  
            if(c == '('){
                if(s == "if") v.push_back(loadIf());  
                else v.push_back(loadWhile());  
                s.clear();  
            }  
            else if(c == '#'){
                v.push_back(loadSpecial());  
                s.clear();  
            }  
            else if(c == ';'){
                if(!s.empty()){  
                    v.push_back(new Assignment(s));  
                    s.clear();  
                }  
            }  
            else s.push_back(c);
        }  
    }  
public:  
    ~Program(){  
        for(int i = 0; i < clause.size(); ++i) delete clause[i];  
    }  
    void load(){  
        load(clause);  
    }  
    void run(){  
        for_each(clause.begin(), clause.end(), mem_fun(&Expression::execute));  
    }  
};  

int main()  
{  
    Program tiny;  
    tiny.load();  
    tiny.run();  
    return 0;  
}



