#include "./include/RiakClient.h"

RiakClient::RiakClient() {
    cfg = new RiakConfig();
}


RiakClient::~RiakClient() {
    // TODO
    //std::vector<RiakConnection>::iterator it;
    //connections.erase(it.begin(), it.end());
    delete(cfg);

}

RiakBucket* RiakClient::fetchBucket(const char* bucket_type, const char* bucket_name) {
    std::cout << "Fetched bucket " << bucket_type << ":" << bucket_name << std::endl;
    return new RiakBucket(this, bucket_type, bucket_name);
}


void RiakClient::connect(const char* host, const char* port) {
    std::cout << "Connecting to " << host << ":" << port << std::endl;
    RiakConnection *c = new RiakConnection(cfg, host, port);
    connections.push_back(c);
}

riak_config* RiakClient::_raw_config() {
    return cfg->raw_cfg;
}


RiakConnection* RiakClient::getNextConnection() {
    // TODO
    return this->connections[0];
}

RiakConfig* RiakClient::getRiakConfig() {
    return cfg;
}