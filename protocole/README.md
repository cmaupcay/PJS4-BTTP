# BTTP - _Protocole_

## Démarrer
Pour générer les scripts de compilation de la __librairie BTTP__, suivez la procédure suivante :

```sh
    mkdir cmake
    cd cmake
    cmake ..
```

### Démonstration
Une __démonstration fonctionnelle__ du protocole est disponible pour exposer les fonctions principales du protocole. Elle peut être compilée et exécutée grâce aux commandes :
```sh
    cmake .. -DBTTP_DEMO=ON
    ../bin/bttp-demo
```
> Le [code source](demo/src/demo.cpp) peut également vous servir d'exemple d'implémentation dans vos projets.

### Tests
Pour vérifier automatiquement l'état de fonctionnement du protocole, utilisez les __tests unitaires__ grâce aux commandes suivantes :
```sh
    cmake .. -DBTTP_TEST=ON
    ../bin/bttp-test
```

## Dépendances
- __[OpenPGP](https://github.com/calccrypto/OpenPGP) :__ fonctions de cryptographie.
- __[segvcatch](https://github.com/Plaristote/segvcatch) :__ prévenir des erreurs de type _Segmentation fault_.

### Tests
- __[googletest](https://github.com/google/googletest) :__ tests unitaires.