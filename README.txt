Versija v0.2.1 ~ Mindaugas Krupavičius, Objektinis programavimas:

1. Pridetas try-catch blokas ties išvedimu.
2. pridėta range(float F, int a, int b) funkcija, kuri tikrina ar a <= F <= b.
3. Pridėta RANGE(x) preprocesoriaus direktyva, kad nereikėtų visų kintamųjų vesti. Ji nukreipia į range(x, 0, 10) funkciją ir leidžia įvertinti ar tinkamai įvesti namų darbų ir egzamino rezultatai
4. Pridėtos etiketės ties skaitine įvestimi - jeigu neįvedamas skaičius kur reikia, arba įvedamas už intervalo RANGE(x) ribų, šokama prie etiketės ir skaičius vedamas iš naujo
5. Pridėta FILEINPUT preprocesoriaus direktyva lengvesniam debuginimui - (ne vartotojui) galima rinktis ar imti duomenis iš failo