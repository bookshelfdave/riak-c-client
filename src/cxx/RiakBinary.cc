#include "./include/RiakBinary.h"
#include "./include/RiakConfig.h"

RiakBinary::RiakBinary(RiakConfig* cfg, riak_binary* bin) : cfg(cfg), bin(bin) {

}

RiakBinary::~RiakBinary() {
    riak_binary_free(cfg->raw(), &bin);
}