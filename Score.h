/*
    ����Ѻ�红����Ū�����Ф�ṹ

    ���Ѳ�� : ��� �� �è���ѵ��ѭ��
    ��¹����� : 13-11-2021
*/

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

/**
 * ����Ѻ�ѹ�֡������Ф�ṹ��Ҵ��¡ѹ
 *
 * @param string ����
 * @param int ��ṹ
 */
class Score {
private:

    std::string name;
    unsigned long score;

public:

    Score(std::string name, unsigned long score);

    void setName(std::string name);
    std::string getName();

    void setScore(unsigned long score);
    unsigned long getScore();
};