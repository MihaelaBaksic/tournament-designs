#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../src/designs/latin_square.h"

#include <memory>


using namespace CPPUNIT_NS;


class LSKConstructionTest: public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(LSKConstructionTest);

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
            int k = 2;
            std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, k));
            bool validation_result = d->validate_latin_square();

            CPPUNIT_ASSERT(validation_result == true);    
        }

        void test6()
        {
            int n = 6;
            int k = 2;
            std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, k));
            bool validation_result = d->validate_latin_square();

            CPPUNIT_ASSERT(validation_result == false);    
        }

        void test9()
        {
            int n = 9;
            int k = 5;
            std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, k));
            bool validation_result = d->validate_latin_square();

            CPPUNIT_ASSERT(validation_result == true);    
        }

        void test20()
        {
            int n = 20;
            int k = 2;
            std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, k));
            bool validation_result = d->validate_latin_square();

            CPPUNIT_ASSERT(validation_result == false);    
        }

        void test35()
        {
            int n = 35;
            int k = 11;
            std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, k));
            bool validation_result = d->validate_latin_square();

            CPPUNIT_ASSERT(validation_result == true);      
        }

        void test100()
        {
            int n = 100;
            int k = 2;
            std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, k));
            bool validation_result = d->validate_latin_square();

            CPPUNIT_ASSERT(validation_result == false);    
        }


        void test135()
        {
            int n = 135;
            int k = 1;
            std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, k));
            bool validation_result = d->validate_latin_square();

            CPPUNIT_ASSERT(validation_result == true);    
        }

        void test1000()
        {
            int n = 1000;
            int k = 2;
            std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, k));
            bool validation_result = d->validate_latin_square();

            CPPUNIT_ASSERT(validation_result == false);    
        }

        void test1001()
        {
            int n = 1001;
            int k = 1000;
            std::unique_ptr<design::LatinSquare> d = std::unique_ptr<design::LatinSquare>(new design::LatinSquare(n, k));
            bool validation_result = d->validate_latin_square();

            CPPUNIT_ASSERT(validation_result == true);   
        }

        
};