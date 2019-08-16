#include <QtTest>

// add necessary includes here

class array_test : public QObject
{
    Q_OBJECT

public:
    array_test();
    ~array_test();

private slots:
    void test_case1();

};

array_test::array_test()
{

}

array_test::~array_test()
{

}

void array_test::test_case1()
{

}

QTEST_APPLESS_MAIN(array_test)

#include "tst_array_test.moc"
