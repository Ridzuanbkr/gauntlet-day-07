#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "Dice.hpp"
#include "RandomSource.hpp"

class FakeRandom : public RandomSource {
    private:
        int fixed_value_;

    public:
        explicit FakeRandom(int value) : fixed_value_(value) {}

        //Unnamed parameter toprevent -Wunused-parameter warning
        int next(int) override {
            return fixed_value_;
        }
};

TEST_CASE("roll() maps rng value 0 to face 1", "[Dice]") {
    FakeRandom fakeRng(0);
    Dice dice(fakeRng);

    REQUIRE(dice.roll() == 1);
}

TEST_CASE("roll() maps rng value 5 to face 6", "[Dice]") {
    FakeRandom fakeRng(5);
    Dice dice(fakeRng);

    REQUIRE(dice.roll() == 6);
}