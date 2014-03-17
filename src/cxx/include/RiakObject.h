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


	riak_boolean_t hasLastMod();
    riak_uint32_t  getLastMod();

    riak_boolean_t hasLastModUSecs();
    riak_uint32_t  getLastModUSecs();
    riak_boolean_t hasDeleted();
    riak_boolean_t getDeleted();
  	
  	riak_int32_t   getNLinks();
    //riak_link    **links;

    riak_int32_t   getNUserMeta();
    //riak_pair    **usermeta;
    riak_int32_t   getNIndexs();
    //riak_pair    **indexes;

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