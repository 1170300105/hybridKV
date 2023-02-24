#include "msgHandler.h"
#include <string>

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
void msgHandler::handleMsg(msg* msg,msgHandleResult* r){
    if(msg->type == kvCmd){
        dbType dbtype = this->region->getdbType(msg->regionId);
        if(msg->msgCmd[1]=="put"){
            int kvCount = std::stoi(msg->msgCmd[2]);
            for(int i=0;i<kvCount;i++){
                this->kv->handlePut(dbtype,msg->msgCmd[3+2*i],msg->msgCmd[4+2*i]);
            }
        }else if(msg->msgCmd[1]=="get"){
            int kvCount = std::stoi(msg->msgCmd[2]);
            for(int i=0;i<kvCount;i++){
                r->result.push_back(this->kv->handleGet(dbtype,msg->msgCmd[3+i]));
            }
        }else{

        }
    }else if (msg->type == raftCmd){
        
    }else{
        r->err = false;
        r->result = {"msg Type error"};
    }
    
}
void msgHandler::handleMsg(std::string s,msgHandleResult* r){
    std::vector<std::string> arg = stringSplit(s,'|');
    for(int i =0;i<arg.size();i++){
        printf("%s ,",arg[i].c_str());
    }
    printf("\n");
    msg m;
    m.msgCmd = arg;
    if(arg[0] == "kv"){
        m.type = msgType::kvCmd;
    }else if(arg[0] == "raft"){
       m.type = msgType::raftCmd; 
    }else{
        m.type = msgType::unkonw;
    }
    printf("arg[arg.size()-1] = %s\n",arg[arg.size()-1].c_str());
    printf("stoi = %d\n",std::stoi(arg[arg.size()-1]));
    m.regionId = std::stoi(arg[arg.size()-1]);
    handleMsg(&m,r);
}

msgHandler::msgHandler(){
    printf("create msgHandler");
    this->kv = new kvLayer;
    this->region = new regionHandler;
    this->region->setRegion({
        .id = 1,
        .dbtype = dbType::map
    });
    this->region->setRegion({
        .id = 2,
        .dbtype = dbType::rocks
    });
}
