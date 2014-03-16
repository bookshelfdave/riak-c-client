#include "./include/RiakGetResponse.h"
#include "./include/RiakClient.h"
#include "./include/RiakBinary.h"
#include "./include/RiakObject.h"
#include "../internal/riak_messages-internal.h"

RiakGetResponse::RiakGetResponse(RiakClient* client, riak_get_response* response) :
    client(client), response(response) {
    if(response->has_vclock) {
        vclock = new RiakBinary(client->getRiakConfig(), response->vclock);
    }
    for(int i = 0; i < response->n_content; i++) {
        riak_object* o = response->content[i];
        content.push_back(new RiakObject(client, o));
    }
}

RiakGetResponse::~RiakGetResponse() {
    // TODO: erase content
    riak_get_response_free(client->_raw_config(), &response);
    delete(vclock);
}

bool RiakGetResponse::hasVClock() {
    return response->has_vclock;
}

RiakBinary* RiakGetResponse::getVClock() {
    return vclock;
}

riak_int32_t RiakGetResponse::n() {
    return response->n_content;
}

RiakObject* RiakGetResponse::getObject(riak_int32_t index) {
    if(index > response->n_content) {
        // TODO
        return 0;
    } else {
        return content[index];
    }
}