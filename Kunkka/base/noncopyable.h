

#ifndef RANET_NONCOPYABLE_H
#define RANET_NONCOPYABLE_H
namespace ranet
{
class noncopyable
{
public:
    noncopyable(const noncopyable&) = delete;
    void operator=(const noncopyable&) = delete;

protected:

};
}

#endif //RANET_NONCOPYABLE_H
