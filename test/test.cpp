# include <gtest/gtest.h>
# include "unit_creation_test.h"
# include "unit_structure_test.h"
# include "unit_behavior_test.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}