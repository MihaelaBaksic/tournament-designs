#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "BTD_test.cpp"

CPPUNIT_TEST_SUITE_REGISTRATION(BTDOddSideTest);

int main(int argc, char* argv[])
{

  CppUnit::TextUi::TestRunner runner;
  CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
  runner.addTest(registry.makeTest());
  runner.run();
  return 0;
  
}