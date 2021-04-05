#include "c-echo.h"
#include "c-count.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3,test_val));
}
TEST(EchoTest, EmptyString) {
    char* test_val[1]; test_val[0] = "./c-echo";
    EXPECT_EQ("", echo(1,test_val));
}

TEST(CountTest, HelloWorld) {
    std::string test_str = "hello world";
    EXPECT_EQ(2, count(test_str));
}

TEST(CountTest, EmptyString) {
    std::string test_str = "";
    EXPECT_EQ(0, count(test_str));
}

TEST(CountTest, ManySpaces) {
    std::string test_str = "   this   string has     weird   spacing";
    EXPECT_EQ(5, count(test_str));
}

//New Test #1
TEST(EchoTest, Symbols) {
    char* test_val[2]; test_val[1]; test_val[0] = "./c-echo"; test_val[1] = "~!@#$%^&*()_+";
    EXPECT_EQ("~!@#$%^&*()_+", echo(2 ,test_val));
}

//New Test #2
TEST(EchoTest, Newline) {
    char* test_val[2]; test_val[0] = "./c-echo"; test_val[1] = "test\n";
    EXPECT_EQ("test\n", echo(2,test_val));
}

//New Test #3
TEST(EchoTest, Quotes) {
    char* test_val[12]; test_val[0] = "./c-echo"; test_val[1] = "This"; test_val[2] = "is"; test_val[3] = "in"; test_val[4] = "double"; test_val[5] = "quotes,"; test_val[6] = "'and"; test_val[7] = "this"; test_val[8] = "is"; test_val[9] = "in"; test_val[10] = "single"; test_val[11] = "quotes.'";
    EXPECT_EQ("This is in double quotes, 'and this is in single quotes.'", echo(12,test_val));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
