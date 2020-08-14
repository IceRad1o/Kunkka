#ifndef RANET_EVENTLOOP_H
#define RANET_EVENTLOOP_H
namespace ranet
{
namespace net
{

class Eventloop
{
public:
    Eventloop();
    ~Eventloop();

    void loop();

    void assertInloopThread()
    {

    }
private:

};
}
}



#endif //RANET_EVENTLOOP_H
