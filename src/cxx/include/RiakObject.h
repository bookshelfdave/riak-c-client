#ifndef RIAK_CPP_OBJECT_H
#define RIAK_CPP_OBJECT_H
#include "riak.h"
#include "../internal/riak_messages-internal.h"
#include "../internal/riak_utils-internal.h"
#include "../internal/riak_binary-internal.h"
#include "../internal/riak_object-internal.h"
#include "../internal/riak_config-internal.h"

#include <iostream>
#include <vector>

class RiakClient;
class RiakBinary;

class RiakObject {
public:
    RiakObject(RiakClient* client, riak_object* obj);
    ~RiakObject();
private:
    RiakClient *client;
    riak_object* obj;
};
#endif