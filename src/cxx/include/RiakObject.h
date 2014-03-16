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
    RiakBinary* 	getBucket();
    riak_boolean_t  hasKey();
    RiakBinary* 	getKey();
    RiakBinary* 	getValue();
    riak_boolean_t  hasCharset();
    RiakBinary* 	getCharset();
    riak_boolean_t  hasContentType();
    RiakBinary* 	getContentType();
    riak_boolean_t  hasEncoding();
    RiakBinary* 	getEncoding();
    riak_boolean_t  hasVTag();
    RiakBinary* 	VTag();

	/*last_mod
	last_mod_usecs
	deleted
	n_links
	*/

private:
    RiakClient *client;
    riak_object* obj;
    RiakBinary* bucket;
    RiakBinary* key;
    RiakBinary* value;
    RiakBinary* charset;
    RiakBinary* content_type;
    RiakBinary* encoding;
    RiakBinary* vtag;
};
#endif