#include <QTest>

#include "testrunner.h"

//#include "InfluxMeasurement_tst.h"
//#include "tst_MyTestCase.h"

#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
#include <QtGui/QGuiApplication>


int main(int argc, char *argv[])
{
#if 0
    InfluxMeasurement_tst test1;
    MyTestCase test2;
//    BarTests test3;

    QTEST_SET_MAIN_SOURCE_PATH


    int status = 0;

    runTestsAppless<InfluxMeasurement_tst>(argc, argv, &status);
    runTestsAppless<MyTestCase>(argc, argv, &status);

    return status;
#else
    QGuiApplication app(argc, argv);
    return Catch::Session().run(argc, argv);
#endif
}
