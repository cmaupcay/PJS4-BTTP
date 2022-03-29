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

/*class HomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    SystemChrome.setPreferredOrientations(
        [DeviceOrientation.portraitUp, DeviceOrientation.portraitDown]);
    return Scaffold(
      backgroundColor: Color(0xFF000010),
      bottomNavigationBar: BottomNavBarSection(),
    );
  }
}*/

class HomePage extends StatefulWidget {
  @override
  State<StatefulWidget> createState() {
    return HomePageState();
  }
}

class HomePageState extends State<HomePage> {
  bool darkmode = false;
  dynamic savedThemeMode;
  int selectedIndex = 0;
  Widget _myScripts = MyScripts();
  Widget _addScript = AddScript();
  Widget _myProfile = MyProfile();
  Widget _myScriptsAppBar = MyScriptsAppBar();
  Widget _addScriptAppBar = AddScriptAppBar();
  Widget _myProfileAppBar = MyProfileAppBar();
  void initState() {
    super.initState();
    getCurrentTheme();
  }

  Future getCurrentTheme() async {
    savedThemeMode = await AdaptiveTheme.getThemeMode();
    if (savedThemeMode.toString() == 'AdaptiveThemeMode.dark') {
      setState(() {
        darkmode = true;
      });
    } else {
      setState(() {
        darkmode = false;
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: MyProfileAppBar(),
      body: this.getBody(),
      bottomNavigationBar: BottomNavigationBar(
        type: BottomNavigationBarType.fixed,
        currentIndex: this.selectedIndex,
        backgroundColor: Theme.of(context).primaryColor,
        selectedItemColor: Theme.of(context).bottomAppBarColor,
        selectedFontSize: 16,
        unselectedItemColor: Colors.grey[400],
        items: [
          BottomNavigationBarItem(
            icon: Icon(
              Icons.search,
//              color: Colors.white,
            ),
            label: 'My Scripts',
          ),
          BottomNavigationBarItem(
            icon: Icon(
              Icons.shopping_cart_outlined,
//              color: Colors.white,
            ),
            label: 'Market place',
          ),
          BottomNavigationBarItem(
            icon: Icon(
              Icons.account_circle_outlined,
//              color: Colors.white,
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

class MyScriptsAppBar extends StatelessWidget implements PreferredSizeWidget {
  @override
  Size get preferredSize => new Size.fromHeight(50);
  @override
  Widget build(BuildContext context) {
    return AppBar(
      backgroundColor: Theme.of(context).primaryColor,
      title: Text(
        'My Scripts',
        style: GoogleFonts.poppins(
          color: Theme.of(context).bottomAppBarColor,
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
            color: Theme.of(context).bottomAppBarColor,
            size: 20,
          ),
        )
      ],
      centerTitle: true,
    );
  }
}

class AddScriptAppBar extends StatelessWidget implements PreferredSizeWidget {
  @override
  Size get preferredSize => new Size.fromHeight(50);
  @override
  Widget build(BuildContext context) {
    return AppBar(
      backgroundColor: Theme.of(context).primaryColor,
      title: Text(
        'Add Script',
        style: GoogleFonts.poppins(
          color: Theme.of(context).bottomAppBarColor,
          fontSize: 22,
          fontWeight: FontWeight.w800,
        ),
      ),
      actions: [
        IconButton(
          onPressed: null,
          icon: Icon(
            Icons.settings,
            color: Theme.of(context).bottomAppBarColor,
            size: 20,
          ),
        )
      ],
      centerTitle: true,
    );
  }
}

class MyProfileAppBar extends StatelessWidget implements PreferredSizeWidget {
  @override
  Size get preferredSize => new Size.fromHeight(50);
  @override
  Widget build(BuildContext context) {
    return AppBar(
      automaticallyImplyLeading: false,
      backgroundColor: Theme.of(context).primaryColor,
      title: Text(
        'My Profile',
        style: GoogleFonts.poppins(
          color: Theme.of(context).bottomAppBarColor,
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
            color: Theme.of(context).bottomAppBarColor,
            size: 20,
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
      backgroundColor: Theme.of(context).primaryColor,
      title: Text(
        'My Scripts',
        style: GoogleFonts.poppins(
          color: Theme.of(context).bottomAppBarColor,
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
            color: Theme.of(context).bottomAppBarColor,
            size: 20,
          ),
        )
      ],
    );
    return Scaffold(
      backgroundColor: Theme.of(context).backgroundColor,
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
      'description': "lalalaalalalal",
      'variables': true,
    },
    {
      'title': 'Script2',
      'description': "lalzeczczcl",
      'variables': false,
    },
    {
      'title': 'Script3',
      'description': "lacedcdcdcddl",
      'variables': false,
    },
    {
      'title': 'Script4',
      'description': "lyj,hkygfvdl",
      'variables': true,
    }
  ];
  @override
  Widget build(BuildContext context) {
    return Container(
      padding: EdgeInsets.all(10),
      color: Theme.of(context).backgroundColor,
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
        color: Theme.of(context).primaryColor,
        borderRadius: BorderRadius.all(Radius.circular(18)),
        boxShadow: [
          BoxShadow(
            color: Colors.grey.shade200,
            spreadRadius: 4,
            blurRadius: 6,
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
                    color: Theme.of(context).focusColor,
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
                    color: Theme.of(context).cardColor,
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
                color: Theme.of(context).cardColor,
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
