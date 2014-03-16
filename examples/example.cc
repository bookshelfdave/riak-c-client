#include "riak.h"
#include "./src/cxx/include/RiakClient.h"
#include "./src/cxx/include/RiakConnection.h"
#include "./src/cxx/include/RiakGetResponse.h"
#include "./src/cxx/include/RiakBinary.h"
#include "./src/cxx/include/RiakObject.h"

int main(int argc, char* argv[]) {
    try {
        RiakClient riak;
        riak.connect("localhost", "10017");
        RiakBucket *bucket = riak.fetchBucket("footype","foo");
        RiakGetResponse* resp = bucket->get("foo");
        std::cout << "Data:" << resp->getObject(0)->getValue()->getData() << std::endl;
        delete(bucket);

    } catch (RiakException e) {
        std::cout << "Connection exception" << std::endl;
    }
}