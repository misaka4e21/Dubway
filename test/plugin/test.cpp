#include <QObject>
#include "../../Plugin.hpp"
#include <iostream>
using namespace subway::dubway;

class A : public QObject
{
  Q_OBJECT
public slots:
  void testa ()
  {
    std::cout<< "test"<<std::endl;
  }
};

DUBWAY_PLUGIN_EXPORT_CLASS(A)
