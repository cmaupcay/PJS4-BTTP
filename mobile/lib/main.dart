// ignore_for_file: prefer_const_constructors, avoid_unnecessary_containers

import 'globale_variable.dart';
import 'package:flutter/material.dart';
import 'welcome_page.dart';
import 'package:adaptive_theme/adaptive_theme.dart';

/*
Map<int, Color> bleu1 = {
  50: Color.fromRGBO(0, 168, 232, .1),
  100: Color.fromRGBO(0, 168, 232, .2),
  200: Color.fromRGBO(0, 168, 232, .3),
  300: Color.fromRGBO(0, 168, 232, .4),
  400: Color.fromRGBO(0, 168, 232, .5),
  500: Color.fromRGBO(0, 168, 232, .6),
  600: Color.fromRGBO(0, 168, 232, .7),
  700: Color.fromRGBO(0, 168, 232, .8),
  800: Color.fromRGBO(0, 168, 232, .9),
  900: Color.fromRGBO(0, 168, 232, 1),
};
Map<int, Color> bleu2 = {
  50: Color.fromRGBO(0, 126, 167, .1),
  100: Color.fromRGBO(0, 126, 167, .2),
  200: Color.fromRGBO(0, 126, 167, .3),
  300: Color.fromRGBO(0, 126, 167, .4),
  400: Color.fromRGBO(0, 126, 167, .5),
  500: Color.fromRGBO(0, 126, 167, .6),
  600: Color.fromRGBO(0, 126, 167, .7),
  700: Color.fromRGBO(0, 126, 167, .8),
  800: Color.fromRGBO(0, 126, 167, .9),
  900: Color.fromRGBO(0, 126, 167, 1),
};

Map<int, Color> bleu3 = {
  50: Color.fromRGBO(0, 52, 89, .1),
  100: Color.fromRGBO(0, 52, 89, .2),
  200: Color.fromRGBO(0, 52, 89, .3),
  300: Color.fromRGBO(0, 52, 89, .4),
  400: Color.fromRGBO(0, 52, 89, .5),
  500: Color.fromRGBO(0, 52, 89, .6),
  600: Color.fromRGBO(0, 52, 89, .7),
  700: Color.fromRGBO(0, 52, 89, .8),
  800: Color.fromRGBO(0, 52, 89, .9),
  900: Color.fromRGBO(0, 52, 89, 1),
};

Map<int, Color> blanc = {
  50: Color.fromRGBO(255, 255, 255, .1),
  100: Color.fromRGBO(255, 255, 255, .2),
  200: Color.fromRGBO(255, 255, 255, .3),
  300: Color.fromRGBO(255, 255, 255, .4),
  400: Color.fromRGBO(255, 255, 255, .5),
  500: Color.fromRGBO(255, 255, 255, .6),
  600: Color.fromRGBO(255, 255, 255, .7),
  700: Color.fromRGBO(255, 255, 255, .8),
  800: Color.fromRGBO(255, 255, 255, .9),
  900: Color.fromRGBO(255, 255, 255, 1),
};

Map<int, Color> bleuNuit = {
  50: Color.fromRGBO(0, 23, 31, .1),
  100: Color.fromRGBO(0, 23, 31, .2),
  200: Color.fromRGBO(0, 23, 31, .3),
  300: Color.fromRGBO(0, 23, 31, .4),
  400: Color.fromRGBO(0, 23, 31, .5),
  500: Color.fromRGBO(0, 23, 31, .6),
  600: Color.fromRGBO(0, 23, 31, .7),
  700: Color.fromRGBO(0, 23, 31, .8),
  800: Color.fromRGBO(0, 23, 31, .9),
  900: Color.fromRGBO(0, 23, 31, 1),
};

Map<int, Color> vertFluo = {
  50: Color.fromRGBO(35, 235, 209, .1),
  100: Color.fromRGBO(35, 235, 209, .2),
  200: Color.fromRGBO(35, 235, 209, .3),
  300: Color.fromRGBO(35, 235, 209, .4),
  400: Color.fromRGBO(35, 235, 209, .5),
  500: Color.fromRGBO(35, 235, 209, .6),
  600: Color.fromRGBO(35, 235, 209, .7),
  700: Color.fromRGBO(35, 235, 209, .8),
  800: Color.fromRGBO(35, 235, 209, .9),
  900: Color.fromRGBO(35, 235, 209, 1),
};

Map<int, Color> gris = {
  50: Color.fromRGBO(58, 61, 75, .1),
  100: Color.fromRGBO(58, 61, 75, .2),
  200: Color.fromRGBO(58, 61, 75, .3),
  300: Color.fromRGBO(58, 61, 75, .4),
  400: Color.fromRGBO(58, 61, 75, .5),
  500: Color.fromRGBO(58, 61, 75, .6),
  600: Color.fromRGBO(58, 61, 75, .7),
  700: Color.fromRGBO(58, 61, 75, .8),
  800: Color.fromRGBO(58, 61, 75, .9),
  900: Color.fromRGBO(58, 61, 75, 1),
};

Map<int, Color> noir = {
  50: Color.fromRGBO(58, 61, 75, .1),
  100: Color.fromRGBO(58, 61, 75, .2),
  200: Color.fromRGBO(58, 61, 75, .3),
  300: Color.fromRGBO(58, 61, 75, .4),
  400: Color.fromRGBO(58, 61, 75, .5),
  500: Color.fromRGBO(58, 61, 75, .6),
  600: Color.fromRGBO(58, 61, 75, .7),
  700: Color.fromRGBO(58, 61, 75, .8),
  800: Color.fromRGBO(58, 61, 75, .9),
  900: Color.fromRGBO(58, 61, 75, 1),
};

MaterialColor customblanc = MaterialColor(
  0xFFFFFFF,
  const <int, Color>{
    50: Color.fromRGBO(255, 255, 255, .1),
    100: Color.fromRGBO(255, 255, 255, .2),
    200: Color.fromRGBO(255, 255, 255, .3),
    300: Color.fromRGBO(255, 255, 255, .4),
    400: Color.fromRGBO(255, 255, 255, .5),
    500: Color.fromRGBO(255, 255, 255, .6),
    600: Color.fromRGBO(255, 255, 255, .7),
    700: Color.fromRGBO(255, 255, 255, .8),
    800: Color.fromRGBO(255, 255, 255, .9),
    900: Color.fromRGBO(255, 255, 255, 1),
  },
);
MaterialColor custombleu1 = MaterialColor(
  0xFF00A8E8,
  const <int, Color>{
    50: Color.fromRGBO(0, 168, 232, .1),
    100: Color.fromRGBO(0, 168, 232, .2),
    200: Color.fromRGBO(0, 168, 232, .3),
    300: Color.fromRGBO(0, 168, 232, .4),
    400: Color.fromRGBO(0, 168, 232, .5),
    500: Color.fromRGBO(0, 168, 232, .6),
    600: Color.fromRGBO(0, 168, 232, .7),
    700: Color.fromRGBO(0, 168, 232, .8),
    800: Color.fromRGBO(0, 168, 232, .9),
    900: Color.fromRGBO(0, 168, 232, 1),
  },
);
MaterialColor custombleu2 = MaterialColor(
  0xFF007EA7,
  const <int, Color>{
    50: Color.fromRGBO(0, 126, 167, .1),
    100: Color.fromRGBO(0, 126, 167, .2),
    200: Color.fromRGBO(0, 126, 167, .3),
    300: Color.fromRGBO(0, 126, 167, .4),
    400: Color.fromRGBO(0, 126, 167, .5),
    500: Color.fromRGBO(0, 126, 167, .6),
    600: Color.fromRGBO(0, 126, 167, .7),
    700: Color.fromRGBO(0, 126, 167, .8),
    800: Color.fromRGBO(0, 126, 167, .9),
    900: Color.fromRGBO(0, 126, 167, 1),
  },
);
MaterialColor custombleu3 = MaterialColor(
  0xFF003459,
  const <int, Color>{
    50: Color.fromRGBO(0, 52, 89, .1),
    100: Color.fromRGBO(0, 52, 89, .2),
    200: Color.fromRGBO(0, 52, 89, .3),
    300: Color.fromRGBO(0, 52, 89, .4),
    400: Color.fromRGBO(0, 52, 89, .5),
    500: Color.fromRGBO(0, 52, 89, .6),
    600: Color.fromRGBO(0, 52, 89, .7),
    700: Color.fromRGBO(0, 52, 89, .8),
    800: Color.fromRGBO(0, 52, 89, .9),
    900: Color.fromRGBO(0, 52, 89, 1),
  },
);
MaterialColor custombleuNuit = MaterialColor(
  0xFF00171F,
  const <int, Color>{
    50: Color.fromRGBO(0, 23, 31, .1),
    100: Color.fromRGBO(0, 23, 31, .2),
    200: Color.fromRGBO(0, 23, 31, .3),
    300: Color.fromRGBO(0, 23, 31, .4),
    400: Color.fromRGBO(0, 23, 31, .5),
    500: Color.fromRGBO(0, 23, 31, .6),
    600: Color.fromRGBO(0, 23, 31, .7),
    700: Color.fromRGBO(0, 23, 31, .8),
    800: Color.fromRGBO(0, 23, 31, .9),
    900: Color.fromRGBO(0, 23, 31, 1),
  },
);
MaterialColor customvertFluo = MaterialColor(
  0xFF23ebd1,
  const <int, Color>{
    100: Color.fromRGBO(35, 235, 209, .2),
    200: Color.fromRGBO(35, 235, 209, .3),
    300: Color.fromRGBO(35, 235, 209, .4),
    400: Color.fromRGBO(35, 235, 209, .5),
    500: Color.fromRGBO(35, 235, 209, .6),
    600: Color.fromRGBO(35, 235, 209, .7),
    700: Color.fromRGBO(35, 235, 209, .8),
    800: Color.fromRGBO(35, 235, 209, .9),
    900: Color.fromRGBO(35, 235, 209, 1),
  },
);
MaterialColor customgris = MaterialColor(
  0xFF3a3d4b,
  const <int, Color>{
    50: Color.fromRGBO(58, 61, 75, .1),
    100: Color.fromRGBO(58, 61, 75, .2),
    200: Color.fromRGBO(58, 61, 75, .3),
    300: Color.fromRGBO(58, 61, 75, .4),
    400: Color.fromRGBO(58, 61, 75, .5),
    500: Color.fromRGBO(58, 61, 75, .6),
    600: Color.fromRGBO(58, 61, 75, .7),
    700: Color.fromRGBO(58, 61, 75, .8),
    800: Color.fromRGBO(58, 61, 75, .9),
    900: Color.fromRGBO(58, 61, 75, 1),
  },
);
MaterialColor customnoir = MaterialColor(
  0xFF3a3d4b,
  const <int, Color>{
    50: Color.fromRGBO(58, 61, 75, .1),
    100: Color.fromRGBO(58, 61, 75, .2),
    200: Color.fromRGBO(58, 61, 75, .3),
    300: Color.fromRGBO(58, 61, 75, .4),
    400: Color.fromRGBO(58, 61, 75, .5),
    500: Color.fromRGBO(58, 61, 75, .6),
    600: Color.fromRGBO(58, 61, 75, .7),
    700: Color.fromRGBO(58, 61, 75, .8),
    800: Color.fromRGBO(58, 61, 75, .9),
    900: Color.fromRGBO(58, 61, 75, 1),
  },
); */
void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    /*return AdaptiveTheme(
      light: ThemeData(
        brightness: Brightness.light,
        primarySwatch: customblanc,
        primaryColor: customblanc,
        backgroundColor: custombleu1,
        bottomAppBarColor: custombleu3,
        cardColor: custombleu2,
        focusColor: custombleuNuit,
      ),
      dark: ThemeData(
        brightness: Brightness.dark,
        primaryColor: customgris,
        primarySwatch: customgris,
        backgroundColor: customnoir,
        bottomAppBarColor: customgris,
        cardColor: customvertFluo,
        focusColor: customblanc,
      ),
      initial: AdaptiveThemeMode.light,
      builder: (theme, darkTheme) => MaterialApp(
        debugShowCheckedModeBanner: false,
        title: 'BTTP',
        theme: theme,
        darkTheme: darkTheme,
        home: WelcomePage(),
      ),
    ); */
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'BTTP',
      home: WelcomePage(),
    );
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
  }*/
