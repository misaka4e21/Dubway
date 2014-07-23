#ifndef __DBW_PLUGIN_HPP__
#define __DBW_PLUGIN_HPP__
#include "dubway-global.hpp"
#include <QList>
#include <QVariant>
#include <QMetaObject>

DUBWAY_NS_BEGIN

static QList<QMetaObject> _all_static_metaobjects;

template <typename T>
class ClassWrapper
{
public:
  ClassWrapper ()
  {
    _all_static_metaobjects << T::staticMetaObject;
  }

  T *
  create ()
  {
    return new T;
  }
};

DUBWAY_NS_END

/**
  * DUBWAY_GLOBAL_CLASSWRAPPER(CLASS) creates a global
  * ClassWrapper<CLASS>
  */
#define DUBWAY_GLOBAL_CLASSWRAPPER(CLASS) \
  ClassWrapper<CLASS> __dbw_classwrapper_##CLASS;

/**
  * DUBWAY_PLUGIN_EXPORT_CREATE(CLASS) defines a function
  * that returns a new instance of CLASS through
  * ClassWrapper<CLASS>::create();
  */
#define DUBWAY_PLUGIN_EXPORT_CREATE(CLASS)\
  extern "C"  QObject *\
  __dbw_plugin_export_create_##CLASS () \
  { \
    return __dbw_classwrapper_##CLASS.create();\
  } \

#define DUBWAY_PLUGIN_EXPORT_CLASS(CLASS)\
  DUBWAY_GLOBAL_CLASSWRAPPER(CLASS)\
  DUBWAY_PLUGIN_EXPORT_CREATE(CLASS)


#endif
