#include "kvLayer.h"
kvLayer::kvLayer(){
    //this->rds = new redisHandler();
    this->rks = new rocksdbHandler("../testData");
}

std::string kvLayer::handleGet(dbType tp,std::string key){
    this->ops++;
    if(tp == redis){
        //return this->rds->get(key);
        return "redis no use any more";
    }else if(tp == map){
        return kvmap[key];
    }else{
        return this->rks->get(key);
    }
}

void kvLayer::handlePut(dbType tp,std::string key,std::string value){
    this->ops++;
    if(tp == redis){
       // return this->rds->put(key,value);
       // return "redis no use any more";
    }else if(tp == map){
        kvmap.emplace(key,value);
    }else{
        return this->rks->put(key,value);
    }
}

void kvLayer::handleDelete(dbType tp,std::string key){
    this->ops++;
    if(tp == redis){
        //return this->rds->put(key,"");
       // return "redis no use any more";
    }else if(tp == map){
         kvmap.emplace(key,"");
    }else{
        return this->rks->put(key,"");
    }
}