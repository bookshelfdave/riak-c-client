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

RiakBinary* RiakObject::getKey() {
	return key;
}

RiakBinary* RiakObject::getCharset() {
	return charset;
}

RiakBinary* RiakObject::getContentType() {
	return content_type;
}

RiakBinary* RiakObject::getEncoding() {
	return encoding;
}

RiakBinary* RiakObject::VTag() {
	return vtag;
}