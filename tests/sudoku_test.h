#ifndef TEST_TICTACTOE_H
#define TEST_TICTACTOE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "sudoku.hpp"

extern "C" {
#include "sudoku.hpp"
}

TEST(player_win, auto)
{
    std::string output_text = "Вы не допустили ни одной ошибки, игра выиграна";

    testing::internal::CaptureStdout();

    int masking_cells = 0;
    int board[9][9];
    
    start(0, masking_cells, board);
    gameover(board);
    
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(generator, different)
{
    int board1[9][9];
    int board2[9][9];
    start(10, 0, board1);
    start(10, 0, board2);

    EXPECT_NE(board1, board2);
}

TEST(error, row)
{
    int board[9][9];
    start(0, 0, board);
    board[0][1] = 1;

    EXPECT_EQ(row_error(board), true);
}

TEST(error, line)
{
    int board[9][9];
    start(0, 0, board);
    board[1][0] = 1;

    EXPECT_EQ(line_error(board), true);
}

TEST(error, block)
{
    int board[9][9];
    start(0, 0, board);
    board[1][1] = 1;

    EXPECT_EQ(block_error(board), true);
}


#endif
