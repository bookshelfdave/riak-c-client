#ifndef RIAK_CPP_CONFIG_H
#define RIAK_CPP_CONFIG_H
#include "riak.h"
class RiakConfig {
public:
    friend class RiakConnection;
    friend class RiakClient;
    friend class RiakBucket;
    RiakConfig();
    ~RiakConfig();
    riak_config* raw();
private:
    riak_config* raw_cfg;
};
#endif