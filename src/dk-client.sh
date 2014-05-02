#!/bin/bash

# 安装xlinker到模拟器
# 自动启动xlinker到调试器
# 启动本地的调试器，并且与远程对接
# 启动a-gdbtui

AGdbtui="a-gdbtui"
TP=1234
SymbolFile="~/workspace/xlinker/src/udog"
BreakLine=3050

$AGdbtui