#include "./include/RiakObject.h"
#include "./include/RiakClient.h"
#include "./include/RiakConfig.h"
#include "./include/RiakBinary.h"

#include "../internal/riak_object-internal.h"

RiakObject::RiakObject(RiakClient* client, riak_object* obj) : client(client), obj(obj) {
    bucket = new RiakBinary(client->getRiakConfig(), obj->bucket);
    value = new RiakBinary(client->getRiakConfig(), obj->value);
    if(obj->has_key) {
    	key = new RiakBinary(client->getRiakConfig(), obj->key);
    }
    
    if(obj->has_charset) {
 	   charset = new RiakBinary(client->getRiakConfig(), obj->charset);
	}
    if(obj->has_content_type) {
    	content_type = new RiakBinary(client->getRiakConfig(), obj->content_type);
    }
    if(obj->has_content_encoding) {
    	encoding = new RiakBinary(client->getRiakConfig(), obj->encoding);
    }
    if(obj->has_vtag) {
    	vtag = new RiakBinary(client->getRiakConfig(), obj->vtag);
	}
}

RiakObject::~RiakObject() {
	std::cout << "FREEING RIAK OBJECT" << std::endl;
    riak_object_free(client->_raw_config(), &obj);
 
	if(bucket) delete(bucket);
    if(value) delete(value);
    if(key) delete(key);
    if(value) delete(value);
    if(charset) delete(charset);
    if(content_type) delete(content_type);
    if(encoding) delete(encoding);
    if(vtag) delete(vtag);
}


RiakBinary* RiakObject::getValue() {
    return value;
}

RiakBinary* RiakObject::getBucket() {
	return bucket;
}

riak_boolean_t  RiakObject::hasKey() {
	return obj->has_key;
}
RiakBinary* RiakObject::getKey() {
	return key;
}

riak_boolean_t RiakObject::hasCharset() {
	return obj->has_charset;
}

RiakBinary* RiakObject::getCharset() {
	return charset;
}

riak_boolean_t RiakObject::hasContentType() {
	return obj->has_content_type;
}

RiakBinary* RiakObject::getContentType() {
	return content_type;
}

riak_boolean_t RiakObject::hasEncoding() {
	return obj->has_content_encoding;
}

RiakBinary* RiakObject::getEncoding() {
	return encoding;
}

riak_boolean_t  RiakObject::hasVTag() {
	return obj->has_vtag;
}

RiakBinary* RiakObject::VTag() {
	return vtag;
}

riak_boolean_t RiakObject::hasLastMod() {
	return obj->has_last_mod;
}

riak_uint32_t  RiakObject::getLastMod() {
	return obj->last_mod;
}

riak_boolean_t RiakObject::hasLastModUSecs() {
	return obj->has_last_mod_usecs;
}

riak_uint32_t  RiakObject::getLastModUSecs() {
	return obj->last_mod_usecs;
}

riak_boolean_t RiakObject::hasDeleted() {
	return obj->has_deleted;
}

riak_boolean_t RiakObject::getDeleted() {
	return obj->deleted;
}

riak_int32_t   RiakObject::getNLinks() {
	return obj->n_links;
}

riak_int32_t   RiakObject::getNUserMeta() {
	return obj->n_usermeta;
}

riak_int32_t   RiakObject::getNIndexs() {
	return obj->n_indexes;
}
