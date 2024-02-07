#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../Tests/tests.h"

/******************************************

VEC2 TESTS

******************************************/

TEST_CASE("Test Empty Initialization") {
    Vec2 vector;

    CHECK(vector.x == 0.0);
    CHECK(vector.y == 0.0);
}

TEST_CASE("Test Value Initialization") {

    SUBCASE("Zero Values"){
        Vec2 myVector(0.0, 0.0);

        CHECK(myVector.x == 0.0);
        CHECK(myVector.y == 0.0);
    }

    SUBCASE("Nonzero Values"){
        Vec2 myVector(3.0, 5.0);

        CHECK(myVector.x == 3.0);
        CHECK(myVector.y == 5.0);
    }

    SUBCASE("One Zero Value"){
        Vec2 myVector(0.0, 5.0);

        CHECK(myVector.x == 0.0);
        CHECK(myVector.y == 5.0);
    }

    SUBCASE("Negative Values"){
        Vec2 myVector(-3.0, -5.0);

        CHECK(myVector.x == -3.0);
        CHECK(myVector.y == -5.0);
    }

    SUBCASE("Very Large Values"){
        Vec2 myVector(pow(3.0, 10), pow(5.0, 10));

        CHECK(myVector.x == doctest::Approx(pow(3.0, 10)));
        CHECK(myVector.y == doctest::Approx(pow(5.0, 10)));
    }

    SUBCASE("Very Small Values"){
        Vec2 myVector(pow(3.0, -10), pow(5.0, -10));

        CHECK(myVector.x == doctest::Approx(pow(3.0, -10)));
        CHECK(myVector.y == doctest::Approx(pow(5.0, -10)));
    }
}

TEST_CASE("Test Binary Arithmetic Operations") {

    Vec2 vectorOne(3.0, 5.0);
    Vec2 vectorTwo(6.0, 10.0);
    Vec2 emptyVector;

    REQUIRE(vectorOne.x == 3.0);
    REQUIRE(vectorOne.y == 5.0);
    REQUIRE(vectorTwo.x == 6.0);
    REQUIRE(vectorTwo.y == 10.0);
    REQUIRE(emptyVector.x == 0.0);
    REQUIRE(emptyVector.y == 0.0);

    SUBCASE("Test Adding Vectors") {
        Vec2 tempVector = vectorOne + vectorTwo;
        
        CHECK(tempVector.x == 9.0);
        CHECK(tempVector.y == 15.0);
    }

    SUBCASE("Test Subtracting Vectors") {
        Vec2 tempVector = vectorOne - vectorTwo;
        
        CHECK(tempVector.x == -3.0);
        CHECK(tempVector.y == -5.0);
    }

    SUBCASE("Test Multiplying Vector By Scalar") {
        Vec2 tempVector = vectorOne * 3;
        
        CHECK(tempVector.x == 9.0);
        CHECK(tempVector.y == 15.0);
    }

        SUBCASE("Test Multiplying Vectors Element-Wise") {
        Vec2 tempVector = vectorOne * vectorTwo;
        
        CHECK(tempVector.x == 18.0);
        CHECK(tempVector.y == 50.0);
    }

        SUBCASE("Test Dividing Vector By Scalar") {
        Vec2 tempVector = vectorOne / 3;
        
        CHECK(tempVector.x == 1.0);
        CHECK(tempVector.y == doctest::Approx((5.0/3)));
    }

        SUBCASE("Test Dividing Vectors Element-Wise") {
        Vec2 tempVector = vectorOne / vectorTwo;
        
        CHECK(tempVector.x == (3.0/6.0));
        CHECK(tempVector.y == (5.0/10.0));
    }
}

TEST_CASE("Test Unary Arithmetic Operations") {

}

TEST_CASE("Test Assignment Operations") {

}

TEST_CASE("Test Relational Operations") {

}

TEST_CASE("Test Utility Methods") {
    
}