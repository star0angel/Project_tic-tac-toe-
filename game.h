#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3  //��
#define COL 3  //��
static int count = 0;


void staring();//������ʾ
void Load_Game();//������Ϸ
void initboard(char board[ROW][COL], int row, int col);//��ʼ������
void  displayboard(char board[ROW][COL], int row, int col);//��ʾ���� ��������������
void playermove(char board[ROW][COL], int row, int col);//����߲�
void computermove(char board[ROW][COL], int row, int col);//�����߲�
int iswin(char board[ROW][COL], int row, int col);//�ж���Ӯ�;�״̬
