Könyvesbolt menedzsment rendszer

A fentebb látható kód egy könyvesbolt menedzsment rendszer felépítését mutatja, ami tartalmazza az alkalmazottakat, a könyveket és a leadott rendeléseket. Az alkalmazásban le tudjuk kérdezni az elöző három adatait, meg tudjuk változtatni azokat, valamint törlöni tudjuk őket az adatbázisból és újak adait is meg tudjuk adni. Az információk a következők:
Könyvek:
-azonosító
-cím
-szerző
-darabszám
-ár

Rendelés:
-azonosító
-könyv azonosítója
-rendelő neve, címe
-megrendelt könyv darabszáma
-rendelés ára

Alkalmazottak:
-azonosító
-név
-cím
-fizetés
-pozíció


A munkatársak, könyvek és a rendelések adatait (pl: egy könyvből hány darab van) MYSQL-ben van eltárolva, így a program használatához ez is elengedhetetlen.

A MYSQL telepítése után a main.cpp-ben meg kell adni a MYSQL-hez tartozó jelszavunkat, valamint létre kell hozni a bookshop adatbázist és azon belül a book, az orders és az employees táblákat.