#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../src/designs/BTD.h"

#include <memory>


using namespace CPPUNIT_NS;

class BTDOddSideTest: public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(BTDOddSideTest);

    CPPUNIT_TEST(test3);
    CPPUNIT_TEST(test9);
    CPPUNIT_TEST(test35);
    CPPUNIT_TEST(test135);

    CPPUNIT_TEST_SUITE_END();

    public:

        void test3()
        {
            int n = 3;
            std::unique_ptr<design::TournamentDesign> d = std::unique_ptr<design::TournamentDesign>(new design::BalancedTournamentDesign(n));
            bool validation_result = d->validate_design();

            CPPUNIT_ASSERT(validation_result == true);    
        }

        void test9()
        {
            int n = 9;
            std::unique_ptr<design::TournamentDesign> d = std::unique_ptr<design::TournamentDesign>(new design::BalancedTournamentDesign(n));
            bool validation_result = d->validate_design();

            CPPUNIT_ASSERT(validation_result == true);    
        }

        void test35()
        {
            int n = 35;
            std::unique_ptr<design::TournamentDesign> d = std::unique_ptr<design::TournamentDesign>(new design::BalancedTournamentDesign(n));
            bool validation_result = d->validate_design();

            CPPUNIT_ASSERT(validation_result == true);    
        }


        void test135()
        {
            int n = 135;
            std::unique_ptr<design::TournamentDesign> d = std::unique_ptr<design::TournamentDesign>(new design::BalancedTournamentDesign(n));
            bool validation_result = d->validate_design();

            CPPUNIT_ASSERT(validation_result == true);  
        }

        
};