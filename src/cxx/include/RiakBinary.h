#ifndef RIAK_BINARY_H
#define RIAK_BINARY_H
#include "riak.h"
#include <iostream>

class RiakConfig;

class RiakBinary {
public:
    RiakBinary(RiakConfig* cfg, riak_binary* bin);
    ~RiakBinary();

private:
    RiakConfig* cfg;
    riak_binary* bin;
};
#endif