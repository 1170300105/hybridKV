#include <vector>
#include <map>
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
    //std::vector<msg> cmd;
};

class regionHandler{
    public:
        region* getRegionInfo(int regionId);
        void handleSplit(int regionid,int newid,int splitkey);
        dbType getdbType(int regionId);
        bool setRegion(region r);
    private:
        std::map<int,region > metaInfo;
};