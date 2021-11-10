# 2 Užduotis

### Sąlyga

10 variantas

> Įvesti sveiką skaičių N. Įvesti N sveikų skaičių. Pertvarkyti juos taip, kad pradžioje būtų visi neigiami elementai, o po jų neneigiami (pradinė neigiamų ir neneigiamų tvarka turi būti išsaugota), ir išvesti.

### Refleksija

Iš pirmos užduoties ištraukiau validavimo algoritmą, jį patobulinau ir padariau atskirą biblioteką (static library), kurią su Makefile pagalba įsirašiau į savo kompiuterį. Pagrindinius šios bibliotekos failus taip pat įdėjau prie šios užduoties ([validation direktorija](./validation)), o visą validavimo projektą galima rasti [čia](https://github.com/BenasB/c-input-validation). Sunkiausia dalis ko gero buvo atrasti būdą, kaip grąžinti array iš funkcijos. Sakyčiau, jog implementuoti patį užduoties sprendimo algoritmą truko greit - apie 1-2 val. su testavimu, tačiau daug laiko užtrukau kol išsiaiškinau, kaip sudaromos C bibliotekos (apie 10 valandų).

Patobulinimui: būtų galima parašyti atskirą `validation` funkciją, kuri priimtų tik natūraliuosius skaičius (nereiktų tikrinti imant `arraySize`). Dar galbūt būtų galima sukurti `struct`, kuris laikytų array ir jo size kartu vienoje vietoje (nereiktų į funkcijas paduoti atskirai).

### Kompiliavimas

Neįsirašant `c-input-validation` bibliotekos į savo sistemą, galima programą sukompiliuoti tokiu būdu: `gcc main-local.c ./validation/getInteger.c -o output -std=c99`
