#include "./include/RiakConfig.h"
#include "riak.h"
RiakConfig::RiakConfig() {
    riak_error err = riak_config_new_default(&raw_cfg);
}

RiakConfig::~RiakConfig() {
    riak_config_free(&raw_cfg);
}

riak_config* RiakConfig::raw() {
    return raw_cfg;
}