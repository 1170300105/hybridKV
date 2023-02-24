#include "msgHandler.h"

void handleMsg(msg* msg,msgHandleResult* r){
    if(msg->type == kvCmd){
        if(msg->msgCmd[1]=="put"){

        }else if(msg->msgCmd[1]=="get"){

        }else{

        }
    }else if (msg->type == raftCmd){
        
    }else{
        r->err = false;
        r->result = "msg Type error";
    }
    
}
void handleMsg(std::string s,msgHandleResult* r){
    std::vector<std::string> arg = stringSplit(s,'|');
    msg m;
    m.msgCmd = arg;
    if(arg[0] == "kv"){
        m.type = msgType::kvCmd;
    }else{
       m.type = msgType::raftCmd; 
    }
}
msgHandler::msgHandler(){
    this->kv = new kvLayer;
}
std::vector<std::string> stringSplit(const std::string& str, char delim) {
    std::size_t previous = 0;
    std::size_t current = str.find_first_of(delim);
    std::vector<std::string> elems;
    while (current != std::string::npos) {
        if (current > previous) {
            elems.push_back(str.substr(previous, current - previous));
        }
        previous = current + 1;
        current = str.find_first_of(delim, previous);
    }
    if (previous != str.size()) {
        elems.push_back(str.substr(previous));
    }
    return elems;
}