#include "./include/RiakBucket.h"
#include "./include/RiakClient.h"
#include "./include/RiakGetResponse.h"

RiakBucket::RiakBucket(RiakClient* client, const char* bucket_type, const char* bucket_name)
                        : client(client), bucket_type(bucket_type), bucket_name(bucket_name) {
}

RiakBucket::~RiakBucket() {
}

RiakGetResponse* RiakBucket::get(const char* key) {
    riak_binary *bucket_bin   = riak_binary_copy_from_string(client->_raw_config(), bucket_name);
    riak_binary *key_bin      = riak_binary_copy_from_string(client->_raw_config(), key);


    // allocate a struct to set GET options, specifically
    // to set the basic_quorum & r options
    riak_get_options *get_options = riak_get_options_new(client->_raw_config());

    // freed in ~RiakGetResponse
    riak_get_response *get_response = NULL;
    riak_error err = riak_get(client->getNextConnection()->raw_conn, bucket_bin, key_bin, get_options, &get_response);
    RiakGetResponse* gr = new RiakGetResponse(client, get_response);
    
    // TODO: cache bucket_bin 
    riak_binary_free(client->_raw_config(), &bucket_bin);
    riak_binary_free(client->_raw_config(), &key_bin);
    riak_get_options_free(client->_raw_config(), &get_options);
    return gr;
    
}