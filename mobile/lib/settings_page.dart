// ignore_for_file: unnecessary_const, avoid_print, prefer_const_constructors

import 'theme_color.dart';

import 'main.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:google_fonts/google_fonts.dart';
import 'globale_variable.dart';
import 'home_page.dart';
import 'package:adaptive_theme/adaptive_theme.dart';

ThemeColor lightMode = ThemeColor(
  fond: const Color(0xFF00A8E8),
  textColor: const Color(0xFF003459),
  bar: const Color(0xFFFFFFFF),
  button: const Color(0xFF007E7A),
);

ThemeColor darkMode = ThemeColor(
  fond: const Color(0xFF1d1d1d),
  textColor: const Color(0xFF003459),
  bar: const Color(0xFF3a3d4b),
  button: const Color(0xFF23ebd1),
);

class SettingsPage extends StatefulWidget {
  @override
  _SettingsPage createState() => _SettingsPage();
}

class _SettingsPage extends State<SettingsPage> {
  @override
  void initState() {
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    SystemChrome.setPreferredOrientations(
        [DeviceOrientation.portraitUp, DeviceOrientation.portraitDown]);
    return Scaffold(
      backgroundColor: isDarkMode ? darkMode.fond : lightMode.textColor,
      appBar: AppBar(
        elevation: 0,
        backgroundColor: isDarkMode ? darkMode.bar : lightMode.bar,
        leading: IconButton(
          icon: Icon(
            Icons.arrow_back,
            color: isDarkMode ? darkMode.button : lightMode.textColor,
            size: 30,
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
        title: Text(
          'Settings',
          style: GoogleFonts.raleway(
            color: isDarkMode ? darkMode.button : lightMode.textColor,
            fontSize: 22,
            fontWeight: FontWeight.w800,
          ),
        ),
      ),
      body: SingleChildScrollView(
        child: SwitchListTile(
          title: Text(
            'Mode sombre',
            style: GoogleFonts.raleway(
              color: isDarkMode ? darkMode.button : lightMode.textColor,
              fontSize: 16,
              fontWeight: FontWeight.w500,
            ),
          ),
          tileColor: isDarkMode ? darkMode.textColor : lightMode.fond,
          activeColor: darkMode.button,
          secondary: const Icon(Icons.nightlight_round),
          value: isDarkMode,
          onChanged: (bool value) {
            setIsDarkMode();
            setState(() {});
            print('cc');
          },
        ),
      ),
    );
  }
}
