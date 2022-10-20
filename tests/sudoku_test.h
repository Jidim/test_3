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
    std::string output_text = "Вы не допустили ни одной ошибки, игра выиграна\n";

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

TEST(handler, zero)
{
    std::string output_text = "Вы не допустили ни одной ошибки, игра выиграна\n";

    testing::internal::CaptureStdout();

    int masking_cells = 0;
    
    handler(masking_cells);
    
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

}

TEST(swiple, littleRow)
{
    int board1[9][9];
    int board2[9][9];
    start(0, 0, board1);
    start(0, 0, board2);
    small_row_swipe(1, 0, board1);
    bool eq = true;
    
    for(int i = 0; i < 9; i++)
        if (board1[i][1] != board2[i][0] || board1[i][0] != board2[i][1])
            eq = false;
    
    EXPECT_EQ(eq, true);
}

TEST(swiple, littleLine)
{
    int board1[9][9];
    int board2[9][9];
    start(0, 0, board1);
    start(0, 0, board2);
    small_line_swipe(1, 0, board1);
    bool eq = true;
    
    for(int j = 0; j < 9; j++)
        if (board1[1][j] != board2[0][j] || board1[0][j] != board2[1][j])
            eq = false;
    
    EXPECT_EQ(eq, true);
}

TEST(swipe, bigRow)
{
    int board1[9][9];
    int board2[9][9];
    start(0, 0, board1);
    start(0, 0, board2);
    big_row_swipe(1, 0, board1);
    bool eq = true;
    
    for (int b = 0; b < 3; b++)
        for(int j = 0; j < 9; j++)
            if (board1[b+3][j] != board2[b][j] || board1[b][j] != board2[b+3][j])
                eq = false;
    
    EXPECT_EQ(eq, true);
}

TEST(swipe, bigLine)
{
    int board1[9][9];
    int board2[9][9];
    start(0, 0, board1);
    start(0, 0, board2);
    big_line_swipe(1, 0, board1);
    bool eq = true;
    
    board_print(board1);
    board_print(board2);
    
    for (int b = 0; b < 3; b++)
        for(int i = 0; i < 9; i++)
            if (board1[i][b+3] != board2[i][b] || board1[i][b] != board2[i][b+3])
                eq = false;
    
    EXPECT_EQ(eq, true);
}
#endif
