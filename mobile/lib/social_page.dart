// ignore_for_file: prefer_const_constructors, prefer_const_literals_to_create_immutables

import 'main.dart';
import 'package:flutter/material.dart';
import 'delayed_animation.dart';
import 'package:flutter/services.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';
import 'login_page.dart';
import 'globale_variable.dart';
import 'register_page.dart';

class SocialPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    SystemChrome.setPreferredOrientations(
        [DeviceOrientation.portraitUp, DeviceOrientation.portraitDown]);
    return Scaffold(
      backgroundColor: fondLight,
      /*appBar: AppBar(
        automaticallyImplyLeading: false,
        elevation: 0,
        backgroundColor: screen.withOpacity(0),
        leading: IconButton(
          icon: Icon(
            Icons.arrow_back,
            color: Colors.black,
            size: 30,
          ),
          onPressed: () {
            Navigator.pop(context);
          },
        ),
      ),*/
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
                  height: 280,
                  child: Image.asset('images/logoTrans.png'),
                ),
              ),
              DelayedAnimation(
                delay: 1000,
                child: Container(
                  margin: const EdgeInsets.symmetric(
                    vertical: 40,
                    horizontal: 30,
                  ),
                  child: Column(
                    children: [
                      Text(
                        "Connectez vous pour commencer",
                        textAlign: TextAlign.center,
                        style: GoogleFonts.raleway(
                          color: textColorLight,
                          fontSize: 16,
                          fontWeight: FontWeight.w600,
                        ),
                      ),
                      SizedBox(
                        height: 20,
                      ),
                      ElevatedButton(
                        onPressed: () {
                          Navigator.push(
                            context,
                            MaterialPageRoute(
                              builder: (context) => LoginPage(),
                            ),
                          );
                        },
                        style: ElevatedButton.styleFrom(
                          shape: StadiumBorder(),
                          primary: barLight,
                          padding: EdgeInsets.all(13),
                        ),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            Icon(
                              Icons.logout_outlined,
                              color: textColorLight,
                            ),
                            SizedBox(width: 10),
                            Text(
                              "CONNEXION",
                              style: GoogleFonts.raleway(
                                color: textColorLight,
                                fontSize: 16,
                                fontWeight: FontWeight.w500,
                              ),
                            ),
                          ],
                        ),
                      ),
                      SizedBox(
                        height: 30,
                      ),
                      SizedBox(
                        height: 10,
                      ),
                      ElevatedButton(
                        onPressed: () {
                          Navigator.push(
                            context,
                            MaterialPageRoute(
                              builder: (context) => RegisterPage(),
                            ),
                          );
                        },
                        style: ElevatedButton.styleFrom(
                          shape: StadiumBorder(),
                          primary: barLight,
                          padding: EdgeInsets.all(13),
                        ),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            Icon(Icons.app_registration_outlined,
                                color: textColorLight),
                            SizedBox(width: 10),
                            Text(
                              "INSCRIPTION",
                              style: GoogleFonts.raleway(
                                color: textColorLight,
                                fontSize: 16,
                                fontWeight: FontWeight.w500,
                              ),
                            ),
                          ],
                        ),
                      ),
                    ],
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
