#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../Tests/tests.h"

/******************************************

VEC2 TESTS

******************************************/

TEST_CASE("Test Empty Initialization") {
    Vec2 vector;

    CHECK(vector.x == 0.0f);
    CHECK(vector.y == 0.0f);
}

TEST_CASE("Test Value Initialization") {

    SUBCASE("Zero Values"){
        Vec2 myVector(0.0f, 0.0f);

        CHECK(myVector.x == 0.0f);
        CHECK(myVector.y == 0.0f);
    }

    SUBCASE("Nonzero Values"){
        Vec2 myVector(3.0f, 5.0f);

        CHECK(myVector.x == 3.0f);
        CHECK(myVector.y == 5.0f);
    }

    SUBCASE("One Zero Value"){
        Vec2 myVector(0.0f, 5.0f);

        CHECK(myVector.x == 0.0f);
        CHECK(myVector.y == 5.0f);
    }

    SUBCASE("Negative Values"){
        Vec2 myVector(-3.0f, -5.0f);

        CHECK(myVector.x == -3.0f);
        CHECK(myVector.y == -5.0f);
    }

    SUBCASE("Very Large Values"){
        Vec2 myVector(pow(3.0f, 10.0f), pow(5.0f, 10.0f));

        CHECK(myVector.x == doctest::Approx(pow(3.0f, 10.0f)));
        CHECK(myVector.y == doctest::Approx(pow(5.0f, 10.0f)));
    }

    SUBCASE("Very Small Values"){
        Vec2 myVector(pow(3.0f, -10.0f), pow(5.0f, -10.0f));

        CHECK(myVector.x == doctest::Approx(pow(3.0f, -10.0f)));
        CHECK(myVector.y == doctest::Approx(pow(5.0f, -10.0f)));
    }
}

TEST_CASE("Test Binary Arithmetic Operations") {

    Vec2 vectorOne(3.0f, 5.0f);
    Vec2 vectorTwo(6.0f, 10.0f);
    Vec2 emptyVector;

    REQUIRE(vectorOne.x == 3.0f);
    REQUIRE(vectorOne.y == 5.0f);
    REQUIRE(vectorTwo.x == 6.0f);
    REQUIRE(vectorTwo.y == 10.0f);
    REQUIRE(emptyVector.x == 0.0f);
    REQUIRE(emptyVector.y == 0.0f);

    SUBCASE("Test Adding Vectors") {
        Vec2 tempVector = vectorOne + vectorTwo;
        
        CHECK(tempVector.x == 9.0f);
        CHECK(tempVector.y == 15.0f);
    }

    SUBCASE("Test Subtracting Vectors") {
        Vec2 tempVector = vectorOne - vectorTwo;
        
        CHECK(tempVector.x == -3.0f);
        CHECK(tempVector.y == -5.0f);
    }

    SUBCASE("Test Multiplying Vector By Scalar") {
        Vec2 tempVector = vectorOne * 3.0f;
        
        CHECK(tempVector.x == 9.0f);
        CHECK(tempVector.y == 15.0f);
    }

    SUBCASE("Test Multiplying Vectors Element-Wise") {
        Vec2 tempVector = vectorOne * vectorTwo;
        
        CHECK(tempVector.x == 18.0f);
        CHECK(tempVector.y == 50.0f);
    }

    SUBCASE("Test Dividing Vector By Scalar") {
        Vec2 tempVector = vectorOne / 3.0f;
        
        CHECK(tempVector.x == 1.0f);
        CHECK(tempVector.y == doctest::Approx((5.0f/3.0f)));
    }

    SUBCASE("Test Dividing Vectors Element-Wise") {
        Vec2 tempVector = vectorOne / vectorTwo;
        
        CHECK(tempVector.x == (3.0f/6.0f));
        CHECK(tempVector.y == (5.0f/10.0f));
    }
}

TEST_CASE("Test Unary Arithmetic Operations") {

    Vec2 vector(3.0f, 5.0f);
    Vec2 originalVector = vector;

    SUBCASE("Test Prefix Increment") {
        ++vector;
        CHECK(vector.x == 4.0f);
        CHECK(vector.y == 6.0f);

        ++vector, ++vector;

        CHECK(vector.x == 6.0f);
        CHECK(vector.y == 8.0f);
    }

    SUBCASE("Test Postfix Increment") {
        Vec2 returnValue = vector++;

        CHECK(returnValue.x == originalVector.x);
        CHECK(returnValue.y == originalVector.y);
    }

    SUBCASE("Test Prefix Decrement") {
        --vector;
        CHECK(vector.x == 2.0f);
        CHECK(vector.y == 4.0f);

        --vector, --vector;

        CHECK(vector.x == 0.0f);
        CHECK(vector.y == 2.0f);
    }

    SUBCASE("Test Postfix Decrement") {
        Vec2 returnValue = vector--;

        CHECK(returnValue.x == originalVector.x);
        CHECK(returnValue.y == originalVector.y);
    }
}

TEST_CASE("Test Assignment Operations") {

}

TEST_CASE("Test Relational Operations") {

}

TEST_CASE("Test Utility Methods") {
    
}