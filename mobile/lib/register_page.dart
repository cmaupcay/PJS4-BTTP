// ignore_for_file: file_names, prefer_const_constructors, sized_box_for_whitespace, use_key_in_widget_constructors

import 'main.dart';
import 'package:flutter/material.dart';
import 'delayed_animation.dart';
import 'package:flutter/services.dart';
import 'package:google_fonts/google_fonts.dart';
import 'home_page.dart';
import 'globale_variable.dart';

class RegisterPage extends StatelessWidget {
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
              Container(
                margin: EdgeInsets.symmetric(
                  vertical: 40,
                  horizontal: 30,
                ),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    DelayedAnimation(
                      delay: 500,
                      child: Text(
                        "Inscrivez-vous",
                        style: GoogleFonts.raleway(
                          color: textColorLight,
                          fontSize: 25,
                          fontWeight: FontWeight.w600,
                        ),
                      ),
                    ),
                    SizedBox(height: 22),
                  ],
                ),
              ),
              SizedBox(height: 35),
              LoginForm(),
              SizedBox(height: 125),
              DelayedAnimation(
                delay: 3000,
                child: ElevatedButton(
                  style: ElevatedButton.styleFrom(
                    shape: StadiumBorder(),
                    primary: barLight,
                    padding: EdgeInsets.symmetric(
                      horizontal: 125,
                      vertical: 13,
                    ),
                  ),
                  child: Text(
                    'CONFIRMER',
                    style: GoogleFonts.raleway(
                      color: textColorLight,
                      fontSize: 15,
                      fontWeight: FontWeight.w500,
                    ),
                  ),
                  onPressed: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(
                        builder: (context) => HomePage(),
                      ),
                    );
                  },
                ),
              ),
              SizedBox(height: 90),
            ],
          ),
        ),
      ),
    );
  }
}

class LoginForm extends StatefulWidget {
  @override
  _LoginFormState createState() => _LoginFormState();
}

class _LoginFormState extends State<LoginForm> {
  var _obscureText = true;
  @override
  Widget build(BuildContext context) {
    return Container(
      margin: EdgeInsets.symmetric(
        horizontal: 30,
      ),
      child: Column(
        children: [
          DelayedAnimation(
            delay: 1500,
            child: TextField(
              style: GoogleFonts.raleway(
                color: textColorLight,
              ),
              cursorColor: textColorLight,
              decoration: InputDecoration(
                fillColor: Colors.white,
                filled: true,
                labelText: 'Votre pseudo',
                labelStyle: GoogleFonts.raleway(
                  color: textColorLight,
                ),
              ),
            ),
          ),
          SizedBox(height: 30),
          DelayedAnimation(
            delay: 2000,
            child: TextField(
              style: GoogleFonts.raleway(
                color: textColorLight,
              ),
              cursorColor: textColorLight,
              obscureText: _obscureText,
              decoration: InputDecoration(
                fillColor: Colors.white,
                filled: true,
                labelStyle: GoogleFonts.raleway(
                  color: textColorLight,
                ),
                labelText: 'Mot de passe',
                suffixIcon: IconButton(
                  icon: Icon(
                    Icons.visibility,
                    color: textColorLight,
                  ),
                  onPressed: () {
                    setState(() {
                      _obscureText = !_obscureText;
                    });
                  },
                ),
              ),
            ),
          ),
          SizedBox(height: 30),
          DelayedAnimation(
            delay: 2000,
            child: TextField(
              style: GoogleFonts.raleway(
                color: textColorLight,
              ),
              cursorColor: textColorLight,
              obscureText: _obscureText,
              decoration: InputDecoration(
                fillColor: Colors.white,
                filled: true,
                labelStyle: GoogleFonts.raleway(
                  color: textColorLight,
                ),
                labelText: 'vérification mot de passe',
                suffixIcon: IconButton(
                  icon: Icon(
                    Icons.visibility,
                    color: textColorLight,
                  ),
                  onPressed: () {
                    setState(() {
                      _obscureText = !_obscureText;
                    });
                  },
                ),
              ),
            ),
          ),
        ],
      ),
    );
  }
}
