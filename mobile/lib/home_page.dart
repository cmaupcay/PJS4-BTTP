// ignore_for_file: prefer_const_constructors, prefer_const_literals_to_create_immutables, use_key_in_widget_constructors, prefer_const_constructors_in_immutables, unnecessary_this, prefer_final_fields, unnecessary_new

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
      appBar: MyProfileAppBar(),
      body: this.getBody(),
      bottomNavigationBar: BottomNavigationBar(
        type: BottomNavigationBarType.fixed,
        currentIndex: this.selectedIndex,
        backgroundColor: bars,
        selectedItemColor: Colors.white,
        selectedFontSize: 16,
        unselectedItemColor: Colors.grey[400],
        items: [
          BottomNavigationBarItem(
            icon: Icon(
              Icons.search,
              color: Colors.white,
            ),
            label: 'My Scripts',
          ),
          BottomNavigationBarItem(
            icon: Icon(
              Icons.add,
              color: Colors.white,
            ),
            label: 'Add Script',
          ),
          BottomNavigationBarItem(
            icon: Icon(
              Icons.account_circle_outlined,
              color: Colors.white,
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
      backgroundColor: bars,
      title: Text(
        'My Scripts',
        style: GoogleFonts.poppins(
          color: Colors.white,
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
            color: Colors.white,
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
      backgroundColor: bars,
      title: Text(
        'Add Script',
        style: GoogleFonts.poppins(
          color: Colors.white,
          fontSize: 22,
          fontWeight: FontWeight.w800,
        ),
      ),
      actions: [
        IconButton(
          onPressed: null,
          icon: Icon(
            Icons.settings,
            color: Colors.white,
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
      backgroundColor: bars,
      title: Text(
        'My Profile',
        style: GoogleFonts.poppins(
          color: Colors.white,
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
            color: Colors.white,
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
      backgroundColor: bars,
      title: Text(
        'My Scripts',
        style: GoogleFonts.poppins(
          color: Colors.white,
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
            color: Colors.white,
            size: 20,
          ),
        )
      ],
    );
    return Center(
      child: Text("MyScripts"),
    );
  }
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
