#include <catch.h>

#include <add.h>

TEST_CASE("add", "[add]") {

    CHECK(add::add(1, 2) == 3);
    CHECK(add::add(3, 4) == 7);
}
