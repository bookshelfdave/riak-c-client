#include "./include/RiakBinary.h"
#include "./include/RiakConfig.h"

#include "../internal/riak_messages-internal.h"
#include "../internal/riak_utils-internal.h"
#include "../internal/riak_binary-internal.h"
#include "../internal/riak_object-internal.h"
#include "../internal/riak_config-internal.h"


RiakBinary::RiakBinary(RiakConfig* cfg, riak_binary* bin) : cfg(cfg), bin(bin) {

}

RiakBinary::~RiakBinary() {
    riak_binary_free(cfg->raw(), &bin);
}

char* RiakBinary::getData() {
    return (char*)bin->data;
}