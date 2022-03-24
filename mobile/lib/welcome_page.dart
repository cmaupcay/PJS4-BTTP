// ignore_for_file: file_names, prefer_const_constructors, sized_box_for_whitespace

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
      backgroundColor: Color(0xFF000010),
      body: SingleChildScrollView(
        child: Container(
          margin: EdgeInsets.symmetric(
            vertical: 60,
            horizontal: 30,
          ),
          child: Column(
            children: [
              DelayedAnimation(
                delay: 500,
                child: Container(
                  height: 170,
                  child: Image.asset('images/logo.jpg'),
                ),
              ),
              DelayedAnimation(
                delay: 1000,
                child: Container(
                  height: 400,
                  child: Image.asset('images/LogoRond.png'),
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
                    "Découvrez la meilleure Application de gestion de script: BTTP",
                    textAlign: TextAlign.center,
                    style: GoogleFonts.poppins(
                      color: Colors.grey[500],
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
                      primary: bars,
                      shape: StadiumBorder(),
                      padding: EdgeInsets.all(13),
                    ),
                    child: Text('COMMENCER'),
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
