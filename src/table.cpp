﻿#include <sstream>
#include "../include/table.h"

PlayTable::PlayTable(QWidget *parent) :
    QTableWidget(parent){

}

void PlayTable::AddItem(PlayFair &playfair)
{
    this->setRowCount(PlayFair::rows - 1);//设置行数
    this->setColumnCount(PlayFair::cols - 1);//设置列数

    /* 填充表格 */
    for(size_t i = 0; i != PlayFair::rows; ++i){
        /* 设置行高和列高 */
        this->setRowHeight(i, 30);
        this->setColumnWidth(i, 30);

        for(size_t j = 0; j != PlayFair::cols; ++j){
            QTableWidgetItem *item = new QTableWidgetItem;
            QString txt = QString("%1").arg(playfair.getKey(i + 1, j + 1));
            item->setText(txt);
            this->setItem(i, j, item);
        }
    }
    //this->setItem(PlayFair::rows - 1, PlayFair::cols - 1, new QTableWidgetItem(""));//设置最后一行最后一列为空
    this->setItem(playfair.getKeyValue('z') / 5, playfair.getKeyValue('z') % 5, new QTableWidgetItem("y/z"));//设置z和y显示在同一位置，但其他地方会出现有z和y同时出现却没有在一起的情况
}

void PlayTable::AddItem(HillEnc &hill)
{
    this->setRowCount(HillEnc::rows);
    this->setColumnCount(HillEnc::cols * 2 + 1);
    this->clear();

    /* 填充表格 */
    for(size_t i = 0; i != HillEnc::rows; ++i){
        /* 设置行高和列高 */
        this->setRowHeight(i, 30);

        for(size_t j = 0; j != HillEnc::cols * 2 + 1; ++j){
            if(i == 0)
                this->setColumnWidth(j, 30);

            /* 前三列为加密矩阵，后三列为解密矩阵 */
            int tmp;
            if(j < 3)
                tmp = hill.getKey(i + 1, j + 1);
            else if(j > 3)
                tmp = hill.getRekey(i + 1, j - 3);
            else
                continue;

            /* 添加实例 */
            QTableWidgetItem *item = new QTableWidgetItem;
            QString txt = QString("%1").arg(tmp);
            item->setText(txt);
            this->setItem(i, j, item);
        }
    }
}

void PlayTable::AddItem(RSA &rsa)
{
    this->setRowCount(2);
    this->setColumnCount(6);
    this->clear();

    for(int j = 0; j < 6; ++j)
        this->setColumnWidth(j, 40);

    //this->setColumnWidth(3, 40);

    QString txt;

    txt = "p";
    QTableWidgetItem *item = new QTableWidgetItem;
    item->setText(txt);
    this->setItem(0, 0, item);

    txt = "q";
    item = new QTableWidgetItem;
    item->setText(txt);
    this->setItem(0, 1, item);

    txt = "n";
    item = new QTableWidgetItem;
    item->setText(txt);
    this->setItem(0, 2, item);

    txt = "euler";
    item = new QTableWidgetItem;
    item->setText(txt);
    this->setItem(0, 3, item);

    txt = "e";
    item = new QTableWidgetItem;
    item->setText(txt);
    this->setItem(0, 4, item);

    txt = "d";
    item = new QTableWidgetItem;
    item->setText(txt);
    this->setItem(0, 5, item);

    txt = QString("%1").arg(rsa.getPrimeP());
    item = new QTableWidgetItem;
    item->setText(txt);
    this->setItem(1, 0, item);

    txt = QString("%1").arg(rsa.getPrimeQ());
    item = new QTableWidgetItem;
    item->setText(txt);
    this->setItem(1, 1, item);

    txt = QString("%1").arg(rsa.getN());
    item = new QTableWidgetItem;
    item->setText(txt);
    this->setItem(1, 2, item);

    txt = QString("%1").arg(rsa.getEuler());
    item = new QTableWidgetItem;
    item->setText(txt);
    this->setItem(1, 3, item);

    txt = QString("%1").arg(rsa.getPublicKey());
    item = new QTableWidgetItem;
    item->setText(txt);
    this->setItem(1, 4, item);

    txt = QString("%1").arg(rsa.getPrivateKey());
    item = new QTableWidgetItem;
    item->setText(txt);
    this->setItem(1, 5, item);
}
