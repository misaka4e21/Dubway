#ifndef __DUBWAY_GLOBAL_HPP__
#define __DUBWAY_GLOBAL_HPP__

#include <QVariant>


#define DUBWAY_NS_BEGIN \
 namespace subway {\
    namespace dubway {

#define DUBWAY_NS_END }}

DUBWAY_NS_BEGIN

typedef QObject *(*CreatorFPointer)();

DUBWAY_NS_END


#endif // __DUBWAY_GLOBAL_HPP__
