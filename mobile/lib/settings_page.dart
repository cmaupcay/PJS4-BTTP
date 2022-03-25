import 'main.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:google_fonts/google_fonts.dart';
import 'globale_variable.dart';
import 'home_page.dart';

class SettingsPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    SystemChrome.setPreferredOrientations(
        [DeviceOrientation.portraitUp, DeviceOrientation.portraitDown]);
    return Scaffold(
      backgroundColor: screen,
      appBar: AppBar(
        elevation: 0,
        backgroundColor: bars,
        leading: IconButton(
          // ignore: prefer_const_constructors
          icon: Icon(
            Icons.arrow_back,
            color: Colors.black,
            size: 30,
          ),
          onPressed: () {
            Navigator.pop(context);
          },
        ),
        title: Text(
          'Settings',
          style: GoogleFonts.poppins(
            color: Colors.white,
            fontSize: 22,
            fontWeight: FontWeight.w800,
          ),
        ),
      ),
      body: Column(
        children: [
          Row(children: const <Widget>[
            Expanded(
              child: Text('Dark mode', textAlign: TextAlign.center),
            ),
            Expanded(
              child: OutlinedButton(
                onPressed: changetheme,
                child: Text('appui'),
              ),
            ),
          ]),
        ],
      ),
    );
  }
}
