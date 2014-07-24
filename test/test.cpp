#include <QCoreApplication>
#include "../PluginLoader.hpp"
#include <QDir>

int
main (int argc, char *argv[])
{
  QCoreApplication app(argc,argv);
  subway::dubway::PluginLoader pl((app.applicationDirPath()+"/plugin.so").toLocal8Bit());
  QObject *qo = pl.instance ("A");
  QMetaObject::invokeMethod (qo, "testa");
  return app.exec();
}
