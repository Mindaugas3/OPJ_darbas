v1.0 - Mindaugas Krupavičius

Versijos funkcionalumas:
 - Optimizuota programos sparta, naudojant std::stable_partition rūšiavimui ir buferius failų skaitymui ir rašymui.
 
Kompiliuoti reikia su -fpermissive parametru.

Vykdant programą pirmą kartą reikia sugeneruoti failus, todėl reikia konsolėje rinktis T. Po to jų galima ir negeneruoti, taigi N.

Versijų sąrašas:
- 0.1: Versijoje yra main.cpp - su masyvais, ir vekt.cpp - su vektoriais(neveikia). Programa vedama ranka.
- 0.1.1: Masyvai pakeisti iš statinių į dinaminius, naudojant raktažodį **new**.
- 0.2: Versijoje programa geba dirbti tiek su failais, tiek įvedant ranka. Gražiai išrikiuojami rezultatai ekrane.
- 0.3: Atlikta programos refaktorizacija: Vietoj dvimačių masyvų ir vektorių iš vektorių naudojamas struktūros vektorius. Parašyti antraščių failai. Taip pat programa tikrina, ar įvestas bent vienas namų darbas, ir ar pažymiai priklauso intervalui nuo 1 iki 10.
- 0.4: Sukurtas failų generatorius, iš kurio generuoti failai gali būti naudojami programos išbandymui. Taipogi išvestyje studentai rūšiuojami į "linksmus" (vidurkis > 5) ir "liūdnus" (vidurkis < 5). Ties kiekviena pakopa matuojamas laikas.
- 0.5: Išbandoma ir palyginama programos sparta priklausomai nuo skirtingų STL konteinerių tipo: vektorius, dekas ar sąrašas. Naudojami šablonai **template** leidžia į funkcijas kreiptis nurodant STL konteinerių tipo parametrą.
- 0.5.1: Palyginamas sudedamas į gražiai suformatuotą lentelę, ir naudojami lietuviški rašmenys išvestyje.
- 1.0: Optimizuojama programos sparta su std::stable_partition ir failų skaitymo/rašymo buferiais. Apibendrinamas versijų sąrašas. Įkeltas makefile.win
