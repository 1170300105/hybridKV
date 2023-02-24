#include "hiredis/hiredis.h"
#include "redisHandler.h"
#include <iostream>
#include <string>
redisHandler::redisHandler(){
    this->c = redisConnect("127.0.0.1",6379);
    if(c->err){
       redisFree(c);
       std::cout<<"connect to redis fail"<<std::endl;
       return ;
    }
};
redisHandler::~redisHandler(){
    redisFree(this->c);
}
std::string redisHandler::get(std::string key){
    redisReply *r = (redisReply*)redisCommand(c,("get "+key).c_str());
    std::string s ;
   if (NULL == r)
	{
	std::cout << "Execut set failed" << std::endl;
	freeReplyObject(r);
	redisFree(c);
	}else{
    s = r->str;   
    freeReplyObject(r);
    }
    return s;
};
void redisHandler::put(std::string key,std::string value){
    redisReply *r = (redisReply*)redisCommand(c,("set "+key+" "+value).c_str());
    freeReplyObject(r);

}