// ignore_for_file: file_names, prefer_const_constructors, sized_box_for_whitespace

import 'home_page.dart';

import 'main.dart';
import 'package:flutter/material.dart';
import 'delayed_animation.dart';
import 'package:flutter/services.dart';
import 'social_page.dart';
import 'package:google_fonts/google_fonts.dart';
import 'globale_variable.dart';

class WelcomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    SystemChrome.setPreferredOrientations(
        [DeviceOrientation.portraitUp, DeviceOrientation.portraitDown]);
    return Scaffold(
      backgroundColor: fondLight,
      body: SingleChildScrollView(
        child: Container(
          margin: EdgeInsets.symmetric(
            vertical: 60,
            horizontal: 30,
          ),
          child: Column(
            children: [
              DelayedAnimation(
                delay: 1000,
                child: Container(
                  padding: EdgeInsets.all(13),
                  color: fondLight,
                  height: 400,
                  child: Image.asset('images/logoTrans.png'),
                ),
              ),
              DelayedAnimation(
                delay: 1500,
                child: Container(
                  margin: EdgeInsets.only(
                    top: 30,
                    bottom: 20,
                  ),
                  child: Text(
                    "Découvrez BTTP, un système d’inter opérabilité mobile - PC qui vous permet, à partir de votre smartphone, d’exécuter des scripts sur votre PC de destination à distance. ",
                    textAlign: TextAlign.center,
                    style: GoogleFonts.raleway(
                      color: textColorLight,
                      fontSize: 16,
                    ),
                  ),
                ),
              ),
              DelayedAnimation(
                delay: 2000,
                child: Container(
                  width: double.infinity,
                  child: ElevatedButton(
                    style: ElevatedButton.styleFrom(
                      primary: barLight,
                      shape: StadiumBorder(),
                      padding: EdgeInsets.all(13),
                    ),
                    child: Text(
                      'COMMENCER',
                      style: GoogleFonts.raleway(
                        color: textColorLight,
                      ),
                    ),
                    onPressed: () {
                      Navigator.push(
                        context,
                        MaterialPageRoute(
                          builder: (context) => SocialPage(),
                        ),
                      );
                    },
                  ),
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
