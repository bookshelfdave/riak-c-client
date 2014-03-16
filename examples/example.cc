#include "riak.h"
#include "./src/cxx/include/RiakClient.h"
#include "./src/cxx/include/RiakConnection.h"
int main(int argc, char* argv[]) {
    try {
        RiakClient riak;
        riak.connect("localhost", "10017");
        RiakBucket *bucket = riak.fetchBucket("footype","foobucket");
        bucket->get("foo");
        delete(bucket);
    } catch (RiakException e) {
        std::cout << "Connection exception" << std::endl;
    }
}