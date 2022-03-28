// ignore_for_file: prefer_const_constructors, avoid_unnecessary_containers

import 'globale_variable.dart';
import 'package:flutter/material.dart';
import 'welcome_page.dart';
import 'package:adaptive_theme/adaptive_theme.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    /*
    return AdaptiveTheme(
      light: ThemeData(
        brightness: Brightness.light,
        primarySwatch: Colors.blue,
      ),
      dark: ThemeData(
        brightness: Brightness.dark,
        primarySwatch: Colors.orange,
      ),
      initial: AdaptiveThemeMode.light,
      builder: (theme, darkTheme) => MaterialApp(
        debugShowCheckedModeBanner: false,
        title: 'BTTP',
        theme: theme,
        darkTheme: darkTheme,
        home: WelcomePage(),
      ),
    );*/
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'BTTP',
      //theme: lightTheme,
      //darkTheme: darkTheme,
      //themeMode: _themeManager.themeMode,
      home: WelcomePage(),
    );
  }

  @override
  State<StatefulWidget> createState() {
    // TODO: implement createState
    throw UnimplementedError();
  }
}

/*class ConnectPage extends StatelessWidget {
  const ConnectPage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    SystemChrome.setPreferredOrientations(
        [DeviceOrientation.portraitUp, DeviceOrientation.portraitDown]);
    return Scaffold(
      appBar: AppBar(
        title: Text('BTTP'),
      ),
      body: Center(
          child: DelayedAnimation(
        delay: 1000,
        child: FlutterLogo(
          size: 200,
        ),
      )),
    );
  }
}
*/
/*
class HomePage extends StatelessWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    SystemChrome.setPreferredOrientations(
        [DeviceOrientation.portraitUp, DeviceOrientation.portraitDown]);
    return Container(
        decoration: BoxDecoration(
            image: DecorationImage(
          fit: BoxFit.cover,
          image: AssetImage(
            "images/logo.jpg",
          ),
        )),
        child: Scaffold(
            backgroundColor: Colors.transparent,
            appBar: AppBar(
              backgroundColor: Colors.blueGrey,
              title: const Text("BTTP"),
            ),
            body: Column(
              children: [
                Container(
                  height: 250,
                ),
                Container(
                    child: ElevatedButton(
                  style: ButtonStyle(
                      backgroundColor:
                          MaterialStateProperty.all(Colors.blueGrey)),
                  child: const Text("BTTP"),
                  onPressed: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(builder: (context) => PageScript()),
                    );
                  },
                )),
                Container(
                  height: 50,
                ),
              ],
            )));
  }
}

class PageScript extends StatelessWidget {
  const PageScript({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    SystemChrome.setPreferredOrientations(
        [DeviceOrientation.portraitUp, DeviceOrientation.portraitDown]);
    return Scaffold(
      appBar: MyAppBarTop(),
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
      'description': 'blabla',
      'pp': 'images/logo.jpg',
    },
    {
      'title': 'Script2',
      'description': 'blabla',
      'pp': 'images/logo.jpg',
    },
    {
      'title': 'Script3',
      'description': 'blabla',
      'pp': 'images/logo.jpg',
    },
    {
      'title': 'Script4',
      'description': 'blabla',
      'pp': 'images/logo.jpg',
    },
    {
      'title': 'Script5',
      'description': 'blabla',
      'pp': 'images/logo.jpg',
    },
    {
      'title': 'Script6',
      'description': 'blabla',
      'pp': 'images/logo.jpg',
    },
  ];
  @override
  Widget build(BuildContext context) {
    return Container(
      padding: EdgeInsets.all(10),
      color: fond,
      child: Column(
        children: [
          Column(
            children: scriptList.map((script) {
              return ScriptCard(script);
            }).toList(),
          ),
        ],
      ),
    );
  }
}

class ScriptCard extends StatelessWidget {
  final Map scriptData;
  bool _hasBeenPressed = false;
  ScriptCard(this.scriptData);
  @override
  Widget build(BuildContext context) {
    return Container(
      margin: EdgeInsets.all(10),
      height: 230,
      width: double.infinity,
      decoration: BoxDecoration(
        color: cases,
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
            height: 135,
            decoration: BoxDecoration(
              borderRadius: BorderRadius.only(
                topLeft: Radius.circular(18),
                topRight: Radius.circular(18),
              ),
              image: DecorationImage(
                image: AssetImage(
                  scriptData['pp'],
                ),
                fit: BoxFit.cover,
              ),
            ),
          ),
          Container(
            margin: EdgeInsets.fromLTRB(10, 10, 10, 10),
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [
                Text(
                  scriptData['title'],
                  style: GoogleFonts.nunito(
                    fontSize: 18,
                    fontWeight: FontWeight.w800,
                  ),
                ),
              ],
            ),
          ),
          Container(
            margin: EdgeInsets.symmetric(horizontal: 10),
            child: Row(
              // ignore: prefer_const_literals_to_create_immutables
              children: [
                IconButton(
                  icon: Icon(
                    Icons.favorite_border_outlined,
                    color: _hasBeenPressed ? Colors.grey[900] : Colors.red,
                    size: 20,
                  ),
                  onPressed: () => {
                    setState(() {
                      _hasBeenPressed = !_hasBeenPressed;
                    })
                  },
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }

  setState(Null Function() param0) {}
}

class MyAppBarTop extends StatelessWidget implements PreferredSizeWidget {
  const MyAppBarTop({Key? key}) : super(key: key);

  @override
  Size get preferredSize => Size.fromHeight(50);
  @override
  Widget build(BuildContext context) {
    return AppBar(
      leading: IconButton(
        icon: Icon(
          Icons.account_circle,
          color: Colors.grey[800],
          size: 25,
        ),
        onPressed: null,
      ),
      title: Text(
        "Fil d'actualité",
        style: GoogleFonts.nunito(
          color: Colors.black,
          fontSize: 22,
          fontWeight: FontWeight.w800,
        ),
      ),
      actions: [
        IconButton(
          icon: Icon(
            Icons.chat_bubble_outline,
            color: Colors.grey[800],
            size: 25,
          ),
          onPressed: null,
        ),
        IconButton(
          icon: Icon(
            Icons.settings_outlined,
            color: Colors.grey[800],
            size: 25,
          ),
          onPressed: null,
        ),
      ],
      centerTitle: true,
      backgroundColor: bars,
    );
  }
}
*/