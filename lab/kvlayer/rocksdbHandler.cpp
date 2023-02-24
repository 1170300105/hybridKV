#include "rocksdb/db.h"
#include "rocksdb/options.h"
#include "rocksdb/slice.h"
#include "rocksdbHandler.h"

using ROCKSDB_NAMESPACE::DB;
using ROCKSDB_NAMESPACE::Options;
using ROCKSDB_NAMESPACE::PinnableSlice;
using ROCKSDB_NAMESPACE::ReadOptions;
using ROCKSDB_NAMESPACE::Status;
using ROCKSDB_NAMESPACE::WriteBatch;
using ROCKSDB_NAMESPACE::WriteOptions;

rocksdbHandler::rocksdbHandler(std::string kDBPath){
    this->kDBPath = kDBPath;
    Options options;
    options.create_if_missing = true;
    Status s = DB::Open(options, kDBPath, &db);
    
}
rocksdbHandler::~rocksdbHandler(){
    this->db->Close();
}
std::string rocksdbHandler::get(std::string key){
    std::string value;
    Status s = db->Get(ReadOptions(), key, &value);
    return value;
}
void rocksdbHandler::put(std::string key,std::string value){
    Status s = db->Put(WriteOptions(), key, value);
}