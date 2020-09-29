#ifndef RANET_BUFFER_H
#define RANET_BUFFER_H

#include <string>
class Buffer
{
public:
    Buffer() = default;
    ~Buffer() = default;
    const char *peek();
    int readableBytes();
    void retrive(int len);
    void append(const std::string& buf);
    std::string retrieveAllasString();
    std::string retrieveAsString(size_t len);
private:
    std::string _buf;
};

#endif //RANET_BUFFER_H
