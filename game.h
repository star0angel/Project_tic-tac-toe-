#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3  //行
#define COL 3  //列
static int count = 0;


void staring();//开场提示
void Load_Game();//载入游戏
void initboard(char board[ROW][COL], int row, int col);//初始化棋盘
void  displayboard(char board[ROW][COL], int row, int col);//显示棋盘 并更新棋盘数据
void playermove(char board[ROW][COL], int row, int col);//玩家走步
void computermove(char board[ROW][COL], int row, int col);//电脑走步
int iswin(char board[ROW][COL], int row, int col);//判断输赢和局状态
