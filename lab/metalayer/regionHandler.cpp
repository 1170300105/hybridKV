#include "regionHandler.h"
dbType regionHandler::getdbType(int regionId){
    return this->metaInfo[regionId].dbtype;
}
bool regionHandler::setRegion(region r){
    this->metaInfo[r.id] = r;
    return true;
}