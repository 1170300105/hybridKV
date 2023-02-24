#include "rocksdb/db.h"
#include <string>
class rocksdbHandler{
    public:
        std::string get(std::string key);
        void put(std::string key,std::string value);
        rocksdbHandler(std::string kDBPath);
        ~rocksdbHandler();
    private:
        std::string kDBPath;
        ROCKSDB_NAMESPACE::DB* db;
};