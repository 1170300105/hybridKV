#include <vector>
#include "netlayer/msg.h"
#include "kvlayer/kvLayer.h"
struct region
{
    /* data */
    long start;
    long end;
    int id;
    bool isLeader;
    dbType dbtype;
    int cont=0;
    std::vector<msg> cmd;
};

class regionHandler{
    public:
        region* getRegionInfo(int regionId);
        void handleSplit(int regionid,int newid,int splitkey);
    private:
        std::map<int,region *> metaInfo;
};