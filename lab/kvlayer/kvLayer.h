#include "redisHandler.h"
#include "rocksdbHandler.h"
#include <string>
#include <map>
enum dbType{
    redis,
    rocks,
    map,
};
class kvLayer{
    public:
        kvLayer();
        std::string handleGet(dbType tp,std::string key);
        void handlePut(dbType tp,std::string key,std::string value);
        void handleDelete(dbType tp,std::string key);
    private:
        redisHandler* rds;
        rocksdbHandler* rks;
        std::map<std::string,std::string> kvmap;
        int ops = 0;

};

