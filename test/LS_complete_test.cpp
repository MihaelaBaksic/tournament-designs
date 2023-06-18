#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../src/designs/latin_square.h"

#include <memory>


using namespace CPPUNIT_NS;


class LSCompleteTest: public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(LSCompleteTest);

    CPPUNIT_TEST(test3);
    CPPUNIT_TEST(test6);
    CPPUNIT_TEST(test9);
    CPPUNIT_TEST(test20);
    CPPUNIT_TEST(test35);
    CPPUNIT_TEST(test100);
    CPPUNIT_TEST(test135);
    CPPUNIT_TEST(test1000);
    CPPUNIT_TEST(test1001);


    CPPUNIT_TEST_SUITE_END();

    public:

        void test3()
        {
            int n = 3;

            try{
                std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, true));
                bool validation_result = d->validate_latin_square(true);

                CPPUNIT_ASSERT(validation_result == false);
            }
            catch(const std::invalid_argument& e)
            {
                CPPUNIT_ASSERT_ASSERTION_PASS();
            }
        }

        void test6()
        {
            int n = 6;
            std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, true));
            bool validation_result = d->validate_latin_square(true);

            CPPUNIT_ASSERT(validation_result == true);    
        }

        void test9()
        {
            int n = 9;
            
            try{
                std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, true));
                bool validation_result = d->validate_latin_square(true);

                CPPUNIT_ASSERT(validation_result == false);
            }
            catch(const std::invalid_argument& e)
            {
                CPPUNIT_ASSERT_ASSERTION_PASS();
            }  
        }

        void test20()
        {
            int n = 20;
            std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, true));
            bool validation_result = d->validate_latin_square(true);

            CPPUNIT_ASSERT(validation_result == true);    
        }

        void test35()
        {
            int n = 35;
            try{
                std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, true));
                bool validation_result = d->validate_latin_square(true);

                CPPUNIT_ASSERT(validation_result == false);
            }
            catch(const std::invalid_argument& e)
            {
                CPPUNIT_ASSERT_ASSERTION_PASS();
            }    
        }

        void test100()
        {
            int n = 100;
            std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, true));
            bool validation_result = d->validate_latin_square(true);

            CPPUNIT_ASSERT(validation_result == true);    
        }


        void test135()
        {
            int n = 135;
            try{
                std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, true));
                bool validation_result = d->validate_latin_square(true);

                CPPUNIT_ASSERT(validation_result == false);
            }
            catch(const std::invalid_argument& e)
            {
                CPPUNIT_ASSERT_ASSERTION_PASS();
            }   
        }

        void test1000()
        {
            int n = 1000;
            std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, true));
            bool validation_result = d->validate_latin_square(true);

            CPPUNIT_ASSERT(validation_result == true);    
        }

        void test1001()
        {
            int n = 1001;
            try{
                std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, true));
                bool validation_result = d->validate_latin_square(true);

                CPPUNIT_ASSERT(validation_result == false);
            }
            catch(const std::invalid_argument& e)
            {
                CPPUNIT_ASSERT_ASSERTION_PASS();
            }
        }

        
};