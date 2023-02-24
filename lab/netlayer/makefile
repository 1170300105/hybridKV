include ../make_config.mk
ifndef DISABLE_JEMALLOC
	ifdef JEMALLOC
		PLATFORM_CXXFLAGS += -DROCKSDB_JEMALLOC -DJEMALLOC_NO_DEMANGLE
	endif
	EXEC_LDFLAGS := $(JEMALLOC_LIB) $(EXEC_LDFLAGS) -lpthread
	PLATFORM_CXXFLAGS += $(JEMALLOC_INCLUDE)
endif

ifneq ($(USE_RTTI), 1)
	CXXFLAGS += -fno-rtti
endif
CFLAGS += -Wstrict-prototypes

server:  ../kvlayer/rocksdbHandler.cpp ../kvlayer/kvLayer.cpp ../metalayer/regionHandler.cpp server.cpp msgHandler.cpp
	$(CXX) $(CXXFLAGS) $^ -o$@ ../librocksdb.a ../libhiredis.a ../libevent.a -I ../include -I ../ -O2 -std=c++17 $(PLATFORM_LDFLAGS) $(PLATFORM_CXXFLAGS) $(EXEC_LDFLAGS)

client: client.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@ ../libevent.a -I ../include -I ../ -O2 -std=c++17