// ignore_for_file: prefer_const_constructors

import 'dart:ui';

import 'package:flutter/material.dart';

var fond = Color(0xFF191970);
var screen = Colors.white;
var bars = Color(0xFF2154a2);
var theme = true;
void changetheme() {
  if (theme) {
    //passer dark
    fond = Color(0xFF191970);
    screen = Colors.white;
    bars = Color(0xFF2154a2);
    theme = false;
  } else {
    fond = Color(0xFF191970);
    screen = Colors.white;
    bars = Color(0xFF2154a2);
    theme = true;
  }
}
