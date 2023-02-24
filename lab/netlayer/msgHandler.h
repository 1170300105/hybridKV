#include "msg.h"
#include "metalayer/regionHandler.h"
class msgHandler{
    public:
        void handleMsg(msg* msg,msgHandleResult* r);
        void handleMsg(std::string msg,msgHandleResult* r);
        msgHandler();
    private:
        kvLayer* kv;
        regionHandler* region;
};
