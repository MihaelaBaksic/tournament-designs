#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "BTD_test.cpp"
#include "LS_rotation_test.cpp"
#include "LS_complete_test.cpp"
#include "LS_kconstruction_test.cpp"
#include "BipartiteTD_test.cpp"
#include "CarryOverBipartiteTD_test.cpp"
#include "PairMOLS_test.cpp"

CPPUNIT_TEST_SUITE_REGISTRATION(BTDOddSideTest);
CPPUNIT_TEST_SUITE_REGISTRATION(LSRotationTest);
CPPUNIT_TEST_SUITE_REGISTRATION(LSCompleteTest);
CPPUNIT_TEST_SUITE_REGISTRATION(LSKConstructionTest);
CPPUNIT_TEST_SUITE_REGISTRATION(BipartiteTDTest);
CPPUNIT_TEST_SUITE_REGISTRATION(COBipartiteTDTest);
CPPUNIT_TEST_SUITE_REGISTRATION(PairMOLSTest);



int main(int argc, char* argv[])
{

  CppUnit::TextUi::TestRunner runner;
  CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
  runner.addTest(registry.makeTest());
  runner.run();
  return 0;
  
}