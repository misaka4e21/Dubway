#include <QCoreApplication>
#include "../PluginLoader.hpp"
#include <QDir>

int
main (int argc, char *argv[])
{
  QCoreApplication app(argc,argv);
  subway::dubway::PluginLoader pl(QDir::current().filePath("plugin").toLocal8Bit());
  QObject *qo = pl.instance ("A");
  return app.exec();
}
