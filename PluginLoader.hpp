#ifndef __DBW_PLUGIN_LOADER_HPP__
#define __DBW_PLUGIN_LOADER_HPP__

#include "dubway-global.hpp"
#include <QScopedPointer>
#include <QLibrary>
#include <QString>
#include <QDebug>

DUBWAY_NS_BEGIN

class PluginLoader : public QObject
{
  Q_OBJECT
public:
  PluginLoader (QObject * parent = 0);
  PluginLoader (const QString & fileName, QObject * parent = 0)
   : QObject(parent), m_lib(new QLibrary (fileName)), m_loaded(true)
  {
    m_lib->setLoadHints (QLibrary::ResolveAllSymbolsHint);
    m_lib->load ();
  }

  PluginLoader (QLibrary * lib, QObject * parent = 0)
   : QObject(parent), m_lib(lib),m_loaded(true)
  {
    m_lib->setLoadHints (QLibrary::ResolveAllSymbolsHint);
    m_lib->load ();
  }

  void load ()
  {
    if (m_loaded)
      return;
    else
      // TODO: finish the loading process
      return;
  }

  QObject *
  instance (const char * className)
  {
    QString fn ("__dbw_plugin_export_create_");
    fn+=className;
    CreatorFPointer fp
      = (CreatorFPointer)
          m_lib->resolve (fn.toStdString ().c_str());
    if (fp != NULL)
      return fp ();
    else
      {
        qDebug() << m_lib->errorString();
        return NULL;
      }
  }

private:
  QScopedPointer<QLibrary> m_lib;
  bool m_loaded;
};

DUBWAY_NS_END
#endif
