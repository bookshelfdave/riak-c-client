#include "./include/RiakObject.h"
#include "./include/RiakClient.h"
#include "./include/RiakConfig.h"
#include "./include/RiakBinary.h"

#include "../internal/riak_object-internal.h"

RiakObject::RiakObject(RiakClient* client, riak_object* obj) : client(client), obj(obj) {
    value = new RiakBinary(client->getRiakConfig(), obj->value);
}

RiakObject::~RiakObject() {
    riak_object_free(client->_raw_config(), &obj);
    delete(value);
}


RiakBinary* RiakObject::getValue() {
    return value;
}