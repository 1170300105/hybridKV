#include "hiredis/hiredis.h"
#include <string>
class redisHandler{
    public:
        std::string get(std::string key);
        void put(std::string key,std::string value);
        redisHandler();
        ~redisHandler();
    private:
        redisContext *c;
        redisReply *r;
};