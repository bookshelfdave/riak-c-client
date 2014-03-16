#ifndef RIAK_CPP_CONNECTION_H
#define RIAK_CPP_CONNECTION_H
#include "riak.h"
#include <iostream>

struct RiakException : std::exception {
};

class RiakConnection {
friend class RiakBucket;
public:
    RiakConnection(RiakConfig *cfg, const char *host, const char* port);
    ~RiakConnection();
private:
    riak_connection *raw_conn;
};
#endif