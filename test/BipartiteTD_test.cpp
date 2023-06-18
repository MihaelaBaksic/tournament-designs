#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../src/designs/BipartiteTD.h"

#include <memory>


using namespace CPPUNIT_NS;

class BipartiteTDTest: public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(BipartiteTDTest);

    CPPUNIT_TEST(test3);
    CPPUNIT_TEST(test9);
    CPPUNIT_TEST(test35);
    CPPUNIT_TEST(test135);
    CPPUNIT_TEST(test1001);


    CPPUNIT_TEST_SUITE_END();

    public:


        void test3()
        {
            int n = 3;
            std::unique_ptr<design::BipartiteTournamentDesign> d = std::unique_ptr<design::BipartiteTournamentDesign>(new design::BipartiteTournamentDesign(n));
            bool validation_result = d->validate_design();

            CPPUNIT_ASSERT(validation_result == true);    
        }

        void test9()
        {
            int n = 9;
            std::unique_ptr<design::BipartiteTournamentDesign> d = std::unique_ptr<design::BipartiteTournamentDesign>(new design::BipartiteTournamentDesign(n));
            bool validation_result = d->validate_design();

            CPPUNIT_ASSERT(validation_result == true);    
        }

        void test35()
        {
            int n = 35;
            std::unique_ptr<design::BipartiteTournamentDesign> d = std::unique_ptr<design::BipartiteTournamentDesign>(new design::BipartiteTournamentDesign(n));
            bool validation_result = d->validate_design();

            CPPUNIT_ASSERT(validation_result == true);    
        }


        void test135()
        {
            int n = 135;
            std::unique_ptr<design::BipartiteTournamentDesign> d = std::unique_ptr<design::BipartiteTournamentDesign>(new design::BipartiteTournamentDesign(n));
            bool validation_result = d->validate_design();

            CPPUNIT_ASSERT(validation_result == true);  
        }

        void test1001()
        {
            int n = 1001;
            std::unique_ptr<design::BipartiteTournamentDesign> d = std::unique_ptr<design::BipartiteTournamentDesign>(new design::BipartiteTournamentDesign(n));
            bool validation_result = d->validate_design();

            CPPUNIT_ASSERT(validation_result == true);  
        }

        
};