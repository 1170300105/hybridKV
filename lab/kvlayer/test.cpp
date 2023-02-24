#include "kvLayer.h"
#include <iostream>
#include <time.h>
int main(int argc, char const *argv[])
{   
    int testSize = 10000000;
    kvLayer kvlayer;
    clock_t start,end;
    start = clock();
    for(int i=0;i<testSize;i++){
        kvlayer.handlePut(map,std::to_string(i),"aaaaaaaaaaaaaaaaaaaa");
    }
    end = clock();
    double endtime=(double)(end-start)/CLOCKS_PER_SEC;
	std::cout<<"Total time(map_put):"<<endtime*1000<<"ms"<<std::endl;
    start = clock();
    for(int i=0;i<testSize;i++){
        kvlayer.handlePut(rocks,std::to_string(i),"aaaaaaaaaaaaaaaaaaaa");
    }
    end = clock();
    endtime=(double)(end-start)/CLOCKS_PER_SEC;
	std::cout<<"Total time(rks_put):"<<endtime*1000<<"ms"<<std::endl;
    start = clock();
    for(int i=0;i<testSize;i++){
        kvlayer.handleGet(map,std::to_string(i));
    }
    end = clock();
    endtime=(double)(end-start)/CLOCKS_PER_SEC;
	std::cout<<"Total time(map_get):"<<endtime*1000<<"ms"<<std::endl;
    start = clock();
    for(int i=0;i<testSize;i++){
        kvlayer.handleGet(rocks,std::to_string(i));
    }
    end = clock();
    endtime=(double)(end-start)/CLOCKS_PER_SEC;
	std::cout<<"Total time(rks_get):"<<endtime*1000<<"ms"<<std::endl;
    return 0;
}
