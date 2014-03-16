#include "./include/RiakObject.h"
#include "../internal/riak_object-internal.h"

RiakObject::RiakObject(RiakClient* client, riak_object* obj) : client(client), obj(obj) {

}

RiakObject::~RiakObject() {
    //riak_object_free(obj);
}
