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
    Vec2 originalVector(3.0f, 5.0f);

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

        CHECK(returnValue.x == 3.0f);
        CHECK(returnValue.y == 5.0f); // return values same as in original vector
        CHECK(vector.x == 4.0f);
        CHECK(vector.y == 6.0f);

        returnValue = vector++; // increment a secend time

        CHECK(returnValue.x == 4.0f);
        CHECK(returnValue.y == 6.0f); // second postfix increment returns values expected after completion of first increment
        CHECK(vector.x == 5.0f);
        CHECK(vector.y == 7.0f);
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

        CHECK(returnValue.x == 3.0f);
        CHECK(returnValue.y == 5.0f); // return values same as in original vector
        CHECK(vector.x == 2.0f);
        CHECK(vector.y == 4.0f);

        returnValue = vector--; // decrement a secend time

        CHECK(returnValue.x == 2.0f);
        CHECK(returnValue.y == 4.0f); // second postfix decrement returns values expected after completion of first increment
        CHECK(vector.x == 1.0f);
        CHECK(vector.y == 3.0f);
    }
}

TEST_CASE("Test Assignment Operations") {
    Vec2 vectorOne(3.0f, 5.0f);
    Vec2 vectorTwo(6.0f, 10.0f);

    SUBCASE("Test += Operator") {
        vectorOne += vectorTwo;

        CHECK(vectorOne.x == 9.0f);
        CHECK(vectorOne.y == 15.0f);
    }

    SUBCASE("Test -= Operator") {
        vectorOne -= vectorTwo;

        CHECK(vectorOne.x == -3.0f);
        CHECK(vectorOne.y == -5.0f);
    }

    SUBCASE("Test *= Scalar Operator") {
        vectorOne *= 2.0;

        CHECK(vectorOne.x == 6.0f);
        CHECK(vectorOne.y == 10.0f);
    }

    SUBCASE("Test *= Element-Wise Operator") {
        vectorOne *= vectorTwo;

        CHECK(vectorOne.x == 18.0f);
        CHECK(vectorOne.y == 50.0f);
    }

    SUBCASE("Test /= Scalar Operator") {
        vectorOne /= 2.0;

        CHECK(vectorOne.x == 1.5f);
        CHECK(vectorOne.y == 2.5f);
    }

    SUBCASE("Test /= Element-Wise Operator") {
        vectorOne /= vectorTwo;

        CHECK(vectorOne.x == 0.5f);
        CHECK(vectorOne.y == 0.5f);
    }

    SUBCASE("Test = Operator") {
        vectorOne = vectorTwo;

        CHECK(vectorOne.x == 6.0f);
        CHECK(vectorOne.y == 10.0f);
    }


}

TEST_CASE("Test Relational Operations") {
    Vec2 vectorOne(3.0f, 5.0f);
    Vec2 vectorTwo(3.0f, 5.0f);
    Vec2 emptyVector;

    CHECK(vectorOne == vectorTwo);
    CHECK(vectorOne != emptyVector);
}

TEST_CASE("Test Utility Methods") {
    
}