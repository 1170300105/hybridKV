#include <string> 
//[kv|put|kvNum|k1|v1|.....|regionId]
//[kv|get|kvNum|k1|k2|.....|regionId]
//[kv|delete|kvNum|k1|k2|.....|regionId]
//[kv|scan|kvNum|start1|end1|.....|regionId]
//[raft|transferLeader|storeid|regionId]
//[raft|split|regionId]
//[raft|destroy|regionId]
struct msg{
    msgType type;
    std::vector<std::string> msgCmd;
    int regionId;
};
enum msgType{
    kvCmd,
    raftCmd,
    heartBeat
};
struct msgHandleResult{
    bool err;
    std::string result;
};
