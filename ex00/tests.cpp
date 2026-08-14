#define CATCH_CONFIG_MAIN
#include "Inventory.hpp"
#include "catch_amalgamated.hpp"

//Cycle 1 (1 assertion)
TEST_CASE("Adding an items raises the count", "[inventory]") {
    Inventory inv;
    inv.add("Sword");
    CHECK(inv.count() == 1);
}
//Cycle 2 (2 assertions)
TEST_CASE("has() finds an added item and rejects a missing one", "[inventory]") {
    Inventory inv;
    inv.add("Shield");
    CHECK(inv.has("Shield")== true);
    CHECK(inv.has("Sword")== false);
}/*
//Cycle 3 (2 assertions)
TEST_CASE("removing an item drops the count and has() stops finding it", "[inventory]") {
    Inventory inv;
    inv.add("Shield");
    CHECK(inv.remove("Shield")== true);
    CHECK(inv.has("Shield") == false);
}
//Cycle 4 (2 assertions)
TEST_CASE("removing a missing item is a no-op: count unchanged, other items untouched", "[inventory]") {
    Inventory inv;
    inv.add("Sword");
    CHECK(inv.remove("Shield")== false);
    CHECK(inv.count() == 1);
}*/