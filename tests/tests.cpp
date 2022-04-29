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
TEST(Gravity, TestJumpKey) {
	GTEST_ASSERT_EQ(CRAFT_KEY_JUMP, GLFW_KEY_SPACE);
}


int main(int argc, char* argv[])
{

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}