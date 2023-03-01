# hybridKV

尝试在分布式数据库架构下，同时使用多种数据存储方式作为底层的存储层

上层架构类似spanner，更接近于tidb

底层使用Key-Value模型存储，且数据按key的范围划分为互斥的数据片（region）

使用raft作为共识协议（每个region有自己的共识组）

需要额外的节点收集每个region的元数据信息(类似tidb的PD节点)，对region在何种数据结构中存储给出指导，并在发生错误时矫正

一旦确定region中的数据放入何种存储结构则不会再自主变化，即使region分裂，分裂后的两个region均采用原region存储结构。

监控可通过transtore指令来进行修改region存储结构，但是该指令也为raft指令需要走一遍共识协议，但只在对应节点上被执行。

每个节点上的主从副本隔离存放，以加速leader-region的处理速度。

Raft+libevent+Rocksdb/Multi-ART/Two-layer Log/Skiplist/Multi-LSM Tree/FASTDB/B+ Tree

Raft：<a>https://github.com/eBay/NuRaft</a>

libevent: <a>https://github.com/search?q=libevent</a>

Rocksdb: <a>https://github.com/facebook/rocksdb</a>

Multi-ART: <a>https://github.com/UncP/aili</a>

Two-layer Log: <a>https://github.com/ustcadsl/depart</a>

Rpc：<a>https://github.com/rpclib/rpclib</a>
