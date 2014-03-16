#include "./include/RiakConfig.h"
#include "./include/RiakConnection.h"
#include "riak.h"
#include <iostream>

RiakConnection::RiakConnection(RiakConfig *cfg, const char *host, const char *port) {
     riak_error err = riak_connection_new(cfg->raw_cfg, &raw_conn, host, port, NULL);
     if(err != ERIAK_OK) {
        throw RiakException();
     }
}



RiakConnection::~RiakConnection() {
    riak_connection_free(&raw_conn);
}