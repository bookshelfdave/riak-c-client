#ifndef RIAK_CPP_CLIENT_H
#define RIAK_CPP_CLIENT_H
#include <vector>

#include "riak.h"
#include "RiakConfig.h"
#include "RiakConnection.h"
#include "RiakBucket.h"

class RiakClient {
friend class RiakBucket;
public:
    RiakClient();
    ~RiakClient();
    // TODO: port number as a string is silly
    void connect(const char* host, const char* port);
    RiakBucket *fetchBucket(const char* bucket_type, const char* bucket_name);
    RiakConnection* getNextConnection();
    riak_config* _raw_config();
    RiakConfig* getRiakConfig();
private:
    RiakConfig *cfg;
    std::vector<RiakConnection*> connections;
};

#endif