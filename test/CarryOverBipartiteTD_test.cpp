#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../src/designs/CarryOverBipartiteTD.h"

#include <memory>


using namespace CPPUNIT_NS;

class COBipartiteTDTest: public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(COBipartiteTDTest);

    CPPUNIT_TEST(test4);
    CPPUNIT_TEST(test12);
    CPPUNIT_TEST(test36);
    CPPUNIT_TEST(test136);
    CPPUNIT_TEST(test1000);


    CPPUNIT_TEST_SUITE_END();

    public:

        void test4()
        {
            int n = 4;
            std::unique_ptr<design::COBipartiteTournamentDesign> d = std::unique_ptr<design::COBipartiteTournamentDesign>(new design::COBipartiteTournamentDesign(n));
            bool validation_result = d->validate_design();

            CPPUNIT_ASSERT(validation_result == true);    
        }

        void test12()
        {
            int n = 12;
            std::unique_ptr<design::COBipartiteTournamentDesign> d = std::unique_ptr<design::COBipartiteTournamentDesign>(new design::COBipartiteTournamentDesign(n));
            bool validation_result = d->validate_design();

            CPPUNIT_ASSERT(validation_result == true);    
        }

        void test36()
        {
            int n = 36;
            std::unique_ptr<design::COBipartiteTournamentDesign> d = std::unique_ptr<design::COBipartiteTournamentDesign>(new design::COBipartiteTournamentDesign(n));
            bool validation_result = d->validate_design();

            CPPUNIT_ASSERT(validation_result == true);    
        }


        void test136()
        {
            int n = 136;
            std::unique_ptr<design::COBipartiteTournamentDesign> d = std::unique_ptr<design::COBipartiteTournamentDesign>(new design::COBipartiteTournamentDesign(n));
            bool validation_result = d->validate_design();

            CPPUNIT_ASSERT(validation_result == true);  
        }

        void test1000()
        {
            int n = 1000;
            std::unique_ptr<design::COBipartiteTournamentDesign> d = std::unique_ptr<design::COBipartiteTournamentDesign>(new design::COBipartiteTournamentDesign(n));
            bool validation_result = d->validate_design();

            CPPUNIT_ASSERT(validation_result == true);  
        }

        
};