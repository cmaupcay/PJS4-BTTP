// ignore_for_file: prefer_const_constructors

import 'dart:ui';

import 'package:flutter/material.dart';

bool isDarkMode = false;
bool getIsDarkMode() {
  return isDarkMode;
}

void setIsDarkMode() {
  isDarkMode = !isDarkMode;
}

var fondLight = const Color(0xFF00A8E8);
var textColorLight = const Color(0xFF003459);
var barLight = const Color(0xFFFFFFFF);
var fondDark = const Color(0xFF1d1d1d);
var barDark = const Color(0xFF3a3d4b);
var textColorDark = const Color(0xFF23ebd1);

var DarkGreen = Color(0xFF0cd146);
var DarkScreen = Color(0xFF070225);
var fond = Color(0xFF191970);
var screen = Colors.white;
var bars = Color(0xFF2154a2);
var theme =
    true;/*
void changetheme() {
  if (!theme) {
    //passer dark
    fond = Color(0xFF191970);
    screen = Colors.white;
    bars = Color(0xFF2154a2);
    theme = true;
  } else {
    fond = Color(0xFF0acac5);
    screen = Color(0xFF070225);
    bars = Color(0xFF15f4ee);
    theme = false;
  }
}*/
