#include <gtest/gtest.h>

//includes from main.c
#include <GLFW/glfw3.h>
#include <gl/glew.h>
#include <string.h>
#include <curl/curl.h>
#include "config.h" //for key presses

//Example Test
TEST(Assert, empty) { GTEST_ASSERT_EQ(true, true); }

//[issue] (https://github.com/rhartlage10/CtrlAltElite-Craft/issues/9)
// Tests to see if our jump key is still space
TEST(Gravity, TestJumpKey) {
	GTEST_ASSERT_EQ(CRAFT_KEY_JUMP, GLFW_KEY_SPACE);
}

//[issue] (https://github.com/rhartlage10/CtrlAltElite-Craft/issues/26)
// Tests to see if our custom sprint key is the Q press
TEST(Sprint, TestSprintKey) {
	GTEST_ASSERT_EQ(CRAFT_KEY_SPRINT, 'Q');
}

int main(int argc, char* argv[])
{

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}