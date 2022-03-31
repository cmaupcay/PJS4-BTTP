// ignore_for_file: prefer_const_constructors, prefer_const_literals_to_create_immutables, use_key_in_widget_constructors, prefer_const_constructors_in_immutables, unnecessary_this, prefer_final_fields, unnecessary_new

import 'package:adaptive_theme/adaptive_theme.dart';
import 'dart:async';
import 'dart:io';
import 'package:flutter/foundation.dart';
import 'main.dart';
import 'package:flutter/material.dart';
import 'delayed_animation.dart';
import 'package:flutter/services.dart';
import 'social_page.dart';
import 'package:google_fonts/google_fonts.dart';
import 'globale_variable.dart';
import 'settings_page.dart';
import 'theme_color.dart';
import 'package:image_picker/image_picker.dart';

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

class HomePage extends StatefulWidget {
  @override
  State<StatefulWidget> createState() {
    return HomePageState();
  }
}

class HomePageState extends State<HomePage> {
  /*ThemeColor lightMode = ThemeColor(
    fond: const Color(0xFF00171F),
    textColor: const Color(0xFF003459),
    bar: const Color(0xFFFFFFFF),
    button: const Color(0xFF007E7A),
    /*shadow: const [
      BoxShadow(
        color: const Color(0xFFd8d7da),
        spreadRadius: 5,
        blurRadius: 10,
        offset: Offset(0, 5),
      ),
    ],*/
  );

  ThemeColor darkMode = ThemeColor(
    fond: const Color(0xFF1a1110),
    textColor: const Color(0xFF003459),
    bar: const Color(0xFF3a3d4b),
    button: const Color(0xFF23ebd1),
    /*shadow: const [
      BoxShadow(
        color: const Color(0xFFd8d7da),
        spreadRadius: 5,
        blurRadius: 10,
        offset: Offset(0, 5),
      ),
    ],*/
  ); */

  int selectedIndex = 0;
  Widget _myScripts = MyScripts();
  Widget _marketScript = MarketScript();
  Widget _myProfile = MyProfile();
  /*Widget _myScriptsAppBar = MyScriptsAppBar();
  Widget _addScriptAppBar = AddScriptAppBar();
  Widget _myProfileAppBar = MyProfileAppBar();
*/
  @override
  Widget build(BuildContext context) {
    return WillPopScope(
      onWillPop: () async => false,
      child: new Scaffold(
        appBar: AppBarHome(),
        body: this.getBody(),
        bottomNavigationBar: BottomNavigationBar(
          type: BottomNavigationBarType.fixed,
          currentIndex: this.selectedIndex,
          backgroundColor: isDarkMode ? darkMode.bar : lightMode.bar,
          selectedItemColor: isDarkMode ? darkMode.button : lightMode.textColor,
          selectedFontSize: 16,
          unselectedItemColor: Colors.grey[400],
          items: [
            BottomNavigationBarItem(
              icon: Icon(
                Icons.search,
              ),
              label: 'My Scripts',
            ),
            BottomNavigationBarItem(
              icon: Icon(
                Icons.shopping_cart_outlined,
              ),
              label: 'Market place',
            ),
            BottomNavigationBarItem(
              icon: Icon(
                Icons.account_circle_outlined,
              ),
              label: 'Profile',
            ),
          ],
          onTap: (int index) {
            this.onTapHandler(index);
          },
        ),
      ),
    );
  }

  Widget getBody() {
    if (this.selectedIndex == 0) {
      return this._myScripts;
    } else if (this.selectedIndex == 1) {
      return this._marketScript;
    } else {
      return this._myProfile;
    }
  }
/*
  Widget getAppBar() {
    if (this.selectedIndex == 0) {
      return this._myScriptsAppBar;
    } else if (this.selectedIndex == 1) {
      return this._addScriptAppBar;
    } else {
      return this._myProfileAppBar;
    }
  }*/

  void onTapHandler(int index) {
    this.setState(() {
      this.selectedIndex = index;
    });
  }
}

class AppBarHome extends StatelessWidget implements PreferredSizeWidget {
  @override
  Size get preferredSize => new Size.fromHeight(kToolbarHeight);
  @override
  Widget build(BuildContext context) {
    return AppBar(
      automaticallyImplyLeading: false,
      backgroundColor: isDarkMode ? darkMode.bar : lightMode.bar,
      title: Text(
        'BTTP',
        style: GoogleFonts.poppins(
          color: isDarkMode ? darkMode.button : lightMode.textColor,
          fontSize: 22,
          fontWeight: FontWeight.w800,
        ),
      ),
      actions: [
        IconButton(
          onPressed: () {
            Navigator.push(
              context,
              MaterialPageRoute(
                builder: (context) => SettingsPage(),
              ),
            );
          },
          icon: Icon(
            Icons.settings,
            color: isDarkMode ? darkMode.button : lightMode.textColor,
            size: 30,
          ),
        )
      ],
      centerTitle: true,
    );
  }
}
/*
class MyScriptsAppBar extends StatelessWidget implements PreferredSizeWidget {
  @override
  Size get preferredSize => const Size.fromHeight(kToolbarHeight);
  @override
  Widget build(BuildContext context) {
    return AppBar(
      automaticallyImplyLeading: false,
      backgroundColor: isDarkMode ? darkMode.bar : lightMode.bar,
      title: Text(
        'BTTP',
        style: GoogleFonts.poppins(
          color: isDarkMode ? darkMode.button : lightMode.textColor,
          fontSize: 22,
          fontWeight: FontWeight.w800,
        ),
      ),
      actions: [
        IconButton(
          onPressed: () {
            Navigator.push(
              context,
              MaterialPageRoute(
                builder: (context) => SettingsPage(),
              ),
            );
          },
          icon: Icon(
            Icons.settings,
            color: isDarkMode ? darkMode.button : lightMode.textColor,
            size: 30,
          ),
        )
      ],
      centerTitle: true,
    );
  }
}

class AddScriptAppBar extends StatelessWidget implements PreferredSizeWidget {
  @override
  Size get preferredSize => const Size.fromHeight(100);
  @override
  Widget build(BuildContext context) {
    return AppBar(
      backgroundColor: isDarkMode ? darkMode.bar : lightMode.bar,
      title: Text(
        'Market Place',
        style: GoogleFonts.poppins(
          color: isDarkMode ? darkMode.textColor : lightMode.textColor,
          fontSize: 22,
          fontWeight: FontWeight.w800,
        ),
      ),
      actions: [
        IconButton(
          onPressed: () {
            Navigator.push(
              context,
              MaterialPageRoute(
                builder: (context) => SettingsPage(),
              ),
            );
          },
          icon: Icon(
            Icons.settings,
            color: isDarkMode ? darkMode.textColor : lightMode.textColor,
            size: 30,
          ),
        )
      ],
      centerTitle: true,
    );
  }
}

class MyProfileAppBar extends StatelessWidget implements PreferredSizeWidget {
  @override
  Size get preferredSize => const Size.fromHeight(100);
  @override
  Widget build(BuildContext context) {
    return AppBar(
      automaticallyImplyLeading: false,
      backgroundColor: isDarkMode ? darkMode.bar : lightMode.bar,
      title: Text(
        'Profile',
        style: GoogleFonts.poppins(
          color: isDarkMode ? darkMode.button : lightMode.textColor,
          fontSize: 22,
          fontWeight: FontWeight.w800,
        ),
      ),
      actions: [
        IconButton(
          onPressed: () {
            Navigator.push(
              context,
              MaterialPageRoute(
                builder: (context) => SettingsPage(),
              ),
            );
          },
          icon: Icon(
            Icons.settings,
            color: isDarkMode ? darkMode.button : lightMode.textColor,
            size: 30,
          ),
        )
      ],
      centerTitle: true,
    );
  }
}*/

class MyScripts extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: isDarkMode ? darkMode.textColor : lightMode.textColor,
      body: SingleChildScrollView(
        child: Column(
          children: [
            FilScript(),
          ],
        ),
      ),
    );
  }
}

class FilScript extends StatelessWidget {
  final List scriptList = [
    {
      'title': 'Script1',
      'terminal': 'Terminal 1',
      'description': "lalalaalalalalalallalalaalalalal",
      'variables': true,
    },
    {
      'title': 'Script2',
      'terminal': 'Terminal 3',
      'description': "lalzelalalaalalalalalalalczczcl",
      'variables': false,
    },
    {
      'title': 'Script3',
      'terminal': 'Terminal 2',
      'description': "lacedcdcalalallalalaalalalalcddl",
      'variables': false,
    },
    {
      'title': 'Script4',
      'terminal': 'Terminal 1',
      'description': "lyj,hkylaalalalalgfvdl",
      'variables': true,
    }
  ];
  @override
  Widget build(BuildContext context) {
    return Container(
      padding: EdgeInsets.all(10),
      color: isDarkMode ? darkMode.fond : lightMode.fond,
      child: Column(
        children: [
          Column(
            children: scriptList.map((scripts) {
              return ScriptCard(scripts);
            }).toList(),
          ),
        ],
      ),
    );
  }
}

class ScriptCard extends StatelessWidget {
  final Map scriptData;
  ScriptCard(this.scriptData);
  @override
  Widget build(BuildContext context) {
    return Container(
      margin: EdgeInsets.all(10),
      height: 230,
      width: double.infinity,
      decoration: BoxDecoration(
//        color: bars,
        color: isDarkMode ? darkMode.bar : lightMode.bar,
        borderRadius: BorderRadius.all(Radius.circular(18)),
        boxShadow: [
          BoxShadow(
            color: Colors.grey.shade600,
            spreadRadius: 1,
            blurRadius: 2,
            offset: Offset(0, 3),
          )
        ],
      ),
      child: Column(
        children: [
          Container(
            margin: EdgeInsets.fromLTRB(10, 10, 10, 10),
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [
                Text(
                  scriptData['title'],
                  style: GoogleFonts.nunito(
                    color: isDarkMode ? darkMode.button : lightMode.textColor,
                    fontSize: 22,
                    fontWeight: FontWeight.w800,
                  ),
                ),
              ],
            ),
          ),
          Container(
            margin: EdgeInsets.fromLTRB(10, 25, 10, 5),
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [
                Text(
                  scriptData['terminal'],
                  style: GoogleFonts.nunito(
                    color: isDarkMode ? darkMode.button : lightMode.textColor,
                    fontSize: 18,
                    fontWeight: FontWeight.w600,
                  ),
                ),
                IconButton(
                  onPressed: () {
                    showDialog(
                      context: context,
                      builder: (BuildContext context) =>
                          _buildPopupDialog(context),
                    );
                  },
                  icon: Icon(
                    Icons.arrow_forward_ios,
                    color: isDarkMode ? darkMode.button : lightMode.fond,
                    size: 30,
                  ),
                )
              ],
            ),
          ),
          Container(
            margin: EdgeInsets.fromLTRB(10, 5, 10, 10),
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [
                Text(
                  scriptData['description'],
                  style: GoogleFonts.nunito(
                    color: isDarkMode ? darkMode.button : lightMode.textColor,
                    fontSize: 18,
                    fontWeight: FontWeight.w600,
                  ),
                ),
                IconButton(
                  onPressed: () {
                    showDialog(
                      context: context,
                      builder: (BuildContext context) =>
                          _buildPopupDialog(context),
                    );
                  },
                  icon: Icon(
                    Icons.add_circle_outline_rounded,
                    color: isDarkMode ? darkMode.button : lightMode.fond,
                    size: 30,
                  ),
                )
              ],
            ),
          ),
        ],
      ),
    );
  }
}

Widget _buildPopupDialog(BuildContext context) {
  return new AlertDialog(
    title: const Text('Popup example'),
    content: new Column(
      mainAxisSize: MainAxisSize.min,
      crossAxisAlignment: CrossAxisAlignment.start,
      children: <Widget>[
        Text("Hello"),
      ],
    ),
    actions: <Widget>[
      new ElevatedButton(
        onPressed: () {
          Navigator.of(context).pop();
        },
        child: const Text('Close'),
      ),
    ],
  );
}

class MarketScript extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: isDarkMode ? darkMode.textColor : lightMode.textColor,
      body: SingleChildScrollView(
        child: Column(
          children: [
            MarketScriptCard(),
          ],
        ),
      ),
    );
  }
}

class MarketScriptCard extends StatelessWidget {
  final List marketScriptList = [
    {
      'title': 'Script1',
      'description': "lalalaalalalalalallalalaalalalal",
      'variables': true,
    },
    {
      'title': 'Script2',
      'description': "lalzelalalaalalalalalalalczczcl",
      'variables': false,
    },
    {
      'title': 'Script3',
      'description': "lacedcdcalalallalalaalalalalcddl",
      'variables': false,
    },
    {
      'title': 'Script4',
      'description': "lyj,hkylaalalalalgfvdl",
      'variables': true,
    },
    {
      'title': 'Script5',
      'description': "lyj,hkylaalalalalgfvdl",
      'variables': true,
    },
    {
      'title': 'Script6',
      'description': "lyj,hkylaalalalalgfvdl",
      'variables': true,
    },
    {
      'title': 'Script7',
      'description': "lyj,hkylaalalalalgfvdl",
      'variables': true,
    },
    {
      'title': 'Script8',
      'description': "lyj,hkylaalalalalgfvdl",
      'variables': true,
    },
    {
      'title': 'Script9',
      'description': "lyj,hkylaalalalalgfvdl",
      'variables': true,
    },
    {
      'title': 'Script10',
      'description': "lyj,hkylaalalalalgfvdl",
      'variables': true,
    },
    {
      'title': 'Script11',
      'description': "lyj,hkylaalalalalgfvdl",
      'variables': true,
    }
  ];
  @override
  Widget build(BuildContext context) {
    return Container(
      padding: EdgeInsets.all(10),
      color: isDarkMode ? darkMode.fond : lightMode.fond,
      child: Column(
        children: [
          Column(
            children: marketScriptList.map((marketscripts) {
              return MarketCard(marketscripts);
            }).toList(),
          ),
        ],
      ),
    );
  }
}

class MarketCard extends StatelessWidget {
  final Map marketscriptData;
  MarketCard(this.marketscriptData);
  @override
  Widget build(BuildContext context) {
    return Container(
      margin: EdgeInsets.all(10),
      height: 70,
      width: double.infinity,
      decoration: BoxDecoration(
//        color: bars,
        color: isDarkMode ? darkMode.bar : lightMode.bar,
        borderRadius: BorderRadius.all(Radius.circular(18)),
        boxShadow: [
          BoxShadow(
            color: Colors.grey.shade600,
            spreadRadius: 1,
            blurRadius: 2,
            offset: Offset(0, 3),
          )
        ],
      ),
      child: Column(
        children: [
          Container(
            margin: EdgeInsets.fromLTRB(10, 10, 10, 10),
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [
                Text(
                  marketscriptData['title'],
                  style: GoogleFonts.nunito(
                    color: isDarkMode ? darkMode.button : lightMode.textColor,
                    fontSize: 22,
                    fontWeight: FontWeight.w800,
                  ),
                ),
                IconButton(
                  onPressed: () {
                    showDialog(
                      context: context,
                      builder: (BuildContext context) => _buildPopupDialogInfo(
                          context, marketscriptData['description']),
                    );
                  },
                  icon: Icon(
                    Icons.info,
                    color: isDarkMode ? darkMode.button : lightMode.fond,
                    size: 30,
                  ),
                ),
                IconButton(
                  onPressed: () {
                    showDialog(
                      context: context,
                      builder: (BuildContext context) => _buildPopupDialogInfo(
                          context, marketscriptData['description']),
                    );
                  },
                  icon: Icon(
                    Icons.download_for_offline,
                    color: isDarkMode ? darkMode.button : lightMode.fond,
                    size: 30,
                  ),
                )
              ],
            ),
          ),
        ],
      ),
    );
  }
}

Widget _buildPopupDialogInfo(BuildContext context, String description) {
  return new AlertDialog(
    title: const Text('Description'),
    content: new Column(
      mainAxisSize: MainAxisSize.min,
      crossAxisAlignment: CrossAxisAlignment.start,
      children: <Widget>[
        Text(description),
      ],
    ),
    actions: <Widget>[
      new ElevatedButton(
        onPressed: () {
          Navigator.of(context).pop();
        },
        child: const Text('Close'),
      ),
    ],
  );
}

class MyProfile extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Container(
        color: isDarkMode ? darkMode.fond : lightMode.fond,
        padding: EdgeInsets.only(left: 16, top: 25, right: 16),
        child: GestureDetector(
          onTap: () {
            FocusScope.of(context).unfocus();
          },
          child: ListView(
            children: [
              /*Text(
                "Edit Profile",
                style: TextStyle(
                  fontSize: 25,
                  fontWeight: FontWeight.w500,
                  color: isDarkMode ? darkMode.button : lightMode.textColor,
                ),
              ),
              SizedBox(
                height: 15,
              ),*/
              Center(
                child: Stack(
                  children: [
                    Container(
                      width: 130,
                      height: 130,
                      decoration: BoxDecoration(
                          border: Border.all(
                            width: 4,
                            color: isDarkMode
                                ? darkMode.button
                                : lightMode.textColor,
                          ),
                          boxShadow: [
                            BoxShadow(
                                spreadRadius: 2,
                                blurRadius: 10,
                                color: Colors.black.withOpacity(0.1),
                                offset: Offset(0, 10))
                          ],
                          shape: BoxShape.circle,
                          image: DecorationImage(
                              fit: BoxFit.cover,
                              image: NetworkImage(
                                "https://i.pinimg.com/736x/0f/8b/28/0f8b2870896edcde8f6149fe2733faaf--logo-programmer-coder.jpg",
                                //"https://yt3.ggpht.com/ytc/AKedOLS-uPKnNFdAC-foMxhkDZjWDleDIJptDrXg_hLYfA=s88-c-k-c0x00ffffff-no-rj",
                              ))),
                    ),
                    Positioned(
                        bottom: 0,
                        right: 0,
                        child: Container(
                          height: 40,
                          width: 40,
                          decoration: BoxDecoration(
                            shape: BoxShape.circle,
                            border: Border.all(
                              width: 4,
                              color: Colors.white,
                            ),
                            color: isDarkMode
                                ? darkMode.button
                                : lightMode.textColor,
                          ),
                          child: Icon(
                            Icons.edit,
                            color: Colors.white,
                          ),
                        )),
                  ],
                ),
              ),
              SizedBox(
                height: 35,
              ),
              SizedBox(
                height: 35,
              ),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  Text("Pseudo :",
                      style: TextStyle(
                        fontSize: 18,
                        letterSpacing: 2.2,
                        color: isDarkMode ? darkMode.button : lightMode.bar,
                      )),
                  Text("Likir09",
                      style: TextStyle(
                        fontSize: 16,
                        letterSpacing: 2.2,
                        color: isDarkMode ? darkMode.button : lightMode.bar,
                      )),
                ],
              ),
              /*Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  Text("Clé PGP:",
                      style: TextStyle(
                        fontSize: 18,
                        letterSpacing: 2.2,
                        color:
                            isDarkMode ? darkMode.button : lightMode.textColor,
                      )),
                  Text("UIBILKHBUAUK9841A8465AAEHJQ",
                      style: TextStyle(
                        fontSize: 10,
                        letterSpacing: 2.2,
                        color:
                            isDarkMode ? darkMode.button : lightMode.textColor,
                      )),
                ],
              ),*/
              SizedBox(
                height: 35,
              ),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  Text("Changer le mot de passe :",
                      style: TextStyle(
                        fontSize: 18,
                        letterSpacing: 2.2,
                        color: isDarkMode ? darkMode.button : lightMode.bar,
                      )),
                  IconButton(
                      onPressed: () {},
                      icon: Icon(
                        Icons.lock,
                        color: isDarkMode ? darkMode.button : lightMode.bar,
                        size: 30,
                      )),
                ],
              ),
              SizedBox(
                height: 35,
              ),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  Text("Déconnexion :",
                      style: TextStyle(
                        fontSize: 18,
                        letterSpacing: 2.2,
                        color: isDarkMode ? darkMode.button : lightMode.bar,
                      )),
                  IconButton(
                      onPressed: () {},
                      icon: Icon(
                        Icons.logout_outlined,
                        color: isDarkMode ? darkMode.button : lightMode.bar,
                        size: 30,
                      )),
                ],
              ),
            ],
          ),
        ),
      ),
    );
  }
}
