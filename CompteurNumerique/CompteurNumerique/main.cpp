#include "mainapplication.hpp"
#include "trace.hpp"
#include "Parameters/parametersManagers.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(Trace::get_instance()==NULL) { Trace::init(3); }
    if(ParametersManagers::get_instance()==NULL) { ParametersManagers::init(); }
    if(MainApplication::get_instance()==NULL) { MainApplication::init(); }


    return a.exec();
}
