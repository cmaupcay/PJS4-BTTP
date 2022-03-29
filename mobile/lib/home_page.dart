// ignore_for_file: prefer_const_constructors, prefer_const_literals_to_create_immutables, use_key_in_widget_constructors, prefer_const_constructors_in_immutables, unnecessary_this, prefer_final_fields, unnecessary_new

import 'package:adaptive_theme/adaptive_theme.dart';

import 'main.dart';
import 'package:flutter/material.dart';
import 'delayed_animation.dart';
import 'package:flutter/services.dart';
import 'social_page.dart';
import 'package:google_fonts/google_fonts.dart';
import 'globale_variable.dart';
import 'settings_page.dart';
import 'theme_color.dart';

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
  Widget _addScript = AddScript();
  Widget _myProfile = MyProfile();
  Widget _myScriptsAppBar = MyScriptsAppBar();
  Widget _addScriptAppBar = AddScriptAppBar();
  Widget _myProfileAppBar = MyProfileAppBar();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: MyScriptsAppBar(),
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
    );
  }

  Widget getBody() {
    if (this.selectedIndex == 0) {
      return this._myScripts;
    } else if (this.selectedIndex == 1) {
      return this._addScript;
    } else {
      return this._myProfile;
    }
  }

  Widget getAppBar() {
    if (this.selectedIndex == 0) {
      return this._myScriptsAppBar;
    } else if (this.selectedIndex == 1) {
      return this._addScriptAppBar;
    } else {
      return this._myProfileAppBar;
    }
  }

  void onTapHandler(int index) {
    this.setState(() {
      this.selectedIndex = index;
    });
  }
}

String getPage(index) {
  if (index == 0) {
    return 'Mes scripts';
  } else if (index == 1) {
    return 'Market Place';
  } else if (index == 2) {
    return 'Profile';
  }
  return 'Mes scripts';
}

class AppBarHome extends StatelessWidget implements PreferredSizeWidget {
  @override
  Size get preferredSize => new Size.fromHeight(kToolbarHeight);
  @override
  Widget build(BuildContext context) {
    return AppBar(
      backgroundColor: isDarkMode ? darkMode.bar : lightMode.bar,
      title: Text(
        getPage(0),
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
            color: isDarkMode ? darkMode.textColor : lightMode.textColor,
            size: 30,
          ),
        )
      ],
      centerTitle: true,
    );
  }
}

class MyScriptsAppBar extends StatelessWidget implements PreferredSizeWidget {
  @override
  Size get preferredSize => const Size.fromHeight(kToolbarHeight);
  @override
  Widget build(BuildContext context) {
    return AppBar(
      automaticallyImplyLeading: false,
      backgroundColor: isDarkMode ? darkMode.bar : lightMode.bar,
      title: Text(
        'My Scripts',
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
}

class MyScripts extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    AppBar(
      backgroundColor: isDarkMode ? darkMode.bar : lightMode.bar,
      title: Text(
        'My Scripts',
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
            color: isDarkMode ? darkMode.textColor : lightMode.textColor,
            size: 30,
          ),
        )
      ],
      centerTitle: true,
    );
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
                ), /*
                MaterialButton(
                  color: Colors.white,
                  shape: CircleBorder(),
                  onPressed: () {},
                  child: Icon(
                    Icons.favorite_outline_rounded,
                    color: bars,
                    size: 20,
                  ),
                )*/
              ],
            ),
          ),
          Container(
            margin: EdgeInsets.fromLTRB(10, 25, 10, 10),
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
                    Icons.arrow_forward_ios_rounded,
                    color: isDarkMode ? darkMode.button : lightMode.fond,
                    size: 30,
                  ),
                )
              ],
            ),
          ),
          Container(
            margin: EdgeInsets.fromLTRB(100, 10, 10, 10),
            child: IconButton(
              onPressed: null,
              icon: Icon(
                Icons.add_circle_outline,
                color: isDarkMode ? darkMode.button : lightMode.fond,
                size: 30,
              ),
            ),
          )
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

class AddScript extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Center(child: Text("AddScript"));
  }
}

class MyProfile extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Center(child: Text("profile"));
  }
}
