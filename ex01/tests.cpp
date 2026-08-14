#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "Inventory.hpp"

struct InventoryFixture {
    Inventory inv;

    InventoryFixture() {
        inv.add("potion");
        inv.add("sword");
    }
};

//1. Adding an item raises the count (shifts form 0->1 in ex00 to 2->3 in ex01)
TEST_CASE_METHOD(InventoryFixture, "adding an item raises the count", "[Inventory]") {
    inv.add("shield");
    CHECK(inv.count() == 3);
}

//2. has() finds an added item and rejects a missing one ("elixir")
TEST_CASE_METHOD(InventoryFixture, "has() finds an added item and rejects a missing one", "[Inventory]") {
    CHECK(inv.has("potion") == true);
    CHECK(inv.has("elixir") == false);
}

//3. Removing an item drops the count
TEST_CASE_METHOD(InventoryFixture, "removing an item drops the count", "[Inventory]") {
    CHECK(inv.remove("potion") == true);
    CHECK(inv.has("potion") == false);
}

//4. Removing a missing item ("elixir") is no-op
TEST_CASE_METHOD(InventoryFixture, "removing a missing item is no-op", "[Inventory]") {
    CHECK(inv.remove("elixir") == false);
    CHECK(inv.count() == 2);
}