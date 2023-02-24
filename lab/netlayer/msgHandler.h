#include "msg.h"
#include "kvlayer/kvLayer.h"
#include "metalayer/reginHandler.h"
class msgHandler{
    public:
        void handleMsg(msg* msg,msgHandleResult* r);
        void handleMsg(std::string msg,msgHandleResult* r);
        msgHandler();
    private:
        kvLayer* kv;
        regionHandler* region;
};
