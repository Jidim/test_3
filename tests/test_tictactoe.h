#ifndef TEST_TICTACTOE_H
#define TEST_TICTACTOE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "myfunc.hpp"

/* using namespace testing; */
extern "C" {
#include "myfunc.hpp"
}

TEST(xwin, diagonal)
{
    std::string output_text = "Congratulations! Player with 'X' has won the game!";

    testing::internal::CaptureStdout();

    int select[] = {1,2,5,6,9};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(xwin, horizontal)
{
    std::string output_text = "Congratulations! Player with 'X' has won the game!";

    testing::internal::CaptureStdout();

    int select[]={4,2,6,3,5};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(xwin, vertical)
{
    std::string output_text = "Congratulations! Player with 'X' has won the game!";

    testing::internal::CaptureStdout();

    int select[]={3,5,6,1,9};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(owin, diagonal)
{
    std::string output_text = "Congratulations! Player with 'O' has won the game!";

    testing::internal::CaptureStdout();

    int select[]={3,5,6,1,8,9};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(owin, horizontal)
{
    std::string output_text = "Congratulations! Player with 'O' has won the game!";

    testing::internal::CaptureStdout();

    int select[]= {5,1,9,3,7,8,4,2};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(owin, vertical)
{
    std::string output_text = "Congratulations! Player with 'O' has won the game!";

    testing::internal::CaptureStdout();

    int select[]={2,5,1,3,8,9,7,6};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(extra, draw)
{
    std::string output_text = "GAME DRAW!";

    testing::internal::CaptureStdout();

    int select[]={5,6,8,2,3,7,9,1,4};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(extra, out_pos)
{
    std::string output_text = "Invalid Move";

    testing::internal::CaptureStdout();

    int select[]={10};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(extra, minus_pos)
{
    std::string output_text = "Invalid Move";

    testing::internal::CaptureStdout();

    int select[]={-1};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(extra, game_is_not_finished)
{
    std::string output_text = "Not enough moves to identify the winner!";

    testing::internal::CaptureStdout();

    int select[]={7,6,5};
    int size=sizeof(select)/4;

    tictactoe(select, size);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

#endif
