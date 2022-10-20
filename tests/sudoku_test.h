#ifndef TEST_TICTACTOE_H
#define TEST_TICTACTOE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "sudoku.hpp"

extern "C" {
#include "sudoku.hpp"
}

TEST(player_win)
{
    std::string output_text = "Вы не допустили ни одной ошибки, игра выиграна";

    testing::internal::CaptureStdout();

    int masking_cells = 0;

    handler(masking_cells);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(generator)
{
    int board1[9][9];
    int board2[9][9];
    start(10, 0, board1);
    start(10, 0, board2);

    EXPECT_NE(board1, board2);
}

TEST(rowError)
{
    int board[9][9];
    start(0, 0, board);
    board[0][1] = 1;

    EXPECT_EQ(row_error(board), true);
}

TEST(collumnError)
{
    int board[9][9];
    start(0, 0, board);
    board[1][0] = 1;

    EXPECT_EQ(line_error(board), true);
}

TEST(blockError)
{
    int board[9][9];
    start(0, 0, board);
    board[1][1] = 1;

    EXPECT_EQ(block_error(board), true);
}


#endif
