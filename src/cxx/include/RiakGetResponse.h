#ifndef RIAK_CPP_GETRESPONSE_H
#define RIAK_CPP_GETRESPONSE_H
#include "riak.h"
#include <iostream>
#include <vector>

class RiakClient;
class RiakBinary;
class RiakObject;

class RiakGetResponse {
public:
    RiakGetResponse(RiakClient* client, riak_get_response* response);
    ~RiakGetResponse();
    bool hasVClock();
    RiakBinary* getVClock();
    riak_int32_t n();
    RiakObject* getObject(riak_int32_t index);
private:
    RiakBinary* vclock;
    riak_get_response *response;
    RiakClient *client;
    std::vector<RiakObject*> content;
};
#endif